#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    FILE *file = NULL;
    int c;
    struct stat s;

    for(int i = 1; i < argc; i++)
    {
        if(stat(argv[i], &s) != 0) 
            printf("cat: %s: No such file or directory\n", argv[i]);
        else if(S_ISDIR(s.st_mode)) 
            printf("cat: %s: Is a directory\n", argv[i]);
        else
        {
            file = fopen(argv[i], "r");

            while((c = fgetc(file)) != EOF)
                printf("%c", c);

            fclose(file);
        }
    }

    return 0;
}
