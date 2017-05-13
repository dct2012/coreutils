#include <string>
#include <vector>

class HelpMessage
{
    protected:
        std::string help;

    public:
        HelpMessage(std::string, std::vector<std::vector<std::string>>);
        std::string getHelp();
};
