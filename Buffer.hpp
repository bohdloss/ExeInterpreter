#pragma once

#include <exception>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdexcept>

class Buffer {
public:
    Buffer(size_t size, void* data);
    virtual ~Buffer();
    
    template<typename T>
    T get(size_t offset) {
        if(offset < 0 || offset + sizeof(T) > this->size) {
            throw std::range_error("Out of buffer range");
        }
        T buffer;
        memcpy(&buffer, data + offset, sizeof(T));
        return buffer;
    }
    
    void copyOut(size_t offset, size_t destination, size_t size) {
        if(offset < 0 || offset + size > this->size) {
            throw std::range_error("Out of buffer range");
        }
        memcpy(destination, data + offset, size);
    }
private:
    size_t size;
    void* data;
};
