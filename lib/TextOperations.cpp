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

    std::vector<std::string> explode(const std::string& string, const char delim)
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

    int stringToInt(const std::string& string)
    {
        //TODO: make decision on string mode representation, for now assuming octal
        return octalToModeT(string);
    }

    mode_t octalToModeT(std::string perm)
    {
        mode_t mode = 0;
        int length = perm.length();
        for(int i = 0, power = length; i < length; i++, power--) {
            mode |= perm[i] * (10 ^ power);
        }
        std::cout << "TextOperations::octalToModeT() return value = " << mode << std::endl;
        return mode;
    }

    mode_t symbolicToModeT(std::string perm)
    {
        mode_t mode = 0;

        if (perm[0] == 'r')
            mode |= 0400;
        if (perm[1] == 'w')
          mode |= 0200;
        if (perm[2] == 'x')
          mode |= 0100;
        if (perm[3] == 'r')
          mode |= 0040;
        if (perm[4] == 'w')
          mode |= 0020;
        if (perm[5] == 'x')
          mode |= 0010;
        if (perm[6] == 'r')
          mode |= 0004;
        if (perm[7] == 'w')
          mode |= 0002;
        if (perm[8] == 'x')
          mode |= 0001;

         return mode;
    }

    mode_t stringToModeT(std::string perm)
    {
        mode_t mode = 0;

        return mode;
    }
}
