#include "fsyslib.h"
#include <iostream>

namespace FILESYSTEM{
    File::File(std::filesystem::path path){
        file = std::fstream{path, std::ios::in || std::ios::out};
        if(file.is_open()){
            std::cout << "File "  << path << " opened" << std::endl;
        }else{
            std::cout << "File "  << path << " don't opened" << std::endl;
        }
    }



    File::~File(){
        //file.close();
    }
}