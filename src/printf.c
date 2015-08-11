#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc == 1) {
        puts("printf: not enough arguments");
        return 1;
    } else {
        printf(argv[1], argv[2]);
        
    }

    return 0;
}
