#include "ArgumentBase.h"
#include <string>

class ArgumentString : ArgumentBase
{
    protected:
        std::string value;

    public:
        ArgumentString(std::string, std::string, std::string);
        std::string getValue();
};
