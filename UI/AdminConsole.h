//
// Created by Alex on 22.03.2021.
//
#include "../serv/Controller.h"
#include <iostream>
#include <string>
#include "../serv/FileServ.h"

#ifndef A45_ALEX62493_CONSOLE_H
#define A45_ALEX62493_CONSOLE_H


class AdminConsole {
private:
    Controller* serv;
    FileServ* fileServ;

public:
    AdminConsole(Controller* d, FileServ *fs);
    ~AdminConsole();
    void start();

private:
    static void printMenu();
    void addElement();
    void updateElement();
    void removeElement();
    void printAll();
};


#endif //A45_ALEX62493_CONSOLE_H
