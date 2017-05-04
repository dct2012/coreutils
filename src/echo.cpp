#include <iostream>
#include "TextOperations.h"

int main(int argc, char *argv[])
{
    if(argc <= 1) {
        std::cout << "Print Help\n";
        return 1; //error
    } else {
        TextOperations::echo(argc, argv);
    }

    return 0;
}
