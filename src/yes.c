#include <stdio.h>

int main(int argc, char *argv[])
{
    while(1)
    {
        if(argc == 1)
            putchar('y');
        else
            for(int i = 1; i < argc; i++)
                printf("%s ", argv[i]);
        putchar('\n');
    }

    return 0;
}
