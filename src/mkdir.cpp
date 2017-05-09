#include <iostream>
#include "ArgumentCollection.h"

int main(int argc, char *argv[])
{
    ArgumentCollection* argcoll = new ArgumentCollection(argc, argv,
        {   {"base", "p", "parents", false, "make parent directories if they do not exist"},
            {"base", "v", "verbose", false, "print a message for each directory created"},
            {"base", "h", "help", false, "print a help message"},
            {"string", "m", "mode", NULL, "set file to mode"},
            {"strings", NULL, "directories", {}, "directories to create if they don't already exist"}
        }
    );
    if(argc == 1)
        std::cout << "mkdir: missing operand" << std::endl;
    else {
        char **dir = (char**)malloc((argc - 1) * sizeof(char*));
        int n = handlearguments(argc, argv, dir);

        for(int i = 0; i < n; i++)
            if(pflag) {
                if(!makedirp(dir[i], mode)) exit(EXIT_FAILURE);
            } else if(!makedir(dir[i], mode)) {
                printf("mkdir: cannot create directory ‘%s’\n",
                        dir[i]);
                exit(EXIT_FAILURE);
            }

        free(dir);
    }
    exit(EXIT_SUCCESS);
}
