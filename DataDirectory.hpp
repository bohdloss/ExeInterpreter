#pragma once

#include <stdint.h>

class DataDirectory {
public:
    DataDirectory();
    virtual ~DataDirectory();
private:
    uint32_t virtual_address;
    uint32_t size;
};