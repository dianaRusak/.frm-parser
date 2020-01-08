#pragma once

#include <string>

namespace myFrm {
    class  Task1{
        public:
            bool isFrm(std::string f);
            void whatInFrm();
            void infoFile();

    private:
        std::string extension;
        std::string file_path;
    };
};

