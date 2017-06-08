#include <iostream>
#include <iomanip>
#include <cmath>
#include "FileOperations.h"
#include "Command.h"

class catCommand : public Command
{
    public:
        catCommand(int argc, char** argv, std::string commandDefinition, std::map<std::string, std::map<std::string, std::string>> argumentDefinitions) :
            Command::Command(argc, argv, commandDefinition, argumentDefinitions)
        {};

        void run(int argc)
        {
            if(argc == 1) {
                std::cerr << "mkdir: missing operand" << std::endl << std::endl;
                this->printHelpMessage();
            } else if(this->arguments->getArgumentValue("help").compare("true") == 0) {
                this->printHelpMessage();
            } else if(this->arguments->getArgumentValue("version").compare("true") == 0) {
                this->printVersion();
            } else if(this->arguments->getExtras().empty()) {
                std::cerr << "TODO: read from std::cin" << std::endl << std::endl;
            } else {
                std::vector<std::string> files = this->arguments->getExtras();

                for(unsigned int i = 0; i < files.size(); i++) {
                    if(FileOperations::isDirectory(files[i])) {
                        std::cout << "cat: " << files[i] << ": Is a directory" << std::endl;
                    }

                    unsigned int lineNumber = 1;
                    std::vector<std::string> lines = FileOperations::getFileByLine(files[i]);
                    unsigned int lineCount = lines.size() + 1;
                    for(std::string line : lines) {
                        if(this->arguments->getArgumentValue("number-nonblank").compare("true") == 0) {
                            if(line.compare("") != 0) {
                                std::cout << std::setw(log10(lineCount)) << lineNumber << " ";
                                lineNumber++;
                            }
                        } else if(this->arguments->getArgumentValue("number").compare("true") == 0) {
                            std::cout << std::setw(log10(lineCount)) << lineNumber << " ";
                            lineNumber++;
                        }
                        std::cout << line << std::endl;
                    }
                }
            }
        }
};


int main(int argc, char *argv[])
{
    catCommand c(argc, argv,
        "Usage: cat [OPTION]... [FILE]...\n"
        "Concatenate FILE(s) to standard output.\n"
        "With no FILE, or when FILE is -, read standard input.\n",
        std::map<std::string, std::map<std::string, std::string>>{
            {"show-all", {
                {"longOption", "show-all"},
                {"shortOption", "A"},
                {"description", "equivalent to -vET"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"number-nonblank", {
                {"longOption", "number-nonblank"},
                {"shortOption", "b"},
                {"description", "number nonempty output lines, overrides -n"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"show-some", {
                {"longOption", "show-some"},
                {"shortOption", "e"},
                {"description", "equivalent to -vE"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"show-ends", {
                {"longOption", "show-ends"},
                {"shortOption", "E"},
                {"description", "display $ at end of each line"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"number", {
                {"longOption", "number"},
                {"shortOption", "n"},
                {"description", "number all output lines"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"squeeze-blank", {
                {"longOption", "squeeze-blank"},
                {"shortOption", "s"},
                {"description", "suppress repeated empty output lines"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"show-others", {
                {"longOption", "show-others"},
                {"shortOption", "t"},
                {"description", "equivalent to -vT"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"show-tabs", {
                {"longOption", "show-tabs"},
                {"shortOption", "T"},
                {"description", "display TAB characters as ^I"},
                {"hasOptions", "false"},
                {"value", "false"}
            }},
            {"show-nonprinting", {
                {"longOption", "show-nonprinting"},
                {"shortOption", "v"},
                {"description", "use ^ and M- notation, except for LFD and TAB"},
                {"hasOptions", "false"},
                {"value", "false"}
            }}
        }
    );
    c.run(argc);
    exit(EXIT_SUCCESS);
}
