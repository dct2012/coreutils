#include "FileOperations.h"
#include "FileReader.h"
#include "FileCreator.h"

namespace FileOperations
{
    ssize_t filecopy(char* src, char* dst)
    {
        FileReader* source = new FileReader(src);
        FileCreator* destination = new FileCreator(dst);

        std::cout << "Copying " << src << " to " << dst << "\n";
        ssize_t written = 0;
        char *buf = new char[BUFSIZ];
        ssize_t size;

        while ((size = source->readByBytes(buf)) > 0) {
            written += destination->writeByBytes(buf, size);
        }

        std::cout << "Amount written: " << written << "\n";
        return written;
    }
}
