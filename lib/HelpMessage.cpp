#include "HelpMessage.h"

HelpMessage::HelpMessage(std::string header, std::string* argumentDefinitions)
{
    this->help += header;
    for(std::string argumentDefinition : argumentDefinitions) {
        this->help += "-" + argumentDefinition[1] + ", --" + argumentDefinition[2];
        if(argumentDefinition[0] == "base") {
            this->help += "\n";
        }
        else {
            this->help += " " + argumentDefinition[2] + "\n";
        }
        this->help += argumentDefinition[4] + "\n";
    }
}
std::string HelpMessage::getHelp()
{
    return this->help;
}
