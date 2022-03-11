//
// Created by Alex on 12.04.2021.
//

#ifndef A45_ALEX62493_FILESERV_H
#define A45_ALEX62493_FILESERV_H
#include "Controller.h"
#include <iostream>
#include <fstream>

class FileServ {
    friend class Controller;

private:
    Controller* serv;

public:
    explicit FileServ(Controller* serv);
    void backupEverything();
    void restoreEverything();
};


#endif //A45_ALEX62493_FILESERV_H
