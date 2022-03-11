//
// Created by Alex on 12.04.2021.
//

#include "FileServ.h"

FileServ::FileServ(Controller* serv)
{
    this->serv = serv;
}

void FileServ::backupEverything()
{
    std::ofstream fout;
    std::string appdata = getenv("appdata");
    appdata += "\\Trench Coat Store\\trenchCoats.txt";
    fout.open(appdata);
    fout << this->serv->nextId << "\n" << this->serv->repo;
    fout.close();
}

void FileServ::restoreEverything()
{
    std::ifstream fin;
    std::string appdata = getenv("appdata");
    appdata += "\\Trench Coat Store\\trenchCoats.txt";
    fin.open(appdata);
    fin >> this->serv->nextId >> this->serv->repo;
    fin.close();
}