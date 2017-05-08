#include <unistd.h>
#include <string>

namespace FileOperations
{
  ssize_t filecopy(char*, char*);
  std::string cat(char*);
  bool isDirectory(char*);
}
