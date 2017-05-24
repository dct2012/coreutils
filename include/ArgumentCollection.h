#include <string>
#include <map>
#include <vector>
#include "ArgumentBase.h"

class ArgumentCollection
{
    protected:
        std::map<std::string, std::string> arguments;
        std::map<std::string, std::string> shortToLongMap;
        std::map<std::string, std::string> longToShortMap;

        void createArguments(std::vector<std::vector<std::string>>);
        void parseCommandLineArguments(int, char**);
        void createArgument(std::string, std::string, std::string);
        void updateArgument(std::string, std::string);

    public:
        ArgumentCollection(int, char**, std::vector<std::vector<std::string>>);
        std::string getArgument(std::string);
};
