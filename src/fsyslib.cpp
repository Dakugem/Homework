#include "fsyslib.h"

namespace FILESYSTEM
{
    File::File(const std::string path, std::ios::openmode mode) : path{path}
    {
        file.open(path, mode);

        if (!file.is_open())
        {
            throw std::ios_base::failure{"Failed to open file: " + path};
        }
    }

    std::string File::readLine()
    {
        std::string line;

        if (!std::getline(file, line))
        {
            if (file.eof())
            {
                throw std::ios_base::failure{"End of file reached: " + path};
            }
            else
            {
                throw std::ios_base::failure{"Failed to read file: " + path};
            }
        }

        return line;
    }

    void File::writeLine(const std::string line)
    {
        file << line;

        if (!file)
        {
            throw std::ios_base::failure{"Failed to write to file: " + path};
        }
    }

    File::~File()
    {
        if (file.is_open())
            file.close();
    }
}