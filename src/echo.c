#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int newline = 0;

    if(argc > 1 && (strcmp(argv[1], "-n") == 0))
        newline = 1;

    for(int i = 1 + newline; i < argc; i++) {
        fputs(argv[i], stdout);
        if(i + 1 != argc)
            putchar(' ');
    }
    
    if(!newline)
        putchar('\n');

    return 0;
}
