#include "ArgumentCollection.h"


ArgumentCollection::ArgumentCollection(int argc, char** argv, std::string** argumentDefinitions)
{
    this->createArguments(argumentDefinitions);
    this->parseCommandLineArguments(argc, argv);
}

void ArgumentCollection::createArguments(std::string** argumentDefinitions)
{
    for(std::string* argumentDefinition : argumentDefinitions) {
        ArgumentBase* temp = NULL;
        if(argumentDefinition[0] == "base") {
            temp = new ArgumentBase(argumentDefinition[1], argumentDefinition[2], argumentDefinition[3]);
            this->arguments[argumentDefinition[1]] = temp;
            this->arguments[argumentDefinition[2]] = temp;
        }
    }
}

void ArgumentCollection::parseCommandLineArguments(int count, char** rawArguments)
{
    for(int i = 1; i < count; i++) {
        std::string argument = rawArguments[i];
        if('-' == argument[0]) {
            while('-' == argument[0]) {
                argument.erase(0, 1);
            }
            if(this->arguments.find(argument)) { //cases similar to -h, --help, or -f filename
                if('-' == rawArguments[i + 1][0]) {
                    this->arguments[argument] =  "true";
                }
                else {
                    this->arguments[argument] = rawArguments[i + 1];
                    i++;
                }
            }
            else if(args.find(argument[0])) { //cases similar to -pjklf filename
                for(int j = 0; j < argument.length(); j++) {
                    if(j == (argument.length() - 1)) {
                        if('-' == rawArguments[i + 1][0]) {
                            this->arguments[argument[j]] =  "true";
                        }
                        else {
                            this->arguments[argument[j]] = rawArguments[i + 1];
                            i++;
                        }
                    } else {
                        this->arguments[argument[j]] =  "true";
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
