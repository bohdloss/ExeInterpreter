#pragma once

#include <stdint.h>

class SectionEntry {
public:
    SectionEntry();
    virtual ~SectionEntry();
private:
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
};