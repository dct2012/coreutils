#include <string>

class HelpMessage
{
    protected:
        std::string help;

    public:
        HelpMessage(std::string, std::string*);
        std::string getHelp();
};
