#include "FileReader.h"

FileReader::FileReader(char* file)
{
    try {
        this->file = open(file, O_RDONLY, 0);
        this->filestream.open(file);
    }
    catch(int e){
        std::cout << "File Constructor Failed: " << e << std::endl;
    }
}

std::vector<std::string> FileReader::getFileByLine()
{
    std::string line;
    std::vector<std::string> out;

    while (std::getline(this->filestream, line)) {
        out.push_back(line);
    }

    return out;
}

FileReader::~FileReader()
{
    close(this->file);
}

ssize_t FileReader::readByBytes(char* buf)
{
    return read(this->file, buf, BUFSIZ);
}
