#include "PortableExecutable.hpp"
#include "Buffer.hpp"

#include <string>

PortableExecutable::PortableExecutable() {
}

PortableExecutable::~PortableExecutable() {
    delete[] msdos_stub;
    delete[] signature;
    delete coff_header;
    delete optional_header;
    delete[] section_table;
}

void PortableExecutable::parse(Buffer buffer) {
    // Find some offsets and sizes
    size_t signature_begin = buffer.get<uint32_t>(0x3c);
    size_t signature_size = 4;
    size_t msdos_begin = 0;
    size_t msdos_size = signature_begin - msdos_begin;
    
    // Initialize stub
    msdos_stub = new unsigned char[msdos_size];
    if(!msdos_stub) {
        printf(NO_MALLOC);
        throw std::logic_error(NO_MALLOC);
    }
    buffer.copyOut(msdos_begin, msdos_stub, msdos_size);
    
    // Initialize signature
    signature = new char[4];
    char correct_signature[4] = "PE\0\0";
    if(!signature) {
        printf(NO_MALLOC);
        throw std::logic_error(NO_MALLOC);
    }
    buffer.copyOut(signature_begin, signature, signature_size);
    
    // Validate signature
    if(strncmp(signature, correct_signature, 4) != 0) {
        printf(NO_SIGNATURE);
        throw std::logic_error(NO_SIGNATURE);
    }
    
    // Initialize coff header
    size_t coff_begin = signature_begin + signature_size;
    size_t coff_size = sizeof(COFFHeader::nCOFF);
    coff_header = new COFFHeader();
    if(!coff_header) {
        printf(NO_MALLOC);
        throw std::logic_error(NO_MALLOC);
    }
    coff_header->parse(buffer, coff_begin);
    
    // Initialize optional header
    size_t optional_begin = coff_begin + coff_size;
    optional_header = new OptionalHeader();
    if(!optional_header) {
        printf(NO_MALLOC);
        throw std::logic_error(NO_MALLOC);
    }
    optional_header->parse(buffer, optional_begin);
    size_t optional_size = optional_header->sizeOf();
    
    // Validate size with previous data
    if(optional_size != coff_header->getOptionalHeaderSize()) {
        printf(NO_OPTSIZE);
        throw std::logic_error(NO_OPTSIZE);
    }
    
    // Initialize section table
    size_t section_begin = optional_begin + optional_size;
    size_t section_length = coff_header->getNumberOfSections();
    section_table = new SectionEntry[section_length];
    if(!section_table) {
        printf(NO_MALLOC);
        throw std::logic_error(NO_MALLOC);
    }
    
    // Parse section table
    for(uint16_t i = 0; i < section_length; i++) {
        section_table[i].parse(buffer, section_begin, &i, coff_header);
        print(section_table[i].getName());
    }
}

void PortableExecutable::relocate(void* address) {
    
}