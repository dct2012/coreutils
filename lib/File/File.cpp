#include "File.h"

File::File(char* source,  char* destination)
{
    try {
        this->source = open(source, O_RDONLY, 0);
        this->destination = open(destination, O_WRONLY | O_CREAT, 0644);
    }
    catch(int e){
        std::cout << "File Constructor Failed: " << e << "\n";
    }
}

File::~File()
{
    close(this->source);
    close(this->destination);
}

ssize_t File::copy()
{
    ssize_t written = 0;

    while ((this->size = read(this->source, this->buf, BUFSIZ)) > 0) {
        written += write(this->destination, this->buf, this->size);
    }

    std::cout << "Amount written: " << written << "\n";
    return written;
}
