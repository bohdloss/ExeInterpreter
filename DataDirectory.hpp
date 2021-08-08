#pragma once

#include <stdint.h>

class DataDirectory {
public:
#pragma pack(push, 1)
    typedef struct {
        uint32_t virtual_address;
        uint32_t size;
    } nDataDirectory;
#pragma pack(pop)
    
    DataDirectory();
    virtual ~DataDirectory();
private:
    uint32_t virtual_address;
    uint32_t size;

    uint32_t getSize() const {
        return size;
    }

    uint32_t getVirtualAddress() const {
        return virtual_address;
    }

};