#include "FileReader.h"

FileReader::FileReader(char* file)
{
    try {
        this->file = open(file, O_RDONLY, 0);
    }
    catch(int e){
        std::cout << "File Constructor Failed: " << e << "\n";
    }
}

FileReader::~FileReader()
{
    close(this->file);
}

ssize_t FileReader::readByBytes(char* buf)
{
    return read(this->file, buf, BUFSIZ);
}
