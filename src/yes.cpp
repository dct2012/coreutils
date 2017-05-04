#include <iostream>

int main(int argc, char *argv[])
{
    while(1) {
        if(argc == 1)
            std::cout << "y";
        else
            for(int i = 1; i < argc; i++)
                std::cout << argv[i] << " ";
        std::cout << "\n";
    }

    return 0;
}
