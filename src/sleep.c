#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

char* substring(const char *string, regoff_t start, regoff_t end)
{
    char *new_string = malloc(end - start);
    memcpy(new_string, &string[start], end - start);
    return new_string;
}

char* regex(const char *regex, const char *string)
{
    regex_t exp;
    if(regcomp(&exp, regex, REG_EXTENDED) != 0)
        return NULL;

    regmatch_t match[1];
    if(regexec(&exp, string, 1, match, 0) != 0)
        return NULL;

    return substring(string, match[0].rm_so, match[0].rm_eo);
}

int timetomultiple(const char *string)
{
    switch(string[0]) {
        case 'm': return 60;
        case 'h': return 60 * 60;
        case 'd': return 60 * 60 * 24;
        default: break;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    int multiplier = 1;
    char *c_number = NULL;
    char *c_time = NULL;
    unsigned int n_number;

    if(argc == 1) {
        puts("sleep: missing operand");
        return 1;
    } else {
        if((c_number = regex("[0-9]+", argv[1])) == NULL)
            return 1;

        n_number = atoi(c_number);
        free(c_number);

        if((c_time = regex("[smhd]", argv[1])) != NULL) {
            multiplier = timetomultiple(c_time);
            free(c_time);
        }
        
        sleep(n_number * multiplier);
    }

    return 0;
}
