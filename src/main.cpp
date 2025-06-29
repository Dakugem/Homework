#include "fsyslib.h"
#include <iostream>

using namespace FILESYSTEM;

int main()
{
    File log{"log.txt", std::ios::out};
    //Write to file test
    try
    {
        File file{"text.txt", std::ios::out};
        std::string line{"Line\nLine\nLine\n\n"};
        file.writeLine(line);

        log.writeLine("Write line to the file text.txt:\n");
        log.writeLine(line);
    }
    catch (const std::exception &e)
    {
        log.writeLine("Error ocured while write test: ");
        log.writeLine(e.what());
        log.writeLine("\n\n");
    }

    //Read from file test
    try
    {
        File file{"text.txt", std::ios::in};

        log.writeLine("Read from the file text.txt:\n");
        std::string line;
        while(true){
            line = file.readLine();
            std::cout << line << std::endl;
            log.writeLine(line);
            log.writeLine("\n");
        }
    }
    catch (const std::exception &e)
    {
        log.writeLine("Error ocured while read test: ");
        log.writeLine(e.what());
        log.writeLine("\n\n");
    }

    //Read exception test
    try
    {
        File file{"nonefile.txt", std::ios::in};

        while(true){
            std::cout << file.readLine() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        log.writeLine("Try to read from non-existent file.\n");
        log.writeLine("Error ocured while read exception test: ");
        log.writeLine(e.what());
        log.writeLine("\n\n");
    }

    //Write exception test
    try
    {
        File file{"text.txt", std::ios::in};

        file.writeLine("This line will not be written to the file because it is open for reading\n");
    }
    catch (const std::exception &e)
    {
        log.writeLine("Now try write line to a file opened with only read mode.\n");
        log.writeLine("Error ocured while write exception test: ");
        log.writeLine(e.what());
        log.writeLine("\n\n");
    }
    
    return 0;
}