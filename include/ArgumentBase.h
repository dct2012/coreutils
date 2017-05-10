#include <string>

class ArgumentBase
{
    protected:
        std::string shortOption;
        std::string longOption;
        bool value;

    public:
        ArgumentBase(std::string, std::string, bool);
        bool getValue();
};
