#pragma once

#include "Buffer.hpp"
#include "COFFHeader.hpp"
#include <stdint.h>

class SectionEntry {
public:
#pragma pack(push, 1)
    typedef struct {
        char name[0x8];
        uint32_t virtual_size;
        uint32_t virtual_address;
        uint32_t raw_data_size;
        uint32_t raw_data_ptr;
        uint32_t relocation_ptr;
        uint32_t line_number_ptr;
        uint16_t number_of_relocation;
        uint16_t number_of_line_number;
        uint32_t characteristics;
    } nSectionEntry;
#pragma pack(pop)
    
    SectionEntry();
    virtual ~SectionEntry();

    void parse(Buffer buffer, size_t offset, uint16_t* index, COFFHeader* coff_header);
    
    uint32_t getCharacteristics() const {
        return characteristics;
    }

    uint32_t getLineNumberPtr() const {
        return line_number_ptr;
    }
    char* getName() const {
        return name;
    }

    uint16_t getNumberOfLineNumbers() const {
        return number_of_line_number;
    }

    uint16_t getNumberOfRelocations() const {
        return number_of_relocation;
    }

    uint32_t getRawDataPtr() const {
        return raw_data_ptr;
    }

    uint32_t getRawDataSize() const {
        return raw_data_size;
    }

    uint32_t getRelocationPtr() const {
        return relocation_ptr;
    }

    uint32_t getVirtualAddress() const {
        return virtual_address;
    }

    uint32_t getVirtualSize() const {
        return virtual_size;
    }

private:
    char* name;
    uint32_t virtual_size;
    uint32_t virtual_address;
    uint32_t raw_data_size;
    uint32_t raw_data_ptr;
    uint32_t relocation_ptr;
    uint32_t line_number_ptr;
    uint16_t number_of_relocation;
    uint16_t number_of_line_number;
    uint32_t characteristics;
};