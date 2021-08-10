#include "SectionEntry.hpp"
#include "Utils.hpp"
#include "AllocationException.hpp"

SectionEntry::SectionEntry() {
}

SectionEntry::~SectionEntry() {
    delete[] name;
}

void SectionEntry::parse(Buffer buffer, size_t offset, uint16_t* index, COFFHeader* coff_header) {
    // Copy data structure
    nSectionEntry entry_struct = buffer.get<nSectionEntry>(offset + (*index) * sizeof(nSectionEntry));
    
    // Retrieve the name
    if(entry_struct.name[0] == '/') {
        // The string is located in the string table
        char* offset_str = &entry_struct.name[1];
        uint32_t offset = std::stoi(std::string(offset_str));
        char* string = coff_header->getString(offset);
        size_t string_len = strlen(string) + 1;
        
        // Copy it
        this->name = new char[string_len];
        if(!name) {
            throw new AllocationException();
        }
        memcpy(name, string, string_len);
    } else {
        // Is the string null terminated?
        char* string = &entry_struct.name[0];
        bool null_term = string[7] == '\0';
        if(null_term) {
            size_t string_len = strlen(string) + 1;
            this->name = new char[string_len];
            if(!name) {
                throw new AllocationException();
            }
            memcpy(name, string, string_len);
        } else {
            this->name = new char[9];
            if(!name) {
                throw new AllocationException();
            }
            memcpy(name, string, 8);
            name[8] = '\0';
        }
    }
    
    // Copy the rest of the data
    this->virtual_size = entry_struct.virtual_size;
    this->virtual_address = entry_struct.virtual_address;
    this->raw_data_size = entry_struct.raw_data_size;
    this->raw_data_ptr = entry_struct.raw_data_ptr;
    this->relocation_ptr = entry_struct.relocation_ptr;
    this->line_number_ptr = entry_struct.line_number_ptr;
    this->number_of_relocation = entry_struct.number_of_relocation;
    this->number_of_line_number = entry_struct.number_of_line_number;
    this->characteristics = entry_struct.characteristics;
}