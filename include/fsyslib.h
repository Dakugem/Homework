#include <filesystem>
#include <fstream>

#ifndef FILESYSTEMLIB
#define FILESYSTEMLIB

namespace FILESYSTEM{
    class File{
        std::fstream file;
    public:
        File(std::filesystem::path path);

        std::string readLine();
        void writeLine(const std::string line);

        ~File();
    };
}

#endif