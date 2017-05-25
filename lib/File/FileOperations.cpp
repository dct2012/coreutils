#include "FileOperations.h"
#include "FileReader.h"
#include "FileCreator.h"
#include "FileStat.h"

namespace FileOperations
{
    ssize_t filecopy(char* src, char* dst)
    {
        FileReader* source = new FileReader(src);
        FileCreator* destination = new FileCreator(dst);

        std::cout << "Copying " << src << " to " << dst << std::endl;
        ssize_t written = 0;
        char *buf = new char[BUFSIZ];
        ssize_t size;

        while ((size = source->readByBytes(buf)) > 0) {
            written += destination->writeByBytes(buf, size);
        }

        std::cout << "Amount written: " << written << std::endl;
        return written;
    }

    std::string cat(char* src)
    {
        FileReader* source = new FileReader(src);
        char *buf = new char[BUFSIZ];
        ssize_t size;
        std::string out;

        while ((size = source->readByBytes(buf)) > 0) {
            out += buf;
        }

        return out;
    }

    bool isDirectory(char* src)
    {
        try {
            FileStat* fs = new FileStat(src);
            return fs->isDirectory();
        }
        catch(std::exception& e) {
            std::cerr << "Error!! FileOperations::isDirectory: " << e.what() << std::endl;
        }

        return false;
    }

    bool pathExists(const char *dir)
    {
        try {
            new FileStat(dir);
            return true;
        } catch(int e){
            return false;
        }
    }

    void makedir(const char* dir, mode_t mode, bool vflag)
    {
        if(pathExists(dir)) {
            throw std::string("mkdir: cannot create directory ") + dir + ", file exists";
        }

        if(mkdir(dir, mode) == -1) {
            throw std::string("mkdir: cannot create directory ") + dir + ", c mkdir() failed";
        }

        if(vflag) {
            std::cout << "mkdir: created directory " << dir << std::endl;
        }
    }

    void makedirp(const char *dir, mode_t mode, bool vflag)
    {
        //if directory exists leave
        if(pathExists(dir)) {
            return;
        }

        makedir(dir, mode, vflag);

        int i;
        for(i = std::string(dir).length(); i >= 0; i--) {
            if(dir[i] == '/') {
                break;
            }
        }

        makedirp(std::string(dir).substr(0, i).c_str(), mode, vflag);

        makedirp(dir, mode, vflag);
    }
}
