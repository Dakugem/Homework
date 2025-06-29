#include "fsyslib.h"

namespace FILESYSTEM
{
    File::File(const std::string path, std::ios::openmode mode) : path{path}
    {
        file.open(path, mode);

        if (!file.is_open())
        {
            throw file_exception{"Failed to open file: " + path};
        }
    }

    std::string File::readLine()
    {
        std::string line;

        if (!std::getline(file, line))
        {
            if (file.eof())
            {
                throw file_exception{"End of file reached: " + path};
            }
            else
            {
                throw file_exception{"Failed to read file: " + path};
            }
        }

        return line;
    }

    void File::writeLine(const std::string line)
    {
        file << line;

        if (!file)
        {
            throw file_exception{"Failed to write to file: " + path};
        }
    }

    File::~File()
    {
        if (file.is_open())
            file.close();
    }
}