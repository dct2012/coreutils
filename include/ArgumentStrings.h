#include "ArgumentBase.h"
#include <string>

class ArgumentStrings : ArgumentBase
{
    protected:
        std::string* value;

    public:
        ArgumentStrings(std::string, std::string, std::string*);
        std::string* getValue();
};
