#include "ArgumentBase.h"

ArgumentBase::ArgumentBase(std::string shortOption, std::string longOption, bool value)
{
    this->shortOption = shortOption;
    this->longOption = longOption;
    this->value = value;
}

bool ArgumentBase::getValue()
{
    return this->value;
}
