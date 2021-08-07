#pragma once

#include <stdint.h>

class COFFSymbol {
public:
    COFFSymbol();
    virtual ~COFFSymbol();
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