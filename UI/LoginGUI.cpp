//
// Created by Alex on 23.05.2021.
//

#include "LoginGUI.h"

LoginGUI::LoginGUI(QWidget *parent) {
    setParent(parent);
    auto* layout = new QVBoxLayout{this};

    const QSize s = QSize(625, 225);
    const QFont f = QFont("Times New Roman", 50, 30, false);
    this->admin = new QPushButton("Login as &Admin");
    this->user = new QPushButton("Login as &User");
    this->admin->setFixedSize(s);
    this->user->setFixedSize(s);
    this->admin->setFont(f);
    this->user->setFont(f);
    layout->addWidget(this->admin);
    layout->addWidget(this->user);

    QObject::connect(this->admin, &QPushButton::clicked, this, &LoginGUI::adminButtonHandler);
    QObject::connect(this->user, &QPushButton::clicked, this, &LoginGUI::userButtonHandler);

    QObject::connect(this, SIGNAL(startAdminSignal()), this->parentWidget(), SLOT(startAdmin()));
    QObject::connect(this, SIGNAL(startUserSignal()), this->parentWidget(), SLOT(startUser()));
}

void LoginGUI::adminButtonHandler()
{
    emit startAdminSignal();
}

void LoginGUI::userButtonHandler() {
    emit startUserSignal();
}