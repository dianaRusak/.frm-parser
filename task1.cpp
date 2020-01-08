#pragma once

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <sys/stat.h>
#include <cstring>
#include <ctime>
#include "task1.h"

//#if defined(__WIN64)
//#define OS = 1
//#elif defined(__linux__)
//#define OS = 0
//#endif

bool myFrm::Task1::isFrm(std::string f) {
    file_path = std::move(f);
    extension = file_path.substr(file_path.rfind('\\') + 1);
    extension = extension.substr(extension.rfind('.') + 1);
    if (extension == "frm") {
        infoFile();
        whatInFrm();
    }
    return extension == "frm";
}

void myFrm::Task1::whatInFrm() {
    unsigned char temp = 0;
    char temp_ch;
    std::vector<unsigned char> v01;
    std::vector<std::vector<unsigned char>> v0;
    if (extension == "frm") {
        std::ifstream ifile(file_path, std::ios::binary | std::ios::out);
        if (!ifile) {
            std::cout << "ops" << std::endl;
        }
    }
    std::string command = std::string("mysqlfrm --diagnostic ") + file_path;
    system(command.c_str());
}

void myFrm::Task1::infoFile() {
    struct stat fileInfo;
    if (stat(file_path.c_str(), &fileInfo) != 0) {  // Use stat() to get the info
        std::cerr << "Error: " << strerror(errno) << '\n';
    }
    std::cout << "Info about the file: " << '\n';
    std::cout << "Type:         : ";
    if ((fileInfo.st_mode & S_IFMT) == S_IFDIR) { // From sys/types.h
        std::cout << "Directory\n";
    } else {
        std::cout << "File\n";
    }

    std::cout << "Size          : " <<
              fileInfo.st_size << '\n';
    std::cout << "Created       : " <<
              std::ctime(&fileInfo.st_ctime);
    std::cout << "Modified      : " <<
              std::ctime(&fileInfo.st_mtime);
    std::cout << "Accessed      : " <<
              std::ctime(reinterpret_cast<const time_t *>(&fileInfo.st_atim));
}
