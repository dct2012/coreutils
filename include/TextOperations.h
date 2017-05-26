#include <string>
#include <vector>

namespace TextOperations
{
    void echo(int, char**);
    std::vector<std::string> explode(std::string const&, const char);
    std::string implode(const std::vector<std::string>, const char);
}
