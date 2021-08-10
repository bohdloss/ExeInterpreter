#include "ParseException.hpp"

ParseException::ParseException(std::string error) {
    this->error = error;
}

std::string ParseException::getClassname() {
    return "ParseException";
}

std::string ParseException::getError() {
    return error;
}