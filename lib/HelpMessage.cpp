#include "HelpMessage.h"

HelpMessage::HelpMessage(std::string header, std::vector<std::vector<std::string>> argumentDefinitions)
{
    this->help += header + "\n";
    for(unsigned int i = 0; i < argumentDefinitions[0].size(); i++) {
        this->help += " -" + argumentDefinitions[i][1] + ", --" + argumentDefinitions[i][2];
        if(argumentDefinitions[i][0] != "base") {
            this->help += " " + argumentDefinitions[i][2];
        }
        this->help += "\t" + argumentDefinitions[i][4] + "\n";
    }
}
std::string HelpMessage::getHelp()
{
    return this->help;
}
