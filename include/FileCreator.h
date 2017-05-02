#include <iostream>
#include <fcntl.h>   // open
#include <unistd.h>  // read, write, close
#include <cstdio>    // BUFSIZ

class FileCreator {
    private:
        int file;

    public:
        FileCreator(char*);
        ~FileCreator();
        ssize_t writeByBytes(char*, ssize_t);
};
