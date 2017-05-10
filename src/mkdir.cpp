#include <iostream>
#include "ArgumentCollection.h"
#include "HelpMessage.h"

int main(int argc, char *argv[])
{
    std::string commandDefinition = "NAME\n\tmkdir - make directories\n"
        + "SYNOPSIS\n\tmkdir [OPTION]... DIRECTORY...\n"
        + "DESCRIPTION\n\tCreate DIRECTORYies if the do not already exist\n";
    std::string* argumentDefinitions = {
        {"base", "p", "parents", false, "make parent directories if they do not exist"},
        {"base", "v", "verbose", false, "print a message for each directory created"},
        {"base", "h", "help", false, "print a help message"},
        {"string", "m", "mode", NULL, "set file to mode"},
        {"strings", NULL, "directories", {}, "directories to create if they don't already exist"}
    };

    ArgumentCollection* argcoll = new ArgumentCollection(argc, argv, argumentDefinitions);
    HelpMessage* help = new HelpMessage(commandDefinition, argumentDefinitions);

    if(argc == 1) {
        std::cout << "mkdir: missing operand" << std::endl;
        std::cout << help->getHelp();
    } else {
        // char **dir = (char**)malloc((argc - 1) * sizeof(char*));
        // int n = handlearguments(argc, argv, dir);
        //
        // for(int i = 0; i < n; i++)
        //     if(pflag) {
        //         if(!makedirp(dir[i], mode)) exit(EXIT_FAILURE);
        //     } else if(!makedir(dir[i], mode)) {
        //         printf("mkdir: cannot create directory ‘%s’\n",
        //                 dir[i]);
        //         exit(EXIT_FAILURE);
        //     }
        //
        // free(dir);
    }
    exit(EXIT_SUCCESS);
}
