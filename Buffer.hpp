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
        if(offset < 0 || offset + sizeof(T) > size) {
            throw std::range_error("Out of buffer range");
        }
        T buffer;
        memcpy(&buffer, data + offset, sizeof(T));
        return buffer;
    }
    
    template<typename T>
    T operator[](size_t offset) {
        return get<T>(offset);
    }
private:
    size_t size;
    void* data;
};
