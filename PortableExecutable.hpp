#pragma once

#include <stdint.h>
#include <cstddef>
#include "COFFHeader.hpp"
#include "OptionalHeader.hpp"
#include "SectionEntry.hpp"
#include "Buffer.hpp"

#define NO_MALLOC "Memory allocation failed\n"
#define NO_SIGNATURE "Executable file does not contain a valid signature\n"
#define NO_MAGIC "Executable file does not contain a valid magic number in its optional header\n"

class PortableExecutable {
public:
    PortableExecutable();
    virtual ~PortableExecutable();
    
    void parse(Buffer buffer);
    void relocate(void* address);
    
    unsigned char* getMsdosStub();
    char* getSignature();
    COFFHeader* getCoffHeader();
    OptionalHeader* getOptionalHeader();
    SectionEntry* getSectionTable();
    
private:
    unsigned char* msdos_stub;
    char* signature;
    COFFHeader* coff_header;
    OptionalHeader* optional_header;
    SectionEntry* section_table;
};