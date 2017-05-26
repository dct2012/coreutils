#include <iostream>
#include <sstream>
#include "TextOperations.h"

namespace TextOperations
{
    void echo(int length, char** string)
    {
        for(int i = 1; i < length; i++) {
            std::cout << string[i];;
            if(i + 1 != length) //place space between strings
                std::cout << " ";
        }
        std::cout << "\n";
    }

    std::vector<std::string> explode(std::string const& string, const char delim)
    {
        std::vector<std::string> result;
        std::istringstream iss(string);

        for (std::string token; std::getline(iss, token, delim); ) {
            result.push_back(std::move(token));
        }

        return result;
    }

    std::string implode(const std::vector<std::string> string, const char delim)
    {
        std::string result;
        int delimCount = string.size() - 1;
        for (int i = 0; i <= delimCount; i++) {
            result += string[i] + (i < delimCount ? delim : '\0');
        }

        return result;
    }
}
