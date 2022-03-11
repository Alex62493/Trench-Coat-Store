//
// Created by Alex on 23.05.2021.
//

#ifndef A89_ALEX62493_ADMINGUI_H
#define A89_ALEX62493_ADMINGUI_H
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <../serv/Controller.h>
#include <FileServ.h>

class AdminGUI : public QWidget{
    Q_OBJECT

public:
    AdminGUI(Controller* serv, FileServ* fileServ, QWidget* parent);

private:
    Controller* serv;
    FileServ* fileServ;
    QListWidget* coats;
    QLabel* sizeLabel;
    QLabel* colourLabel;
    QLabel* priceLabel;
    QLabel* quantityLabel;
    QLabel* photoLabel;
    QLineEdit* id;
    QLineEdit* size;
    QLineEdit* colour;
    QLineEdit* price;
    QLineEdit* quantity;
    QLineEdit* photo;
    QPushButton* add;
    QPushButton* remove;
    QPushButton* update;

private:
    void populateTrenchCoats();
    void listItemChanged();
    int getSelectedIndex();

signals:
    void CoatsUpdateSignal();
    void addCoatSignal(std::string size, std::string colour, double price, int quantity, std::string photo);
    void removeCoatSignal(int id);
    void updateCoatSignal(int id, std::string size, std::string colour, double price, int quantity, std::string photo);

public slots:
    void addCoatButtonHandler();
    void removeCoatButtonHandler();
    void updateCoatButtonHandler();
    void addCoat(std::string size, std::string colour, double price, int quantity, std::string photo);
    void removeCoat(int id);
    void updateCoat(int id, std::string size, std::string colour, double price, int quantity, std::string photo);
};


#endif //A89_ALEX62493_ADMINGUI_H
