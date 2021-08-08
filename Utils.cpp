#include "Utils.hpp"

template<>
void print<uint8_t>(uint8_t v) {
    printf(std::to_string(v).c_str());
    printf("\n");
}

template<>
void print<uint16_t>(uint16_t v) {
    printf(std::to_string(v).c_str());
    printf("\n");
}

template<>
void print<uint32_t>(uint32_t v) {
    printf(std::to_string(v).c_str());
    printf("\n");
}

template<>
void print<uint64_t>(uint64_t v) {
    printf(std::to_string(v).c_str());
    printf("\n");
}

template<>
void print<const char*>(const char* v) {
    printf(v);
    printf("\n");
}

template<>
void print<char*>(char* v) {
    printf(v);
    printf("\n");
}

template<>
void print<std::string>(std::string v) {
    printf(v.c_str());
    printf("\n");
}