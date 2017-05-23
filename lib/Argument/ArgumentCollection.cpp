#include "ArgumentCollection.h"
#include <iostream>

ArgumentCollection::ArgumentCollection(int argc, char** argv, std::vector<std::vector<std::string>> argumentDefinitions)
{
    this->createArguments(argumentDefinitions);
    this->parseCommandLineArguments(argc, argv);
}

void ArgumentCollection::createArguments(std::vector<std::vector<std::string>> argumentDefinitions)
{
    for(unsigned int i = 0; i < argumentDefinitions[0].size(); i++) {
        if(argumentDefinitions[i][0] == "base") {
            this->createArgument(
                argumentDefinitions[i][1], argumentDefinitions[i][2], argumentDefinitions[i][3]
            );
        }
    }
}

void ArgumentCollection::createArgument(std::string shortOption, std::string longOption, std::string value)
{
    this->updateArgument(shortOption, value);
    this->updateArgument(longOption, value);
}

void ArgumentCollection::updateArgument(std::string argument, std::string value)
{
    std::cout << "ArgumentCollection::updateArgument("
        << argument << "," << value << ")" << std::endl;
    this->arguments.emplace(argument, value);
}

void ArgumentCollection::parseCommandLineArguments(int count, char** rawArguments)
{
    std::map<std::string, std::string>::iterator it;
    std::string argument = "";

    for(int i = 0; i < count; i++) {

        argument = rawArguments[i];

        if('-' == argument[0]) {
            while(argument[0] == '-') {
                argument.erase(0, 1);
            }
            it = this->arguments.find(argument);
            if(it != this->arguments.end()) { //cases similar to -h, --help, or -f filename
                std::string value = (i + 1 < count) ?
                    (('-' != rawArguments[i + 1][0]) ?
                        rawArguments[i + 1] : "true") :
                    "true";

                this->updateArgument(argument, value);
            }
            else {
                it = this->arguments.find(std::string(1, argument[0]));
                if(it != this->arguments.end()) { //cases similar to -pjklf filename
                    for(unsigned int j = 0; j < argument.length(); j++) {
                        if(j == (argument.length() - 1)) {
                            if('-' == rawArguments[i + 1][0]) {
                                this->updateArgument(std::string(1, argument[j]), "true");
                            }
                            else {
                                this->updateArgument(std::string(1, argument[j]), rawArguments[i + 1]);
                                i++;
                            }
                        } else {
                            this->updateArgument(std::string(1, argument[j]), "true");
                        }
                    }
                }
            }
        }
    }
}

std::string ArgumentCollection::getArgument(std::string argumentName)
{
    return this->arguments[argumentName]; //should be safe
}
