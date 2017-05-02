#include <iostream>
#include <fcntl.h>   // open
#include <unistd.h>  // read, write, close
#include <cstdio>    // BUFSIZ

class FileReader {
    private:
        int file;

    public:
        FileReader(char*);
        ~FileReader();
        ssize_t readByBytes(char*);
};
