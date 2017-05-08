#include <iostream>
#include "FileOperations.h"

int main(int argc, char *argv[])
{
    if(argc != 3) {
        std::cout << "Print Help" << std::endl;
        return 1; //error
    } else {
        FileOperations::filecopy(argv[1], argv[2]);
    }

    return 0;
}
