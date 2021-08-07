#pragma once

#include "COFFSymbol.hpp"
#include "Buffer.hpp"

class COFFHeader {
public:
    COFFHeader();
    virtual ~COFFHeader();
    
    void parse(Buffer buffer, size_t header_offset);
private:
    typedef struct {
        uint16_t machine;
        uint16_t number_of_sections;
        uint32_t time_stamp;
        uint32_t symbol_table_ptr;
        uint32_t symbol_amount;
        uint16_t optional_header_size;
        uint16_t characteristics;
    } nCOFF;
    
    uint16_t machine;
    uint16_t number_of_sections;
    uint32_t time_stamp;
    COFFSymbol* symbol_table_ptr;
    uint32_t symbol_amount;
    uint16_t optional_header_size;
    uint16_t characteristics;
};