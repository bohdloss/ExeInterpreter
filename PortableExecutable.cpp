#include "PortableExecutable.hpp"
#include "Buffer.hpp"

#include <string>

PortableExecutable::PortableExecutable() {
}

PortableExecutable::~PortableExecutable() {
}

void PortableExecutable::parse(Buffer buffer) {
    // Find some offsets and sizes
    size_t signature_begin = buffer.get<uint32_t>(0x3c);
    size_t signature_size = 4;
    size_t msdos_begin = 0;
    size_t msdos_size = signature_begin - msdos_begin;
    size_t coff_begin = signature_begin + signature_size;
    
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
    coff_header = new COFFHeader();
    if(!coff_header) {
        printf(NO_MALLOC);
        throw std::logic_error(NO_MALLOC);
    }
    coff_header->parse(buffer, coff_begin);
}

void PortableExecutable::relocate(void* address) {
    
}

unsigned char* PortableExecutable::getMsdosStub() {
    return msdos_stub;
}

char* PortableExecutable::getSignature() {
    return signature;
}

COFFHeader* PortableExecutable::getCoffHeader() {
    return coff_header;
}

OptionalHeader* PortableExecutable::getOptionalHeader() {
    return optional_header;
}

SectionEntry* PortableExecutable::getSectionTable() {
    return section_table;
}