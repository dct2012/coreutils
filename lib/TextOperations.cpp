#include <iostream>
#include <sstream>
#include "TextOperations.h"

#include <sys/stat.h>

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

    mode_t stringToModeT(std::string perm)
    {
        //TODO: make decision on string mode representation, for now assuming octal
        return octalToModeT(perm);
    }

    mode_t symbolicToModeT(std::string perm)
    {
        mode_t mode = 0;

        if (perm[0] == 'r')
            mode |= S_IRUSR;
        if (perm[1] == 'w')
            mode |= S_IWUSR;
        if (perm[2] == 'x')
            mode |= S_IXUSR;
        if (perm[3] == 'r')
            mode |= S_IRGRP;
        if (perm[4] == 'w')
            mode |= S_IWGRP;
        if (perm[5] == 'x')
            mode |= S_IXGRP;
        if (perm[6] == 'r')
            mode |= S_IROTH;
        if (perm[7] == 'w')
            mode |= S_IWOTH;
        if (perm[8] == 'x')
            mode |= S_IXOTH;

         return mode;
    }

    mode_t octalToModeT(std::string perm)
    {
        mode_t mode = 0L;

        switch (perm[perm.length() - 1]) {
            case '7':
                mode |= S_IRWXO; // read, write, execute/search by others
                break;
            case '6':
                mode |= S_IROTH | S_IWOTH;
                break;
            case '5':
                mode |= S_IROTH | S_IXOTH;
                break;
            case '4':
                mode |= S_IROTH;
                break;
            case '3':
                mode |= S_IWOTH | S_IXOTH;
                break;
            case '2':
                mode |= S_IWOTH;
                break;
            case '1':
                mode |= S_IXOTH;
                break;
        }

        switch (perm[perm.length() - 2]) {
            case '7':
                mode |= S_IRWXG;
                break;
            case '6':
                mode |= S_IRGRP | S_IWGRP;;
                break;
            case '5':
                mode |= S_IRGRP | S_IXGRP;
                break;
            case '4':
                mode |= S_IRGRP;
                break;
            case '3':
                mode |= S_IWGRP | S_IXGRP;
                break;
            case '2':
                mode |= S_IWGRP;
                break;
            case '1':
                mode |= S_IXGRP;
                break;
        }

        switch (perm[perm.length() - 3]) {
            case '7':
                mode |= S_IRWXU;
                break;
            case '6':
                mode |= S_IRUSR | S_IWUSR;
                break;
            case '5':
                mode |= S_IRUSR | S_IXUSR;
                break;
            case '4':
                mode |= S_IRUSR;
                break;
            case '3':
                mode |= S_IWUSR | S_IXUSR;
                break;
            case '2':
                mode |= S_IWUSR;
                break;
            case '1':
                mode |= S_IXUSR;
                break;
        }

        // S_ISUID
        // set-user-ID on execution
        // S_ISGID
        // set-group-ID on execution
        // S_ISVTX
        // on directories, restricted deletion flag

        return mode;
    }
}
