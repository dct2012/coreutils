#include <string>
#include <vector>

namespace TextOperations
{
    void echo(int, char**);
    std::vector<std::string> explode(const std::string&, const char);
    std::string implode(const std::vector<std::string>, const char);
    mode_t stringToModeT(std::string);
    mode_t octalToModeT(std::string);
    mode_t symbolicToModeT(std::string);
}
