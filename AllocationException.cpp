#include "AllocationException.hpp"
#include "Defines.hpp"

AllocationException::AllocationException() {
}

std::string AllocationException::getClassname() {
    return "AllocationException";
}

std::string AllocationException::getError() {
    return NO_MALLOC;
}