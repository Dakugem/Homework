#include <fstream>
#include <string>
#include <exception>

#ifndef FILESYSTEMLIB
#define FILESYSTEMLIB

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

        std::string readLine();
        void writeLine(const std::string line);

        ~File();
    };

    // Copied from <stdexcept> and renamed to create own exception class
    class file_exception : public std::exception
    {
    public:
        using _Mybase = std::exception;

        explicit file_exception(const std::string &_Message) : _Mybase(_Message.c_str()) {}
        explicit file_exception(const char *_Message) : _Mybase(_Message) {}
    };
}

#endif