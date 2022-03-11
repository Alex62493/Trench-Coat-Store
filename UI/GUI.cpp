//
// Created by Alex on 23.05.2021.
//

#include "GUI.h"

GUI::GUI(DataBase* db, Controller* serv, FileServ* fileServ, QWidget* parent) {
    this->login = new LoginGUI(this);
    this->show();
    this->adminGUI = new AdminGUI(serv, fileServ, this);
    this->userGUI = new UserGUI(db, "AF", fileServ, this);
}

void GUI::startAdmin() {
    this->login->close();
    this->adminGUI->show();
}

void GUI::startUser() {
    this->login->close();
    this->userGUI->show();
}
