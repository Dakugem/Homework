#include <filesystem>

#ifndef FILESYSTEMLIB
#define FILESYSTEMLIB

namespace FILESYSTEM{
    class File{
    public:
        File(std::filesystem::path path);

        std::string readLine();
        void writeLine();

        ~File();
    };
}

#endif