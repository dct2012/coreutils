#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class FileStat
{
    private:
        struct stat s;

    public:
        FileStat(const char*);
        bool isDirectory();
};
