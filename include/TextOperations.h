#include <string>
#include <vector>

namespace TextOperations
{
    void echo(int, char**);
    std::vector<std::string> explode(const std::string&, const char);
    std::string implode(const std::vector<std::string>, const char);
    mode_t octalToModeT(std::string perm);
    mode_t symbolicToModeT(std::string perm);
    int stringToInt(const std::string& string);
}
