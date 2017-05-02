#include <iostream>
#include <fcntl.h>   // open
#include <unistd.h>  // read, write, close
#include <cstdio>    // BUFSIZ

class File {
    private:
        char buf[BUFSIZ];
        size_t size;
        int source;
        int destination;

    public:
        File(char*, char*);
        ~File();
        ssize_t copy();
};
