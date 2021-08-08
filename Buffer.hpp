#pragma once

#include <exception>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdexcept>

#define NO_RANGE "Out of buffer range"

class Buffer {
public:
    Buffer(size_t size, void* data);
    virtual ~Buffer();
    
    template<typename T>
    T get(size_t offset) {
        if(offset < 0 || offset + sizeof(T) > this->size) {
            throw std::range_error(NO_RANGE);
        }
        T buffer;
        memcpy(&buffer, data + offset, sizeof(T));
        return buffer;
    }
    
    template<typename T>
    void set(size_t offset, T value) {
        if(offset < 0 || offset + sizeof(T) > this->size) {
            throw std::range_error(NO_RANGE);
        }
        memcpy(data + offset, &value, sizeof(T));
    }
    
    void copyOut(size_t offset, size_t destination, size_t size) {
        if(offset < 0 || offset + size > this->size) {
            throw std::range_error(NO_RANGE);
        }
        memcpy(destination, data + offset, size);
    }
    
    void copyIn(size_t offset, size_t source, size_t size) {
        if(offset < 0 || offset + size > this->size) {
            throw std::range_error(NO_RANGE);
        }
        memcpy(data + offset, source, size);
    }
    
    size_t getSize();
    void* getData();
private:
    size_t size;
    void* data;
};
