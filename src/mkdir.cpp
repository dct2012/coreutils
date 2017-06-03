#include <iostream>
#include "ArgumentCollection.h"
#include "HelpMessage.h"
#include "FileOperations.h"
#include "TextOperations.h"

std::string commandDefinition = "Usage: mkdir [OPTION]... DIRECTORY...\n"
    "Create the DIRECTORY(ies), if they do not already exist.\n";

std::map<std::string, std::map<std::string, std::string>> argumentDefinitions = {
    {"help", {
        {"longOption", "help"},
        {"shortOption", "h"},
        {"description", "print a help message"},
        {"hasOptions", "false"},
        {"value", "false"}
    }},
    {"parents", {
        {"longOption", "parents"},
        {"shortOption", "p"},
        {"description", "make parent directories if they do not exist"},
        {"hasOptions", "false"},
        {"value", "false"}
    }},
    {"verbose", {
        {"longOption", "verbose"},
        {"shortOption", "v"},
        {"description", "print a message for each directory created"},
        {"hasOptions", "false"},
        {"value", "false"}
    }},
    {"mode", {
        {"longOption", "mode"},
        {"shortOption", "h"},
        {"description", "set file to mode"},
        {"hasOptions", "true"},
        {"value", "0777"}
    }},
};

HelpMessage help(commandDefinition, argumentDefinitions);

void printHelpMessage()
{
    std::cout << help.getHelp() << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc == 1) {
        std::cerr << "mkdir: missing operand" << std::endl << std::endl;
        printHelpMessage();
    }
    else {
        ArgumentCollection* argcoll = new ArgumentCollection(argc, argv, argumentDefinitions);

        std::cout << "help: " << argcoll->getArgumentValue("help") << std::endl;
        std::cout << "parents: " << argcoll->getArgumentValue("parents") << std::endl;
        std::cout << "verbose: " << argcoll->getArgumentValue("verbose") << std::endl;
        std::cout << "mode: " << argcoll->getArgumentValue("mode") << std::endl;

        if(argcoll->getArgumentValue("help").compare("true") == 0) {
            printHelpMessage();
        } else if(argcoll->getExtras().empty()) {
            std::cerr << "mkdir: missing DIRECTORY(ies)" << std::endl << std::endl;
            printHelpMessage();
        }
        else {
            std::vector<std::string> dir = argcoll->getExtras();

            for(unsigned int i = 0; i < dir.size(); i++) {
                std::string mode = argcoll->getArgumentValue("mode");
                if(argcoll->getArgumentValue("parents").compare("true") == 0) {
                    FileOperations::makedirp(
                        dir[i].c_str(),
                        TextOperations::stringToInt(mode),
                        (argcoll->getArgumentValue("verbose").compare("true") == 0)
                    );
                }
                else {
                    FileOperations::makedir(
                        dir[i].c_str(),
                        TextOperations::stringToInt(mode),
                        (argcoll->getArgumentValue("verbose").compare("true") == 0)
                    );
                }
            }
        }
    }

    exit(EXIT_SUCCESS);
}
