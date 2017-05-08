#include "FileOperations.h"
#include "FileReader.h"
#include "FileCreator.h"
#include "FileStat.h"

namespace FileOperations
{
    ssize_t filecopy(char* src, char* dst)
    {
        FileReader* source = new FileReader(src);
        FileCreator* destination = new FileCreator(dst);

        std::cout << "Copying " << src << " to " << dst << std::endl;
        ssize_t written = 0;
        char *buf = new char[BUFSIZ];
        ssize_t size;

        while ((size = source->readByBytes(buf)) > 0) {
            written += destination->writeByBytes(buf, size);
        }

        std::cout << "Amount written: " << written << std::endl;
        return written;
    }

    std::string cat(char* src)
    {
        FileReader* source = new FileReader(src);
        char *buf = new char[BUFSIZ];
        ssize_t size;
        std::string out;

        while ((size = source->readByBytes(buf)) > 0) {
            out += buf;
        }

        return out;
    }

    bool isDirectory(char* src)
    {
        try {
            FileStat* fs = new FileStat(src);
            return fs->isDirectory();
        }
        catch(std::exception& e) {
            std::cerr << "Error!! FileOperations::isDirectory: " << e.what() << std::endl;
        }

        return false;
    }
}
