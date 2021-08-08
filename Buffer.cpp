#include "Buffer.hpp"

Buffer::Buffer(size_t size, void* data) {
    this->size = size;
    this->data = data;
}

Buffer::~Buffer() {
}

size_t Buffer::getSize() {
    return size;
}

void* Buffer::getData() {
    return data;
}