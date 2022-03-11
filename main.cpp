//
// Created by Alex on 20.03.2021.
//

#define _CRTDBG_MAP_ALLOC

#include "domain/DynamicArray.h"
#include "repo/DataBase.h"
#include "serv/Controller.h"
#include "UI/AdminConsole.h"
#include "UI/UserConsole.h"
#include "serv/FileServ.h"
#include "UI/GUI.h"

#include <cstdlib>
#include <crtdbg.h>
#include "tests/Tests.h"
#include <cstring>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    auto* d = new Tests;
    d->testAll();

    std::vector<TrenchCoat*> adminList;
    auto* adminRepo = new DataBase(adminList);
    auto* adminServ = new Controller(adminRepo);
    auto* fileServ = new FileServ(adminServ);
    auto* adminConsole = new AdminConsole(adminServ, fileServ);
    fileServ->restoreEverything();

    /*
    bool exit = false;
    while (!exit)
    {
        std::cout << "\tadmin - admin mode\n";
        std::cout << "\tuser - user mode\n";
        std::cout << "\texit - exit the app\n";
        std::cout << ">>>";

        std::string command;
        std::cin >> command;
        std::cout << "\n";

        if (command == "admin")
        {
            adminConsole->start();
        }
        else if (command == "user")
        {
            bool right = false;
            std::string fileType;
            while (!right)
            {
                std::cout << "Please enter the type of file you want to use: ";
                std::cin >> fileType;
                std::cout << "\n";

                if (fileType == "csv" || fileType == "html")
                    right = true;
            }

            auto* userConsole = new UserConsole(adminRepo, fileType);
            userConsole->start();
            delete userConsole;
        }
        else if (command == "exit")
        {
            exit = true;
            std::cout << "Goodbye!\n";
        }
        else
        {
            std::cout << "Wrong command!\n";
        }
    }
    */
    _CrtDumpMemoryLeaks();
    QApplication a(argc, argv);
    GUI g(adminRepo, adminServ, fileServ);
    g.show();
    fileServ->backupEverything();
    delete d;
    return a.exec();
    //return 0;
}
