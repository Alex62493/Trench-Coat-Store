//
// Created by Alex on 23.05.2021.
//

#ifndef A89_ALEX62493_LOGINGUI_H
#define A89_ALEX62493_LOGINGUI_H
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class LoginGUI : public QWidget{
    Q_OBJECT

private:
    QPushButton* admin;
    QPushButton* user;
public:
    explicit LoginGUI(QWidget* parent);

signals:
    void startAdminSignal();
    void startUserSignal();

private slots:
    void adminButtonHandler();
    void userButtonHandler();
};


#endif //A89_ALEX62493_LOGINGUI_H
