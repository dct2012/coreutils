#include "ArgumentString.h"

ArgumentString::ArgumentString(std::string shortOption, std::string longOption, std::string value)
{
    this->shortOption = shortOption;
    this->longOption = longOption;
    this->value = value;
}

std::string ArgumentString::getValue()
{
    return this->value;
}
