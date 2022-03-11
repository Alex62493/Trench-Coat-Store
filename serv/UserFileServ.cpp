//
// Created by Alex on 19.04.2021.
//

#include "UserFileServ.h"

namespace polymorphism{
    UserFileServ::UserFileServ(const std::string& name, Cart* cart1)
    {
        this->fileName = "C:/Users/Alex/Documents/GitHub/a89-Alex62493/";
        this->fileName.append(name);
        this->cart = cart1;
        this->file.open(this->fileName);
    }

    UserFileServ::~UserFileServ()
    {
        this->file.close();
    }

    void UserFileServ::openFile()
    {
        ShellExecuteA(nullptr, nullptr, "notepad.exe", this->fileName.c_str(), nullptr, SW_SHOWMAXIMIZED);
    }

    void UserFileServ::writeInFile()
    {
        this->file << "This shouldn't happen!";
    }
}