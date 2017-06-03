#include <string>
#include <vector>
#include <map>

class HelpMessage
{
    protected:
        std::string help;

    public:
        HelpMessage(std::string, std::map<std::string, std::map<std::string, std::string>>);
        std::string getHelp();
};
