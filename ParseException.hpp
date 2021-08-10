#pragma once
#include "EIException.hpp"

class ParseException : public EIException {
public:
    ParseException(std::string error);
protected:
    std::string error;
    virtual std::string getClassname();
    virtual std::string getError();
};