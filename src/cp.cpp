#include <iostream>
#include "File.h"

int main(int argc, char *argv[])
{
    if(argc != 3) {
        puts("Print Help");
        return 1; //error
    } else {
        char* source = argv[1];
        char* destination = argv[2];

        std::cout << "Copying " << source << " to " << destination << "\n";
        File* file = new File(source, destination);
        file->copy();
    }

    return 0;
}
