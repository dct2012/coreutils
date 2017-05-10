#include "ArgumentStrings.h"

ArgumentStrings::ArgumentStrings(std::string shortOption, std::string longOption, std::string* value)
{
    this->shortOption = shortOption;
    this->longOption = longOption;
    this->value = value;
}

std::string* ArgumentStrings::getValue()
{
    return this->value;
}
