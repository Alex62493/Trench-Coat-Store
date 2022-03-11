//
// Created by Alex on 03.06.2021.
//

#ifndef A89_ALEX62493_COATTABLE_H
#define A89_ALEX62493_COATTABLE_H
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QAbstractTableModel>
#include <../serv/Controller.h>
#include "../serv/UserServ.h"
#include "../repo/DataBase.h"
#include "../repo/Cart.h"
#include "../serv/HTMLFileServ.h"
#include "../serv/CSVFileService.h"
#include "../serv/UserFileServ.h"

class CoatModel : public QAbstractTableModel {
    Q_OBJECT
    std::vector<std::string> trenchCoats;
    QList<std::vector<std::string>> m_data;

public:
    explicit CoatModel(QObject * parent);
    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void updateVector(std::vector<std::string> newCoats);
};
#endif //A89_ALEX62493_COATTABLE_H
