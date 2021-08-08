#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string>

template<typename T>
void print(T value) {
    printf("Unknown type\n");
}

template<>
void print<uint8_t>(uint8_t v);
template<>
void print<uint16_t>(uint16_t v);
template<>
void print<uint32_t>(uint32_t v);
template<>
void print<uint64_t>(uint64_t v);
template<>
void print<const char*>(const char* v);
template<>
void print<char*>(char* v);
template<>
void print<std::string>(std::string v);