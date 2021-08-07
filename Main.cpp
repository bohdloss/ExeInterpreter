#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdexcept>

#include "PortableExecutable.hpp"
#include "Buffer.hpp"

#define USAGE "Usage: ExeInterpreter <program_name>\n"

#define OP_OPEN1 "Opening file "
#define OP_OPEN2 " ...\n"
#define OP_OPEN_FAIL "Could not open file\n"

#define OP_MALLOC "Allocating memory...\n"
#define OP_MALLOC_FAIL "Memory allocation failed\n"

#define OP_READ "Reading file...\n"
#define OP_READ_FAIL "Could not read file\n"

#define OP_PARSE "Parsing executable...\n"
#define OP_PARSE_FAIL "Executable file failed to validate\n"

#define OP_RELOCATE "Relocating executable...\n"
#define OP_RELOCATE_FAIL "Could not relocate executable\n"

void usage(void) {
    printf(USAGE);
}

void printException(std::exception ex) {
    printf("Error: ");
    printf(ex.what());
    printf("\n");
}

int main(int argc, char** argv) {
    // Check arguments
    if(argc < 2) {
        usage();
        return 0;
    }
    
    // Find windows executable path
    
    // First find relative path
    char relative_path[PATH_MAX];
    relative_path[0] = 0;
    for(int i = 1; i < argc; i++) {
        strcat(relative_path, argv[i]);
        if(i != argc -1) {
            strcat(relative_path, " ");
        }
    }
    
    // Then find the absolute path
    char absolute_path[PATH_MAX];
    if(relative_path[0] == '/') {
        strcpy(absolute_path, relative_path);
    } else {
        char pwd[PATH_MAX];
        getcwd(pwd, sizeof(pwd));
        strcpy(absolute_path, pwd);
        strcat(absolute_path, "/");
        strcat(absolute_path, relative_path);
    }
    
    // Open as file
    printf(OP_OPEN1);
    printf(absolute_path);
    printf(OP_OPEN2);
    FILE* exe_file = fopen(absolute_path, "rb");
    if(!exe_file) {
        printf(OP_OPEN_FAIL);
        printf(absolute_path);
        printf("\n");
        usage();
        return 0;
    }
    
    // Read file
    fseek(exe_file, 0, SEEK_END);
    size_t file_size = ftell(exe_file);
    fseek(exe_file, 0, SEEK_SET);
    
    printf(OP_MALLOC);
    unsigned char* data = (unsigned char*) malloc(file_size);
    if(!data) {
        printf(OP_MALLOC_FAIL);
        return 1;
    }
    
    printf(OP_READ);
    size_t read_amount = fread(data, sizeof(unsigned char), file_size, exe_file);
    if(read_amount != file_size) {
        printf(OP_READ_FAIL);
        return 1;
    }
    
    // Parse the executable file
    printf(OP_MALLOC);
    PortableExecutable* executable = new PortableExecutable();
    if(!executable) {
        printf(OP_MALLOC_FAIL);
        return 1;
    }
    
    printf(OP_PARSE);
    try {
        executable->parse(Buffer(file_size, data));
    } catch(const std::exception ex) {
        printf(OP_PARSE_FAIL);
        printException(ex);
        return 1;
    }
    
    printf(OP_RELOCATE);
    try {
        executable->relocate(0);
    } catch(const std::exception ex) {
        printf(OP_RELOCATE_FAIL);
        printException(ex);
        return 1;
    }
    
    return 0;
}