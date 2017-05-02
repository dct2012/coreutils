#include <iostream>
#include "FileReader.h"
#include "FileCreator.h"

int main(int argc, char *argv[])
{
    if(argc != 3) {
        puts("Print Help");
        return 1; //error
    } else {
        FileReader* source = new FileReader(argv[1]);
        FileCreator* destination = new FileCreator(argv[2]);

        std::cout << "Copying " << argv[1] << " to " << argv[2] << "\n";
        ssize_t written = 0;
        char *buf = new char[BUFSIZ];
        ssize_t size;

        while ((size = source->readByBytes(buf)) > 0) {
            written += destination->writeByBytes(buf, size);
        }

        std::cout << "Amount written: " << written << "\n";
        return written;
    }

    return 0;
}
