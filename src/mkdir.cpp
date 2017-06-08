#include <iostream>
#include "Command.h"
#include "FileOperations.h"
#include "TextOperations.h"

class mkdirCommand : public Command
{
    public:
        mkdirCommand(int argc, char** argv, std::string commandDefinition, std::map<std::string, std::map<std::string, std::string>> argumentDefinitions) :
            Command::Command(argc, argv, commandDefinition, argumentDefinitions)
        {};

        void run(int argc)
        {
            if(argc == 1) {
                std::cerr << "mkdir: missing operand" << std::endl << std::endl;
                this->printHelpMessage();
            }
            else {

                if(this->arguments->getArgumentValue("help").compare("true") == 0) {
                    this->printHelpMessage();
                } else if(this->arguments->getArgumentValue("version").compare("true") == 0) {
                    this->printVersion();
                } else if(this->arguments->getExtras().empty()) {
                    std::cerr << "mkdir: missing DIRECTORY(ies)" << std::endl << std::endl;
                    this->printHelpMessage();
                }
                else {
                    std::vector<std::string> dir = this->arguments->getExtras();

                    for(unsigned int i = 0; i < dir.size(); i++) {
                        if(this->arguments->getArgumentValue("parents").compare("true") == 0) {
                            FileOperations::makedirp(
                                dir[i].c_str(),
                                TextOperations::stringToModeT(this->arguments->getArgumentValue("mode")),
                                (this->arguments->getArgumentValue("verbose").compare("true") == 0)
                            );
                        }
                        else {
                            FileOperations::makedir(
                                dir[i].c_str(),
                                TextOperations::stringToModeT(this->arguments->getArgumentValue("mode")),
                                (this->arguments->getArgumentValue("verbose").compare("true") == 0)
                            );
                        }
                    }
                }
            }
        }
};

int main(int argc, char *argv[])
{
    mkdirCommand m(argc, argv,
        "Usage: mkdir [OPTION]... DIRECTORY...\n"
        "Create the DIRECTORY(ies), if they do not already exist.\n",
        std::map<std::string, std::map<std::string, std::string>>{
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
                {"shortOption", "m"},
                {"description", "set file to mode"},
                {"hasOptions", "true"},
                {"value", "0777"}
            }},
        }
    );
    m.run(argc);
    exit(EXIT_SUCCESS);
}
