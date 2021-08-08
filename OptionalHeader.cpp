#include "OptionalHeader.hpp"
#include "Defines.hpp"

OptionalHeader::OptionalHeader() {
}

OptionalHeader::~OptionalHeader() {
}

void OptionalHeader::parse(Buffer buffer, size_t header_offset) {
    // Get magic number
    uint16_t magic = buffer.get<uint16_t>(header_offset);
    
    switch(magic) {
        case IMAGE_PE32:
        {
            this->bPe32Plus = false;
            nPE32 optional_struct = buffer.get<nPE32>(header_offset);
            
            memcpy(&magic, &optional_struct.magic, 24);
            
            this->image_base = optional_struct.image_base;
            
            memcpy(&section_alignment, &optional_struct.section_alignment, 40);
            
            this->stack_reserve_size = optional_struct.stack_reserve_size;
            this->stack_commit_size = optional_struct.stack_commit_size;
            this->heap_reserve_size = optional_struct.heap_reserve_size;
            this->heap_commit_size = optional_struct.heap_commit_size;
            
            memcpy(&loader_flags, &optional_struct.loader_flags, 8);
            break;
        }
        case IMAGE_PE32PLUS:
        {
            this->bPe32Plus = true;
            nPE32PLUS optional_struct = buffer.get<nPE32PLUS>(header_offset);
            
            memcpy(&magic, &optional_struct.magic, 20);
            
            this->image_base = optional_struct.image_base;
            
            memcpy(&section_alignment, &optional_struct.section_alignment, 40);
            
            this->stack_reserve_size = optional_struct.stack_reserve_size;
            this->stack_commit_size = optional_struct.stack_commit_size;
            this->heap_reserve_size = optional_struct.heap_reserve_size;
            this->heap_commit_size = optional_struct.heap_commit_size;
            
            memcpy(&loader_flags, &optional_struct.loader_flags, 8);
            break;
        }
        default:
        {
            printf(NO_MAGIC);
            throw std::logic_error(NO_MAGIC);
        }
    }
    
}

size_t OptionalHeader::sizeOf() {
    return bPe32Plus ? sizeof(nPE32PLUS) : sizeof(nPE32);
}
