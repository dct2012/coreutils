#include <iostream>
#include "FileOperations.h"

int main(int argc, char *argv[])
{
    if(argc <= 1) {
        std::cout << "Print Help\n";
        return 1; //error
    } else {
        for(int i = 1; i < argc; i++) {
            FileOperations::echo(argv[i]);
            if(i + 1 != argc) //place space between strings
                putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
