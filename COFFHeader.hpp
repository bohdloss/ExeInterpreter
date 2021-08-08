#pragma once

#include "COFFSymbol.hpp"
#include "Buffer.hpp"

class COFFHeader {
public:
#pragma pack(push, 1)
    typedef struct {
        uint16_t machine;
        uint16_t number_of_sections;
        uint32_t time_stamp;
        uint32_t symbol_table_ptr;
        uint32_t symbol_amount;
        uint16_t optional_header_size;
        uint16_t characteristics;
    } nCOFF;
#pragma pack(pop)
    
    COFFHeader();
    virtual ~COFFHeader();
    
    void parse(Buffer buffer, size_t header_offset);

    uint16_t getCharacteristics() const {
        return characteristics;
    }

    uint16_t getMachine() const {
        return machine;
    }

    uint16_t getNumber_of_sections() const {
        return number_of_sections;
    }

    uint16_t getOptional_header_size() const {
        return optional_header_size;
    }

    uint32_t getSymbol_amount() const {
        return symbol_amount;
    }

    COFFSymbol* getSymbol_table_ptr() const {
        return symbol_table_ptr;
    }

    uint32_t getTime_stamp() const {
        return time_stamp;
    }
    
    char** getString_table_ptr() const {
        return string_table_ptr;
    }

    uint32_t getString_amount() const {
        return string_amount;
    }
    
private: 
    uint16_t machine;
    uint16_t number_of_sections;
    uint32_t time_stamp;
    COFFSymbol* symbol_table_ptr;
    uint32_t symbol_amount;
    uint16_t optional_header_size;
    uint16_t characteristics;
    char** string_table_ptr;
    uint32_t string_amount;
};