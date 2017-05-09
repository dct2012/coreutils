#include <string>
#include "ArgumentBase.h"

class ArgumentCollection
{
    protected:
        std::map<std::string, ArgumentBase*>* arguments;
        void createArguments(std::string**);
        void createHelpMessage(std::string**);
        void parseCommandLineArguments(int, char**);

    public:
        ArgumentCollection(int, char**, std::string**);
        std::string getArgument(std::string);
};
