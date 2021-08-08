#pragma once

#include <stdint.h>
#include <cstddef>
#include "COFFHeader.hpp"
#include "OptionalHeader.hpp"
#include "SectionEntry.hpp"
#include "Buffer.hpp"
#include "Defines.hpp"

class PortableExecutable {
public:
    PortableExecutable();
    virtual ~PortableExecutable();
    
    void parse(Buffer buffer);
    void relocate(void* address);
    
private:
    unsigned char* msdos_stub;
    char* signature;
    COFFHeader* coff_header;
    OptionalHeader* optional_header;
    SectionEntry* section_table;
};