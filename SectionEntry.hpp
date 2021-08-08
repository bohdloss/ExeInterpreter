#pragma once

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

    uint32_t GetCharacteristics() const {
        return characteristics;
    }

    uint32_t GetLine_number_ptr() const {
        return line_number_ptr;
    }
    char* GetName() const {
        return name;
    }

    uint16_t GetNumber_of_line_number() const {
        return number_of_line_number;
    }

    uint16_t GetNumber_of_relocation() const {
        return number_of_relocation;
    }

    uint32_t GetRaw_data_ptr() const {
        return raw_data_ptr;
    }

    uint32_t GetRaw_data_size() const {
        return raw_data_size;
    }

    uint32_t GetRelocation_ptr() const {
        return relocation_ptr;
    }

    uint32_t GetVirtual_address() const {
        return virtual_address;
    }

    uint32_t GetVirtual_size() const {
        return virtual_size;
    }

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