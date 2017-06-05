#include "HelpMessage.h"
#include "ArgumentCollection.h"

class Command
{
    protected:
        HelpMessage* help;
        ArgumentCollection* arguments;

    public:
        Command(int, char**, std::string, std::map<std::string, std::map<std::string, std::string>>);
        void printHelpMessage();
        void printVersion();
        virtual void run(int) = 0;
};
