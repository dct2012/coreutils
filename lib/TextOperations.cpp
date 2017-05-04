#include <cstdio>
#include "TextOperations.h"

namespace TextOperations
{
    void echo(int length, char** string)
    {
        for(int i = 1; i < length; i++) {
            fputs(string[i], stdout);
            if(i + 1 != length) //place space between strings
                putchar(' ');
        }
        putchar('\n');
    }
}
