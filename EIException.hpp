#pragma once

#include <string>
#include "Utils.hpp"

class EIException {
public:
    EIException();
    virtual ~EIException();
    
    std::string getMessage() const {
        return getClassname() + ": " + getError();
    }
    
    void printMessage() const {
        print(getMessage());
    }
protected:
    virtual std::string getClassname();
    virtual std::string getError();
};
