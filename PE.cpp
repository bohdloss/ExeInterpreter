#include "PE.hpp"
#include "Buffer.hpp"

PE::PE() {
}

PE::~PE() {
}

bool PE::parse(size_t size, void* raw) {
    Buffer buffer(size, raw);
    
    return true;
}

bool PE::relocate(void* address) {
    return true;
}