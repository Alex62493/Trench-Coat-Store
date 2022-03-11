//
// Created by Alex on 19.04.2021.
//

#ifndef A67_ALEX62493_USERFILESERV_H
#define A67_ALEX62493_USERFILESERV_H

#include <string>
#include <fstream>
#include <Windows.h>
#include <shellapi.h>
#include "../repo/Cart.h"

namespace polymorphism {
    class UserFileServ {

    protected:
        std::string fileName;
        Cart* cart;
        std::ofstream file;

    public:
        UserFileServ(const std::string& name, Cart* cart1);
        virtual ~UserFileServ();
        virtual void writeInFile();
        virtual void openFile();
    };
}

#endif //A67_ALEX62493_USERFILESERV_H
