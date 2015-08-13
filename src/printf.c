#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(const char *string, char *args[]);

void handle_formatter(int c, const char *arg)
{
    //TODO: we should also handle precision, maybe? it doesn't look like gnu does
    switch(c) {
        case '%':
            putchar('%');
            break;
        case 'b':
            print(arg, NULL);
            break;

        case 'd':
        case 'i':
            printf("%d", atoi(arg));
            break;
            //TODO: add warning to value not completely converted
            //meaning we should probably convert them ourselves
        case 'o':
            printf("%o", atoi(arg));
            break;
        case 'u':
            printf("%u", atoi(arg));
            break;
        case 'x':
            printf("%x", atoi(arg));
            break;
        case 'X':
            printf("%X", atoi(arg));
            break;
            //end todo
        case 'f':
        case 'F':
            printf("%f", atof(arg));
            break; 
        case 'e':
            printf("%e", atof(arg));
            break;
        case 'E':
            printf("%E", atof(arg));
            break;
        case 'g':
            printf("%g", atof(arg));
            break;
        case 'G':
            printf("%G", atof(arg));
            break;
        case 'c':
            putchar(arg[0]);
            break;
        case 's':
            fputs(arg, stdout);
            break;

        default:
            break;
    }
}

int handle_escape(int c)
{
    switch(c) {
        case '"':
            putchar('"');
            break;
        //case '\\':
        //case 'a':
        case 'b':
            putchar('\b');
            break;
        case 'c':
            return -1;
        case 'e':
            putchar('\e');
            break;
        case 'f':
            putchar('\f');
            break;
        case 'n':
            putchar('\n');
            break;
        case 'r':
            putchar('\r');
            break;
        case 't':
            putchar('\t');
            break;
        case 'v':
            putchar('\v');
            break;

        //case octal, hex, unicode 4 and 8
        
        default:
            break;
    }

    return 0;
}

void print(const char *string, char *args[])
{
    int arg_count = 0;
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == '%' && args)
            handle_formatter(string[++i], args[arg_count++]);
        else if(string[i] == '\\') {
            if(handle_escape(string[++i]) == -1)
                return;
        } else
            putchar(string[i]);
    }
}

int main(int argc, char *argv[])
{
    if(argc == 1) {
        puts("printf: not enough arguments");
        return 1;
    } else
        print(argv[1], &argv[2]);

    return 0;
}
