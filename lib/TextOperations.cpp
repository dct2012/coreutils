#include <iostream>
#include "TextOperations.h"

namespace TextOperations
{
    void echo(int length, char** string)
    {
        for(int i = 1; i < length; i++) {
            std::cout << string[i];;
            if(i + 1 != length) //place space between strings
                std::cout << " ";
        }
        std::cout << "\n";
    }
}
