#include "ArgumentCollection.h"
#include <iostream>

ArgumentCollection::ArgumentCollection(int argc, char** argv, std::map<std::string, std::map<std::string, std::string>> arguments)
{
    this->arguments = arguments;
    this->parseCommandLineArguments(argc, argv);
}

std::map<std::string, std::string>* ArgumentCollection::getArgument(std::string argumentName)
{
    for (std::pair<const std::string, std::map<std::string, std::string>>& argument : this->arguments) {
        if(argument.first.compare(argumentName) == 0 || argument.second["shortOption"].compare(argumentName) == 0) {
            return &argument.second;
        }
    }

    return nullptr;
}

void ArgumentCollection::updateArgument(std::string argumentName, std::string value)
{
    std::map<std::string, std::string>* argument = this->getArgument(argumentName);
    if(argument != nullptr) {
        (*argument)["value"] = value;
    } else {
        throw std::runtime_error("ArgumentColletion::updateArgumentsInvalid Argument");
    }
}

void ArgumentCollection::parseCommandLineArguments(int count, char** rawArguments)
{
    // i = 1 to skip command name
    for(int i = 1; i < count; i++) {
        std::string argumentName = rawArguments[i];

        if(argumentName[0] != '-') {
            this->extras.push_back(argumentName);
        } else {
            while(argumentName[0] == '-') {
                argumentName.erase(0, 1);
            }

            std::map<std::string, std::string>* argument = this->getArgument(argumentName);
            if(argument != nullptr) {
                if((*argument)["hasOptions"].compare("true") == 0 && rawArguments[i + 1][0] != '-') {
                    (*argument)["value"] = rawArguments[i + 1];
                } else {
                    (*argument)["value"] = "true";
                }
            } else { //cases similar to -pjklf filename
                for(unsigned int j = 0; j < argumentName.length(); j++) {
                    argument = this->getArgument(std::string(1, argumentName[j]));
                    if(argument != nullptr) {
                        if((j == (argumentName.length() - 1))&&((i + 1) > count)&&(rawArguments[i + 1][0] != '-')) {
                            (*argument)["value"] = rawArguments[i + 1];
                            i++;
                        } else {
                            (*argument)["value"] = "true";
                        }
                    }
                }
            }
        }
    }
}

std::string ArgumentCollection::getArgumentValue(std::string argumentName)
{
    return (*this->getArgument(argumentName))["value"]; //should be safe if smart programmer
}

std::vector<std::string> ArgumentCollection::getExtras()
{
    return this->extras;
}
