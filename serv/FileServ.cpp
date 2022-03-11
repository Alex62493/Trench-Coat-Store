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
    fout.open("C:/Users/Alex/Documents/GitHub/a89-Alex62493/trenchCoats.txt");
    fout << this->serv->nextId << "\n" << this->serv->repo;
    fout.close();
}

void FileServ::restoreEverything()
{
    std::ifstream fin;
    fin.open("C:/Users/Alex/Documents/GitHub/a89-Alex62493/trenchCoats.txt");
    fin >> this->serv->nextId >> this->serv->repo;
    fin.close();
}