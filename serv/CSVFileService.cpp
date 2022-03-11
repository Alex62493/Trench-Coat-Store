//
// Created by Alex on 19.04.2021.
//

#include "CSVFileService.h"

namespace polymorphism{
    CSVFileService::CSVFileService(const std::string &name, Cart *cart1) : UserFileServ(name, cart1) {
    }

    void CSVFileService::openFile()
    {
        ShellExecuteA(nullptr, nullptr, "scalc.exe", this->fileName.c_str(), nullptr, SW_SHOWMAXIMIZED);
    }

    void CSVFileService::writeInFile()
    {
        this->file.close();
        this->file.open(this->fileName);

        int i;
        std::vector<std::string> all = this->cart->getPrintList(i);
        for (std::string s : all)
        {
            std::replace(s.begin(), s.end(), '\t', ';');
            this->file << s << std::endl;
        }
    }
}