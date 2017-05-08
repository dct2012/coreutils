#include <iostream>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t now;
    time(&now);
    std::cout << ctime(&now);

    exit(EXIT_SUCCESS);
}
