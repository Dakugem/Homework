#include <fstream>
#include <string>
#include <stdexcept>

#ifndef FILESYSTEMLIB
#define FILESYSTEMLIB

//Проверочный комментарий
namespace FILESYSTEM
{
    class File
    {
        std::fstream file;
        std::string path;

    public:
        // Opened with in/out mode by default
        File(const std::string path,
             std::ios::openmode mode = std::ios::in | std::ios::out);
        //Delete copy constructor
        File(const File&) = delete;
        //Delete assignment constructor
        File& operator=(const File&) = delete;

        std::string readLine();
        void writeLine(const std::string line);

        ~File();
    };
}

#endif