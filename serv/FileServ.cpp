//
// Created by Alex on 12.04.2021.
//

#include <direct.h>
#include "FileServ.h"

FileServ::FileServ(Controller* serv)
{
    this->serv = serv;
}

void FileServ::backupEverything()
{
    std::ofstream fout;
    std::string appdata = getenv("appdata");
    fout.open(appdata);
    fout << this->serv->nextId << "\n" << this->serv->repo;
    fout.close();
}

void FileServ::restoreEverything()
{
    std::ifstream fin;
    char* a = getenv("appdata");
    strcat(a, "\\Trench Coat Store");
    mkdir(a);
    strcat(a, "\\trenchCoats.txt");
    fin.open(a);
    fin >> this->serv->nextId >> this->serv->repo;
    fin.close();
}