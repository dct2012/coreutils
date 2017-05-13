#include "ArgumentBase.h"
#include <stdexcept>

ArgumentBase::ArgumentBase(std::string shortOption, std::string longOption, std::string value)
{
    this->shortOption = shortOption;
    this->longOption = longOption;
    try {
        this->set(value);
    }
    catch(std::exception& e) {
        char* err = NULL;
        sprintf(err, "ArgumentBase::ArgumentBase(): { %s }", e.what());
        throw std::invalid_argument(err);
    }
}

void ArgumentBase::set(std::string value)
{
    if(value == "true") {
        this->value = true;
    }
    else if(value == "false") {
        this->value = false;
    }
    else {
        char* err = NULL;
        sprintf(
            err, "ArgumentBase::set(): invalid value of: %s: for argument: %s",
            value.c_str(), this->shortOption.c_str()
        );
        throw std::invalid_argument(err);
    }
}

std::string ArgumentBase::getToString()
{
    return this->value ? "true" : "false";
}

bool ArgumentBase::getValue()
{
    return this->value;
}
