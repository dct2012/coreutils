#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    bool sflag = true;
    if(argc > 1 && (argv[1][0] == '-'))
        switch(argv[1][1]) {
            case 's': sflag = false;
                      break;
            default: printf("tty: invalid option -- '%c'\n"
                            "usage: tty [-s]\n", argv[1][1]);
                     exit(EXIT_FAILURE);
        }
    
    char *tty = ttyname(STDIN_FILENO);
    if(!tty)
        exit(EXIT_FAILURE);
    if(sflag)
        puts(tty);

    exit(EXIT_SUCCESS);
}
