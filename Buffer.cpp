#include "Buffer.hpp"

Buffer::Buffer(size_t size, void* data) {
    this->size = size;
    this->data = data;
}

Buffer::~Buffer() {
}

