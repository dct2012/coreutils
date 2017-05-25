#include <unistd.h>
#include <string>

namespace FileOperations
{
    ssize_t filecopy(char*, char*);
    std::string cat(char*);
    bool isDirectory(char*);
    bool pathExists(const char*);
    void makedir(const char*, mode_t, bool);
    void makedirp(const char *, mode_t, bool);
}
