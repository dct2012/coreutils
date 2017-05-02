#include "FileCreator.h"

FileCreator::FileCreator(char* file)
{
    try {
        this->file = open(file, O_WRONLY | O_CREAT, 0644);
    }
    catch(int e){
        std::cout << "File Constructor Failed: " << e << "\n";
    }
}

FileCreator::~FileCreator()
{
    close(this->file);
}

ssize_t FileCreator::writeByBytes(char* buf, ssize_t size)
{
    return write(this->file, buf, size);
}
