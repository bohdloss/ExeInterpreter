#pragma once
#include "EIException.hpp"

class AllocationException : public EIException{
public:
    AllocationException();
protected:
    virtual std::string getClassname();
    virtual std::string getError();
};
