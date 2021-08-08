#pragma once

#include "COFFSymbol.hpp"
#include "Buffer.hpp"

class COFFSymbol;

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

    uint16_t getNumberOfSections() const {
        return number_of_sections;
    }

    uint16_t getOptionalHeaderSize() const {
        return optional_header_size;
    }

    uint32_t getSymbolAmount() const {
        return symbol_amount;
    }

    COFFSymbol* getSymbolTablePtr() const {
        return symbol_table_ptr;
    }

    uint32_t getTimestamp() const {
        return time_stamp;
    }
    
    char** getStringTablePtr() const {
        return string_table_ptr;
    }

    uint32_t getStringAmount() const {
        return string_amount;
    }
    
    void* getRawStringTablePtr() const {
        return raw_string_table_ptr;
    }
    
    char* getString(size_t offset) {
        return (char*) (raw_string_table_ptr + offset);
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
    void* raw_string_table_ptr;
};