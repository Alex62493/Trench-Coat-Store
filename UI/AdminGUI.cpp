//
// Created by Alex on 23.05.2021.
//

#include "AdminGUI.h"

#include <utility>

AdminGUI::AdminGUI(Controller* serv, FileServ* fileServ, QWidget* parent) {
    setParent(parent);
    this->serv = serv;
    this->fileServ = fileServ;
    auto* layout = new QHBoxLayout{this};

    this->coats = new QListWidget{};
    this->coats->setSelectionMode(QAbstractItemView::SingleSelection);
    layout->addWidget(this->coats);

    //right
    auto* rSide = new QWidget;
    auto* rLayout = new QHBoxLayout{rSide};
    auto* fields = new QWidget;
    auto fieldsLayout = new QVBoxLayout{fields};
    auto* buttons = new QWidget;
    auto* buttonsLayout = new QVBoxLayout{buttons};

    //fields
    this->sizeLabel = new QLabel("Size:");
    this->size = new QLineEdit;
    this->sizeLabel->setBuddy(this->size);
    fieldsLayout->addWidget(this->sizeLabel);
    fieldsLayout->addWidget(this->size);

    this->colourLabel = new QLabel("Colour:");
    this->colour = new QLineEdit;
    this->colourLabel->setBuddy(this->colour);
    fieldsLayout->addWidget(this->colourLabel);
    fieldsLayout->addWidget(this->colour);

    this->priceLabel = new QLabel("Price:");
    this->price = new QLineEdit;
    this->priceLabel->setBuddy(this->price);
    fieldsLayout->addWidget(this->priceLabel);
    fieldsLayout->addWidget(this->price);


    this->quantityLabel = new QLabel("Quantity:");
    this->quantity = new QLineEdit;
    this->quantityLabel->setBuddy(this->quantity);
    fieldsLayout->addWidget(this->quantityLabel);
    fieldsLayout->addWidget(this->quantity);


    this->photoLabel = new QLabel("Photograph:");
    this->photo = new QLineEdit;
    this->photoLabel->setBuddy(this->photo);
    fieldsLayout->addWidget(this->photoLabel);
    fieldsLayout->addWidget(this->photo);

    this->id = new QLineEdit;

    //buttons
    this->add = new QPushButton("Add Coat");
    this->update = new QPushButton("Update Coat");
    this->remove = new QPushButton("Remove Coat");
    buttonsLayout->addWidget(this->add);
    buttonsLayout->addWidget(this->update);
    buttonsLayout->addWidget(this->remove);

    //combine
    rLayout->addWidget(fields);
    rLayout->addWidget(buttons);
    layout->addWidget(rSide);

    //connections
    QObject::connect(this->add, &QPushButton::clicked, this, &AdminGUI::addCoatButtonHandler);
    QObject::connect(this->remove, &QPushButton::clicked, this, &AdminGUI::removeCoatButtonHandler);
    QObject::connect(this->update, &QPushButton::clicked, this, &AdminGUI::updateCoatButtonHandler);
    QObject::connect(this, &AdminGUI::CoatsUpdateSignal, this, &AdminGUI::populateTrenchCoats);

    QObject::connect(this->coats, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged();});
    QObject::connect(this, SIGNAL(addCoatSignal(std::string, std::string, double, int, std::string)), this, SLOT(addCoat(std::string, std::string, double, int, std::string)));
    QObject::connect(this, SIGNAL(removeCoatSignal(int)), this, SLOT(removeCoat(int)));
    QObject::connect(this, SIGNAL(updateCoatSignal(int, std::string, std::string, double, int, std::string)), this, SLOT(updateCoat(int, std::string, std::string, double, int, std::string)));

    populateTrenchCoats();
}

void  AdminGUI::populateTrenchCoats() {
    this->fileServ->backupEverything();
    if (this->coats->count() > 0)
        this->coats->clear();
    int nr;
    std::vector<std::string> a = this->serv->getPrintListGUI(nr);
    for (int i = 0; i < nr; i++)
    {
        QString toAdd = QString::fromStdString(a[i]);
        QFont f{ "Verdana", 15};
        auto* item = new QListWidgetItem{toAdd};
        item->setFont(f);
        this->coats->addItem(item);
    }
    if (nr > 0)
        this->coats->setCurrentRow(0);
}

void AdminGUI::listItemChanged() {
    int idx = this->getSelectedIndex();
    if (idx == -1)
        return;

    if (idx >= this->serv->getSize())
        return;
    std::vector<std::string> a = this->serv->getElementByPos(idx);
    this->id->setText(QString::fromStdString(a[0]));
    this->size->setText(QString::fromStdString(a[1]));
    this->colour->setText(QString::fromStdString(a[2]));
    this->price->setText(QString::fromStdString(a[3]));
    this->quantity->setText(QString::fromStdString(a[4]));
    this->photo->setText(QString::fromStdString(a[5]));
}

int AdminGUI::getSelectedIndex() {
    if (this->coats->count() == 0)
        return -1;

    QModelIndexList index = this->coats->selectionModel()->selectedIndexes();
    if (index.empty())
    {
        this->id->clear();
        this->size->clear();
        this->colour->clear();
        this->price->clear();
        this->quantity->clear();
        this->photo->clear();
        return -1;
    }
    int idx = index.at(0).row();
    return idx;
}

void AdminGUI::addCoatButtonHandler() {
    QString s = this->size->text();
    QString c = this->colour->text();
    QString p = this->price->text();
    QString q = this->quantity->text();
    QString ph = this->photo->text();

    emit addCoatSignal(s.toStdString(), c.toStdString(), p.toDouble(), q.toInt(), ph.toStdString());
}

void AdminGUI::addCoat(std::string size, std::string colour, double price, int quantity, std::string photo) {
    try {
        this->serv->addElement(std::move(size), std::move(colour), price, quantity, std::move(photo));
        emit CoatsUpdateSignal();
        return;
    }
     catch (std::runtime_error &e) {
         QMessageBox messageBox;
         QMessageBox::critical(0, "Error", "An error has occurred!");
     }
     catch (ValidatorException &e) {
         QMessageBox messageBox;
         QMessageBox::critical(0, "Error", "An error has occurred!");
     }
}

void AdminGUI::removeCoat(int id) {
    try {
        this->serv->removeElement(id);
        emit CoatsUpdateSignal();
        return;
    }
    catch (std::runtime_error &e) {
        QMessageBox messageBox;
        QMessageBox::critical(0, "Error", "An error has occurred!");
    }
}

void AdminGUI::updateCoat(int id, std::string size, std::string colour, double price, int quantity, std::string photo) {
    try {
        this->serv->updateAll(id, std::move(size), std::move(colour), price, quantity, std::move(photo));
        emit CoatsUpdateSignal();
        return;
    }
    catch (std::runtime_error &e) {
        QMessageBox messageBox;
        QMessageBox::critical(0, "Error", "An error has occurred!");
    }
    catch (ValidatorException &e) {
        QMessageBox messageBox;
        QMessageBox::critical(0, "Error", "An error has occurred!");
    }
}

void AdminGUI::removeCoatButtonHandler() {
    QString i = this->id->text();
    emit removeCoatSignal(i.toInt());
}

void AdminGUI::updateCoatButtonHandler() {
    QString i = this->id->text();
    QString s = this->size->text();
    QString c = this->colour->text();
    QString p = this->price->text();
    QString q = this->quantity->text();
    QString ph = this->photo->text();

    emit updateCoatSignal(i.toInt(), s.toStdString(), c.toStdString(), p.toDouble(), q.toInt(), ph.toStdString());
}