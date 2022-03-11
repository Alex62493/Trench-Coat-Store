//
// Created by Alex on 03.06.2021.
//

#include "UserGUI.h"
#include <utility>

UserGUI::UserGUI(DataBase* db, const std::string& fileType, FileServ* fileDB, QWidget* parent) {
    setParent(parent);
    auto* cart = new Cart();
    this->serv = new UserServ(db, cart);
    this->fileDB = fileDB;

    if (fileType == "csv") {
        auto *c = new polymorphism::CSVFileService("cart.csv", cart);
        this->fileServ = c;
    } else {
        auto *c = new polymorphism::HTMLFileServ("cart.html", cart);
        this->fileServ = c;
    }
    auto* layout = new QHBoxLayout{this};

    this->m_view.setModel(&m_model);
    layout->addWidget(&m_view);

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
    this->filterLabel = new QLabel("Size for list:");
    this->filter = new QLineEdit;
    this->filterLabel->setBuddy(this->filter);
    fieldsLayout->addWidget(this->filterLabel);
    fieldsLayout->addWidget(this->filter);

    this->sizeLabel = new QLabel("Size:");
    this->size = new QLineEdit;
    this->size->setReadOnly(true);
    this->sizeLabel->setBuddy(this->size);
    fieldsLayout->addWidget(this->sizeLabel);
    fieldsLayout->addWidget(this->size);

    this->colourLabel = new QLabel("Colour:");
    this->colour = new QLineEdit;
    this->colour->setReadOnly(true);
    this->colourLabel->setBuddy(this->colour);
    fieldsLayout->addWidget(this->colourLabel);
    fieldsLayout->addWidget(this->colour);

    this->priceLabel = new QLabel("Price:");
    this->price = new QLineEdit;
    this->price->setReadOnly(true);
    this->priceLabel->setBuddy(this->price);
    fieldsLayout->addWidget(this->priceLabel);
    fieldsLayout->addWidget(this->price);


    this->quantityLabel = new QLabel("Quantity:");
    this->quantity = new QLineEdit;
    this->quantity->setReadOnly(true);
    this->quantityLabel->setBuddy(this->quantity);
    fieldsLayout->addWidget(this->quantityLabel);
    fieldsLayout->addWidget(this->quantity);


    this->photoLabel = new QLabel("Photograph:");
    this->photo = new QLineEdit;
    this->photo->setReadOnly(true);
    this->photoLabel->setBuddy(this->photo);
    fieldsLayout->addWidget(this->photoLabel);
    fieldsLayout->addWidget(this->photo);

    this->totalPriceLabel = new QLabel("Total Price:");
    this->totalPrice = new QLineEdit;
    this->totalPrice->setReadOnly(true);
    this->totalPriceLabel->setBuddy(this->size);
    fieldsLayout->addWidget(this->totalPriceLabel);
    fieldsLayout->addWidget(this->totalPrice);
    totalPrice->setText("0");

    this->id = new QLineEdit;

    //buttons
    this->add = new QPushButton("Add Coat");
    this->ss = new QPushButton("Show Cart");
    this->buy = new QPushButton("Buy All");
    this->filterButton = new QPushButton("Filter by size");
    buttonsLayout->addWidget(this->add);
    buttonsLayout->addWidget(this->ss);
    buttonsLayout->addWidget(this->buy);
    buttonsLayout->addWidget(this->filterButton);

    //combine
    rLayout->addWidget(fields);
    rLayout->addWidget(buttons);
    layout->addWidget(rSide);

    //connections
    QObject::connect(this->add, &QPushButton::clicked, this, &UserGUI::addButtonHandler);
    QObject::connect(this->ss, &QPushButton::clicked, this, &UserGUI::showButtonHandler);
    QObject::connect(this->buy, &QPushButton::clicked, this, &UserGUI::buyButtonHandler);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &UserGUI::filterButtonHandler);
    QObject::connect(this, &UserGUI::CoatsUpdateSignal, this, &UserGUI::populateTrenchCoats);
    QObject::connect(this->coats, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged();});

    this->add->setEnabled(false);
    this->ss->setEnabled(false);
    this->buy->setEnabled(false);
}

void  UserGUI::populateTrenchCoats() {
    if (this->coats->count() > 0)
        this->coats->clear();
    this->m_model.updateVector(this->trenchCoats);
    int nr = this->trenchCoats.size();
    for (int i = 0; i < nr; i++)
    {
        QString toAdd = QString::fromStdString(this->trenchCoats[i]);
        QFont f{ "Verdana", 15};
        auto* item = new QListWidgetItem{toAdd};
        item->setFont(f);
        this->coats->addItem(item);
    }
    if (nr > 0)
        this->coats->setCurrentRow(0);
}

void UserGUI::listItemChanged() {
    int idx = this->getSelectedIndex();
    if (idx == -1)
        return;

    if (idx >= this->trenchCoats.size())
        return;
    std::vector<std::string> a;
    UserServ::split(this->trenchCoats[idx], "-", a);
    //std::vector<std::string> a = this->serv->getElementByPos(idx);
    this->id->setText(QString::fromStdString(a[0]));
    this->size->setText(QString::fromStdString(a[1]));
    this->colour->setText(QString::fromStdString(a[2]));
    this->price->setText(QString::fromStdString(a[3]));
    this->quantity->setText(QString::fromStdString(a[4]));
    this->photo->setText(QString::fromStdString(a[5]));
}

int UserGUI::getSelectedIndex() {
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

void UserGUI::addButtonHandler()
{
    int idx = this->getSelectedIndex();
    if (idx == -1)
        return;

    this->serv->addToCart(this->trenchCoats[idx]);
    this->trenchCoats.erase(this->trenchCoats.begin() + idx);
    this->totalPrice->setText(QString::fromStdString(std::to_string(this->serv->getPrice())));
    this->fileServ->writeInFile();
    emit CoatsUpdateSignal();
}

void UserGUI::showButtonHandler()
{
    int nr;
    std::vector<std::string> cart = this->serv->getShoppingCart(nr);

    this->fileServ->openFile();
}

void UserGUI::buyButtonHandler()
{
    this->serv->buyAll();
    this->fileDB->backupEverything();
    QMessageBox messageBox;
    QMessageBox::critical(0, "Order Complete", "Thanks for buying!");
    this->close();
}

void UserGUI::filterButtonHandler()
{
    int nr;
    std::string s = this->filter->text().toStdString();
    if (s != "XS" && s !="S" && s != "M" && s != "L" && s != "XL" && s != "XXL" && !s.empty())
        return;
    this->trenchCoats = this->serv->getBuyList(s, nr);
    this->add->setEnabled(true);
    this->ss->setEnabled(true);
    this->buy->setEnabled(true);
    this->filterButton->setEnabled(false);
    this->filter->setEnabled(false);
    emit CoatsUpdateSignal();
}