#include "HelpMessage.h"

HelpMessage::HelpMessage(std::string header, std::map<std::string, std::map<std::string, std::string>> argumentDefinitions)
{
    this->help += header + "\n";
    for (std::pair<const std::string, std::map<std::string, std::string>>& argument : argumentDefinitions) {
        this->help += " -" + argument.second["shortOption"] + ", --" + argument.second["longOption"];
        if(argument.second["hasOptions"] == "true") {
            this->help += " [value]";
        }
        this->help += "\t\t" + argument.second["description"] + "\n";
    }
}
std::string HelpMessage::getHelp()
{
    return this->help;
}
