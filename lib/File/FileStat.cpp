#include "FileStat.h"
#include <stdexcept>

FileStat::FileStat(const char* src)
{
    if(stat(src, &this->s) != 0) {
        char* err = NULL;
        sprintf(err, "FileStat::FileStat(): %s: No such file or directory", src);
        throw std::invalid_argument(err);
    }
}

bool FileStat::isDirectory()
{
    return S_ISDIR(this->s.st_mode);
}
