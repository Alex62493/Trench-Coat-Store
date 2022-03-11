//
// Created by Alex on 21.03.2021.
//

#include "DataBase.h"

#include <utility>

DataBase::DataBase(std::vector<TrenchCoat*> dynamicArray) {
    this->list = std::move(dynamicArray);
}

DataBase::~DataBase()
{
    this->list.clear();
    this->list.shrink_to_fit();
}

void DataBase::addElement(std::string size, std::string colour, double price, int quantity, std::string photograph, int id) {
    auto* d = new TrenchCoat(std::move(size), std::move(colour), price, quantity, std::move(photograph), id);
    this->validator.checkAll(d);
    if (!this->checkIfUnique(*d)) {
        delete d;
        throw std::runtime_error("Cannot have duplicates!");
    }
    this->list.push_back(d);
}

void DataBase::deleteElement(int id) {
    int newId = throwError(id);

    this->list.erase(this->list.begin() + newId);
}

int DataBase::searchId(int id) {
    int i = 0;
    for (TrenchCoat* coat : this->list)
    {
        if (coat->getId() == id) {
            return i;
        }
        i++;
    }
    return -1;
}

void DataBase::updateQuantity(int id, int quantity) {
    Validator::checkIfQuantityPositive(quantity);
    int newId = throwError(id);
    this->list[newId]->updateQuantity(quantity);
}

void DataBase::updateSize(int id, std::string size) {
    Validator::checkSize(size);
    int newId = throwError(id);
    this->list[newId]->updateSize(std::move(size));
}

void DataBase::updatePhotograph(int id, std::string photograph) {
    Validator::checkIfPhotographExists(photograph);
    int newId = throwError(id);
    this->list[newId]->updatePhotograph(std::move(photograph));
}

void DataBase::updateColour(int id, std::string colour) {
    Validator::checkIfColourExists(colour);
    int newId = throwError(id);
    this->list[newId]->updateColour(std::move(colour));
}

void DataBase::updatePrice(int id, double price) {
    Validator::checkIfPricePositive(price);
    int newId = throwError(id);
    this->list[newId]->updatePrice(price);
}

int DataBase::throwError(int id) {
    int newId = this->searchId(id);
    if (newId == -1)
        throw std::runtime_error("The ID doesn't exist");
    return newId;
}

std::vector<std::string> DataBase::getPrintList() {
    std::vector<std::string> printList;
    printList.emplace_back("Id\t\tSize\t\tColour\t\tPrice\t\tQuantity\t\tPhotograph");

    for (TrenchCoat* elem : this->list)
    {
        printList.push_back(std::to_string(elem->getId()) + "\t\t" + elem->getSize() + "\t\t" + elem->getColour() + "\t\t" + std::to_string(elem->getPrice()).substr(0, std::to_string(elem->getPrice()).find('.') + 3) + "\t\t" + std::to_string(elem->getQuantity()) + "\t\t" + elem->getPhotograph());
    }

    return printList;
}

int DataBase::getSize() {
    return this->list.size();
}

bool DataBase::checkIfUnique(TrenchCoat d)
{
    std::string string1;
    string1 = d.getSize() + "\t\t" + d.getColour() + "\t\t" + std::to_string(d.getPrice()).substr(0, std::to_string(d.getPrice()).find('.') + 3) + "\t\t" + std::to_string(d.getQuantity()) + "\t\t" + d.getPhotograph();
    for (TrenchCoat* elem : this->list)
    {
        std::string string2;
        string2 = elem->getSize() + "\t\t" + elem->getColour() + "\t\t" + std::to_string(elem->getPrice()).substr(0, std::to_string(elem->getPrice()).find('.') + 3) + "\t\t" + std::to_string(elem->getQuantity()) + "\t\t" + elem->getPhotograph();
        if (string1 == string2) {
            return false;
        }
    }
    return true;
}

TrenchCoat* DataBase::getElement(int id)
{
    int pos = this->searchId(id);
    return this->list[pos];
}

std::vector<std::string> DataBase::getBuyList(const std::string& size, int& len) {
    std::vector<std::string> printList;
    len = 0;

    if (size.empty()) {
        for (TrenchCoat* elem : this->list)
        {
            if (elem->getQuantity() > 0)
            {
                printList.push_back(std::to_string(elem->getId()) + " - " + elem->getSize() + " - " + elem->getColour() + " - " + std::to_string(elem->getPrice()).substr(0, std::to_string(elem->getPrice()).find('.') + 3) + " - " + std::to_string(elem->getQuantity()) + " - " + elem->getPhotograph());
                len++;
            }
        }
    }
    else
    {
        Validator::checkSize(size);
        for (TrenchCoat* elem : this->list)
        {
            if (elem->getQuantity() > 0 && size == elem->getSize())
            {
                printList.push_back(std::to_string(elem->getId()) + " - " + elem->getSize() + " - " + elem->getColour() + " - " + std::to_string(elem->getPrice()).substr(0, std::to_string(elem->getPrice()).find('.') + 3) + " - " + std::to_string(elem->getQuantity()) + " - " + elem->getPhotograph());
                len++;
            }
        }
    }

    return std::move(printList);
}

std::istream &operator>>(std::istream &is, DataBase* db) {
    int nr;
    is >> nr;
    while (nr)
    {
        auto* coat = new TrenchCoat("S", "b", 21, 21, "w", 0);
        is >> coat;
        db->list.push_back(coat);
        nr--;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, DataBase *db) {
    os << db->getSize() << "\n";
    for (TrenchCoat* i : db->list)
    {
        os << i;
    }
    return os;
}

std::vector<std::string> DataBase::getPrintListGUI() {
    std::vector<std::string> printList;
    for (TrenchCoat* elem : this->list)
    {
        printList.push_back(std::to_string(elem->getId()) + " - " + elem->getSize() + " - " + elem->getColour() + " - " + std::to_string(elem->getPrice()).substr(0, std::to_string(elem->getPrice()).find('.') + 3) + " - " + std::to_string(elem->getQuantity()) + " - " + elem->getPhotograph());
    }

    return printList;
}

std::vector<std::string> DataBase::getElementByPos(int pos) {
    std::vector<std::string> a;
    a.push_back(std::to_string(this->list[pos]->getId()));
    a.push_back(this->list[pos]->getSize());
    a.push_back(this->list[pos]->getColour());
    a.push_back(std::to_string(this->list[pos]->getPrice()));
    a.push_back(std::to_string(this->list[pos]->getQuantity()));
    a.push_back(this->list[pos]->getPhotograph());
    return a;
}

void DataBase::updateAll(int id, std::string size, std::string colour, double price, int quantity, std::string photograph) {
    int newId = throwError(id);
    Validator::checkSize(size);
    Validator::checkIfColourExists(colour);
    Validator::checkIfPricePositive(price);
    Validator::checkIfQuantityPositive(quantity);
    Validator::checkIfPhotographExists(photograph);
    this->list[newId]->updateSize(std::move(size));
    this->list[newId]->updateColour(std::move(colour));
    this->list[newId]->updatePrice(price);
    this->list[newId]->updateQuantity(quantity);
    this->list[newId]->updatePhotograph(std::move(photograph));
}
