#include "Command.h"
#include <iostream>

Command::Command(int argc, char** argv, std::string commandDefinition, std::map<std::string, std::map<std::string, std::string>> argumentDefinitions)
{
    argumentDefinitions["help"] = {
        {"longOption", "help"},
        {"shortOption", "h"},
        {"description", "print a help message"},
        {"hasOptions", "false"},
        {"value", "false"}
    };
    argumentDefinitions["version"] = {
        {"longOption", "version"},
        {"shortOption", "0"},
        {"description", "output version and information"},
        {"hasOptions", "false"},
        {"value", "false"}
    };
    this->help = new HelpMessage(commandDefinition, argumentDefinitions);
    this->arguments = new ArgumentCollection(argc, argv, argumentDefinitions);
}

void Command::printHelpMessage()
{
    std::cout << this->help->getHelp() << std::endl;
}

void Command::printVersion()
{
    std::cout << "version #: develop" << std::endl;
}
