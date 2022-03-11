//
// Created by Alex on 03.06.2021.
//

#ifndef A89_ALEX62493_USERGUI_H
#define A89_ALEX62493_USERGUI_H

#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QTableView>
#include <../serv/Controller.h>
#include <FileServ.h>
#include "../serv/UserServ.h"
#include "../repo/DataBase.h"
#include "../repo/Cart.h"
#include "../serv/HTMLFileServ.h"
#include "../serv/CSVFileService.h"
#include "../serv/UserFileServ.h"
#include "CoatTable.h"

class UserGUI : public QWidget{
Q_OBJECT
public:
    UserGUI(DataBase* db, const std::string& fileType, FileServ* fileDB, QWidget* parent);

private:
    std::vector<std::string> trenchCoats;
    FileServ* fileDB;
    UserServ* serv;
    polymorphism::UserFileServ* fileServ;
    QListWidget* coats;
    QLabel* filterLabel;
    QLabel* sizeLabel;
    QLabel* colourLabel;
    QLabel* priceLabel;
    QLabel* quantityLabel;
    QLabel* photoLabel;
    QLabel* totalPriceLabel;
    QLineEdit* filter;
    QLineEdit* id;
    QLineEdit* size;
    QLineEdit* colour;
    QLineEdit* price;
    QLineEdit* quantity;
    QLineEdit* photo;
    QLineEdit* totalPrice;
    QPushButton* add;
    QPushButton* ss;
    QPushButton* buy;
    QPushButton* filterButton;
    QTableView m_view;
    CoatModel m_model{this};


private:
    void populateTrenchCoats();
    void listItemChanged();
    int getSelectedIndex();

signals:
    void CoatsUpdateSignal();

public slots:
    void addButtonHandler();
    void showButtonHandler();
    void buyButtonHandler();
    void filterButtonHandler();
};


#endif //A89_ALEX62493_USERGUI_H
