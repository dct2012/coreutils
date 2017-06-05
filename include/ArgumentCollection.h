#include <string>
#include <map>
#include <vector>

class ArgumentCollection
{
    protected:
        std::map<std::string, std::map<std::string, std::string>> arguments;
        std::vector<std::string> extras;

        void parseCommandLineArguments(int, char**);
        void updateArgument(std::string, std::string);
        std::map<std::string, std::string>* getArgument(std::string);
        bool hasParsableOption(std::map<std::string, std::string>*, int, int, char**);

    public:
        ArgumentCollection(int, char**, std::map<std::string, std::map<std::string, std::string>>);
        std::string getArgumentValue(std::string);
        std::vector<std::string> getExtras();
};
