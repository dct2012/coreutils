#include <iostream>
#include "ArgumentCollection.h"
#include "HelpMessage.h"

std::string commandDefinition = "Usage: mkdir [OPTION]... DIRECTORY...\n"
    "Create the DIRECTORY(ies), if they do not already exist.\n";

std::vector<std::vector<std::string>> argumentDefinitions = {
    {"base", "p", "parents", "false", "make parent directories if they do not exist"},
    {"base", "v", "verbose", "false", "print a message for each directory created"},
    {"base", "h", "help", "false", "print a help message"},
    {"string", "m", "mode", "", "set file to mode"},
    {"strings", "", "directories", "", "directories to create if they don't already exist"}
};

HelpMessage help(commandDefinition, argumentDefinitions);

void printHelpMessage()
{
    std::cout << help.getHelp() << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc == 1) {
        std::cout << "mkdir: missing operand" << std::endl << std::endl;
        printHelpMessage();
    }
    else {
        ArgumentCollection* argcoll = new ArgumentCollection(argc, argv, argumentDefinitions);

        if(argcoll->getArgument("help") == "true"){
            printHelpMessage();
        }
    }

    exit(EXIT_SUCCESS);
}
