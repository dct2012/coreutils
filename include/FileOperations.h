#include <unistd.h>
#include <string>
#include <vector>

namespace FileOperations
{
    ssize_t filecopy(char*, char*);
    std::string cat(char*);
    bool isDirectory(std::string);
    bool pathExists(const char*);
    void makedir(const char*, mode_t, bool);
    void makedirp(const char *, mode_t, bool);
    std::vector<std::string> getFileByLine(std::string);
}
