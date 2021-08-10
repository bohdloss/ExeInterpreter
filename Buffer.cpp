#include "Buffer.hpp"

BufferException::BufferException() {
}

std::string BufferException::getClassname() {
    return "BufferException";
}

std::string BufferException::getError() {
    return NO_RANGE;
}

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