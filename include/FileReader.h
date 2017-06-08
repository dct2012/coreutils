#include <iostream>
#include <fcntl.h>   // open
#include <unistd.h>  // read, write, close
#include <cstdio>    // BUFSIZ
#include <fstream>
#include <string>
#include <vector>

class FileReader {
    private:
        int file;
        std::ifstream filestream;

    public:
        FileReader(char*);
        ~FileReader();
        ssize_t readByBytes(char*);
        std::vector<std::string> getFileByLine();
};
