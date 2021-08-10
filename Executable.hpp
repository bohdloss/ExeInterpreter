#pragma once

#include <stdint.h>
#include <cstddef>
#include "COFFHeader.hpp"
#include "OptionalHeader.hpp"
#include "SectionEntry.hpp"
#include "Buffer.hpp"
#include "Defines.hpp"

class Executable {
public:
    Executable();
    virtual ~Executable();
    
    void parse(Buffer buffer);
    void relocate(void* address);

    COFFHeader* getCoffHeader() const {
        return coff_header;
    }

    unsigned char* getMsdosStub() const {
        return msdos_stub;
    }

    OptionalHeader* getOptionalHeader() const {
        return optional_header;
    }

    SectionEntry* getSectionTable() const {
        return section_table;
    }

    char* getSignature() const {
        return signature;
    }
    
private:
    unsigned char* msdos_stub;
    char* signature;
    COFFHeader* coff_header;
    OptionalHeader* optional_header;
    SectionEntry* section_table;
};