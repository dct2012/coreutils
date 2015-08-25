#define _DEFAULT_SOURCE
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

bool pflag = false;
bool vflag = false;
mode_t mode = 0777;
char *usage = "usage: mkdir [-phv] [-m mode] dir...";

bool pathexists(char *dir)
{
    struct stat s;
    if(stat(dir, &s) == 0) return true;
    return false;
}

bool makedir(char *dir, mode_t mode)
{
    //check if path exists first
    if(pathexists(dir)) {
        printf("mkdir: cannot create directory ‘%s’: File exists\n", dir);
        exit(EXIT_FAILURE);
    }

    if(mkdir(dir, mode) == -1) return false;

    if(vflag) printf("mkdir: created directory ‘%s’\n", dir);

    return true;
}

bool makedirp(char *dir, mode_t mode)
{
    //if directory exists leave
    if(pathexists(dir)) return true;

    if(makedir(dir, mode)) return true;

    int i;
    for(i = strlen(dir); i >= 0; i--)
        if(dir[i] == '/')
            break;

    char *s = malloc(i);
    strncpy(s, dir, i);
    makedirp(s, mode);
    free(s);
        
    makedirp(dir, mode);
 
    return true;
}


//handlearguments() sets the appropriate flags and mode
//also creates a array of the dirs to be made
int handlearguments(int argc, char *argv[], char **dir)
{
    int index = 0;
    
    for(int i = 1; i < argc; i++) {
        if('-' == argv[i][0]) {
            for(int j = 1; j < strlen(argv[i]); j++) {
                switch (argv[i][j]) {
                    case 'p':   pflag = 1; break;

                    case 'm':   if('-' == argv[i + 1][0]) {
                                    puts(usage);
                                    exit(EXIT_FAILURE);
                                } else {
                                    i++;
                                    mode = strtoul(argv[i], &argv[i], 10);
                                
                                    if(mode > 777) {
                                        puts(usage);
                                        exit(EXIT_FAILURE);
                                    }
                                }
                                break;

                    case 'h':   puts(usage);
                                exit(EXIT_SUCCESS);

                    case 'v' :  vflag = true;
                                break;

                    default:    printf("mkdir: invalid option -- '%c'\n", 
                                        argv[i][j]);
                                puts(usage);
                                break;
                }
            }
        } else {
            dir[index] = (char*)malloc(strlen(argv[i]) + 1);
            strcpy(dir[index], argv[i]);
            index++;
        }
    }

    return index; 
}

int main(int argc, char *argv[])
{
    if(argc == 1) puts("mkdir: missing operand");
    else {
        char **dir = (char**)malloc((argc - 1) * sizeof(char*));
        int n = handlearguments(argc, argv, dir);

        for(int i = 0; i < n; i++)
            if(pflag) {
                if(!makedirp(dir[i], mode)) exit(EXIT_FAILURE);
            } else if(!makedir(dir[i], mode)) {
                printf("mkdir: cannot create directory ‘%s’\n",
                        dir[i]);
                exit(EXIT_FAILURE);
            }
        
        free(dir);
    }
    exit(EXIT_SUCCESS);
}
