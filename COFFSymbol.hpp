#pragma once

#include <stdint.h>
#include "Buffer.hpp"

class COFFSymbol {
public:
#pragma pack(push, 1)
    typedef struct {
        union {
            char name[8];
            struct {
                uint32_t zero;
                uint32_t offset;
            };
        };
        uint32_t value;
        int16_t section_number;
        uint16_t type;
        uint8_t cclass;
        uint8_t auxiliary_number;
    } nSymbol;
#pragma pack(pop)
    
    COFFSymbol();
    virtual ~COFFSymbol();
    
    void parse(Buffer buffer, size_t symbol_table_ptr, uint32_t* index);

    uint8_t getAuxiliary_number() const {
        return auxiliary_number;
    }

    uint8_t getCclass() const {
        return cclass;
    }

    int16_t getSection_number() const {
        return section_number;
    }

    uint16_t getType() const {
        return type;
    }

    uint32_t getValue() const {
        return value;
    }

private:
    union {
        char name[8];
        struct {
            uint32_t zero;
            uint32_t offset;
        };
    };
    uint32_t value;
    int16_t section_number;
    uint16_t type;
    uint8_t cclass;
    uint8_t auxiliary_number;
};