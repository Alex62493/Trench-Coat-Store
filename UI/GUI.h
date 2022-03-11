//
// Created by Alex on 23.05.2021.
//

#ifndef A89_ALEX62493_GUI_H
#define A89_ALEX62493_GUI_H
#include <qwidget.h>
#include "../serv/UserServ.h"
#include "../serv/Controller.h"
#include "AdminGUI.h"
#include "LoginGUI.h"
#include "UserGUI.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <FileServ.h>

class GUI : public QWidget{
    Q_OBJECT

private:
    AdminGUI* adminGUI;
    UserGUI* userGUI;
    LoginGUI* login;

public:
    explicit GUI(DataBase* db, Controller* serv, FileServ* fileServ, QWidget* parent = 0);

public slots:
    void startAdmin();
    void startUser();
};


#endif //A89_ALEX62493_GUI_H
