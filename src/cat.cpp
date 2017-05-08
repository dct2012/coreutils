#include <iostream>
#include <FileOperations.h>

int main(int argc, char *argv[])
{


    for(int i = 1; i < argc; i++) {
        if(FileOperations::isDirectory(argv[i])) {
            std::cout << "cat: " << argv[i] << ": Is a directory" << std::endl;
            return 1;
        }
        std::cout << FileOperations::cat(argv[i]);
    }

    return 0;
}
