#include "COFFSymbol.hpp"
#include <string>

COFFSymbol::COFFSymbol() {
}

COFFSymbol::~COFFSymbol() {
}

void COFFSymbol::parse(Buffer buffer, size_t symbol_table_ptr, uint32_t* index) {
    nSymbol symbol_struct = buffer.get<nSymbol>(symbol_table_ptr + (sizeof(nSymbol) * (*index)));
    memcpy(this->name, symbol_struct.name, 8);
    this->value = symbol_struct.value;
    this->section_number = symbol_struct.section_number;
    this->type = symbol_struct.type;
    this->cclass = symbol_struct.cclass;
    this->auxiliary_number = symbol_struct.auxiliary_number;
    
    *index += auxiliary_number;
}