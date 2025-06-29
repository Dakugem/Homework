#include "fsyslib.h"
#include <iostream>

using namespace FILESYSTEM;

int main(){
    File file{"fsyslib.cpp"};

    std::string line = "Line\nLine\nLine";
    std::cout << line << std::endl;
    system("pause");
    return 0;
}