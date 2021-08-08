#include "COFFSymbol.hpp"
#include <string>

COFFSymbol::COFFSymbol() {
}

COFFSymbol::~COFFSymbol() {
}

void COFFSymbol::parse(Buffer buffer, size_t symbol_table_ptr, uint32_t* index, COFFHeader* coff_header) {
    nSymbol symbol_struct = buffer.get<nSymbol>(symbol_table_ptr + (sizeof(nSymbol) * (*index)));
    // Retrieve the name
    if(symbol_struct.zero == 0) {
        // The string is located in the string table
        uint32_t offset = symbol_struct.offset;
        char* string = coff_header->getString(offset);
        size_t string_len = strlen(string) + 1;
        
        // Copy it
        this->name = new char[string_len];
        memcpy(name, string, string_len);
    } else {
        // Is the string null terminated?
        char* string = &symbol_struct.name[0];
        bool null_term = string[7] == '\0';
        if(null_term) {
            size_t string_len = strlen(string) + 1;
            this->name = new char[string_len];
            memcpy(name, string, string_len);
        } else {
            this->name = new char[9];
            memcpy(name, string, 8);
            name[8] = '\0';
        }
    }
    this->value = symbol_struct.value;
    this->section_number = symbol_struct.section_number;
    this->type = symbol_struct.type;
    this->cclass = symbol_struct.cclass;
    this->auxiliary_number = symbol_struct.auxiliary_number;
    
    *index += auxiliary_number;
}