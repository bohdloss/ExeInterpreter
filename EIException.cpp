#include "EIException.hpp"

EIException::EIException() {
}

EIException::~EIException() {
}

std::string EIException::getClassname() {
    return "EIException";
}

std::string EIException::getError() {
    return "Unknown error";
}