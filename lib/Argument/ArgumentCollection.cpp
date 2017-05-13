#include "ArgumentCollection.h"
#include <iostream>

ArgumentCollection::ArgumentCollection(int argc, char** argv, std::vector<std::vector<std::string>> argumentDefinitions)
{
    this->createArguments(argumentDefinitions);
    //this->parseCommandLineArguments(argc, argv);
}

void ArgumentCollection::createArguments(std::vector<std::vector<std::string>> argumentDefinitions)
{
    for(unsigned int i = 0; i < argumentDefinitions[0].size(); i++) {
        if(argumentDefinitions[i][0] == "base") {
            std::cout <<
                "ArgumentCollection::createArgument(" << argumentDefinitions[i][1] <<
                ", " << argumentDefinitions[i][2] <<
                ", " << argumentDefinitions[i][3] <<
                ");" << std::endl;
            ;
            this->createArgument(
                argumentDefinitions[i][1], argumentDefinitions[i][2], argumentDefinitions[i][3]
            );
        }
    }
    std::cout << "leaving createArguments() " << std::endl;
}

void ArgumentCollection::createArgument(std::string shortOption, std::string longOption, std::string value)
{
    std::cout <<
        "ArgumentCollection::updateArgument(" << shortOption <<
        ", " << value <<
        ");" << std::endl;
    ;
    this->updateArgument(shortOption, value);

    std::cout <<
        "ArgumentCollection::updateArgument(" << longOption <<
        ", " << value <<
        ");" << std::endl;
    ;
    this->updateArgument(longOption, value);
}

void ArgumentCollection::updateArgument(std::string argument, std::string value)
{
    std::pair<std::iterator,bool> ret = this->arguments->emplace(argument, value);
    if(ret.second == false) {
        std::cout << "ArgumentCollection::updateArgument: updating" << std::endl;
        (*this->arguments)[argument] = value;
    }

    std::cout << "ArgumentCollection::updateArgument: leaving" << std::endl;
}

void ArgumentCollection::parseCommandLineArguments(int count, char** rawArguments)
{
    std::map<std::string, std::string>::iterator it;
    std::string argument = "";

    for(int i = 0; i < (count - 1); i++) {

        argument = rawArguments[i];

        if('-' == argument[0]) {
            while('-' == argument[0]) {
                argument.erase(0, 1);
            }
            it = this->arguments->find(argument);
            if(it != this->arguments->end()) { //cases similar to -h, --help, or -f filename
                if('-' == rawArguments[i + 1][0]) {
                    this->updateArgument(argument, "true");
                }
                else {
                    this->updateArgument(argument, rawArguments[i + 1]);
                    i++;
                }
            }
            else {
                it = this->arguments->find(std::string(1, argument[0]));
                if(it != this->arguments->end()) { //cases similar to -pjklf filename
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
    return (*this->arguments)[argumentName]; //should be safe
}
