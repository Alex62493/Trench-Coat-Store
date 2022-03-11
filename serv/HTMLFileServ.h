//
// Created by Alex on 19.04.2021.
//

#ifndef A67_ALEX62493_HTMLFILESERV_H
#define A67_ALEX62493_HTMLFILESERV_H

#include "UserFileServ.h"

namespace polymorphism {
    class HTMLFileServ : public UserFileServ {
    public:
        HTMLFileServ(const std::string &name, Cart *cart1);
        void writeInFile();
        void openFile();
        static void split(const std::string &str, const std::string &delim, std::vector<std::string> &parts);
    };
}

#endif //A67_ALEX62493_HTMLFILESERV_H
