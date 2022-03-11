//
// Created by Alex on 21.03.2021.
//

#include "Controller.h"

#include <utility>



int Controller::addElement(std::string size, std::string colour, double price, int quantity, std::string photograph) {
    this->repo->addElement(std::move(size), std::move(colour), price, quantity, std::move(photograph), this->nextId);
    this->nextId++;
    return this->nextId - 1;
}

Controller::Controller(DataBase* dataBase) {
    this->repo = dataBase;
    this->nextId = 0;
}

Controller::~Controller() {
    delete this->repo;
}

void Controller::removeElement(int id) {
    this->repo->deleteElement(id);
}

std::vector<std::string> Controller::getPrintList(int &i) {
    i = this->repo->getSize();
    return this->repo->getPrintList();
}

std::vector<std::string> Controller::getPrintListGUI(int &i) {
    i = this->repo->getSize();
    return this->repo->getPrintListGUI();
}

int Controller::getSize() {
    return this->repo->getSize();
}

void Controller::updateObject(int id, const std::string& what, const std::string& toWhat) {
    if (what == "colour") {
        this->repo->updateColour(id, toWhat);
        return;
    }
    else if (what == "photograph") {
        this->repo->updatePhotograph(id, toWhat);
        return;
    }
    else if (what == "size") {
        this->repo->updateSize(id, toWhat);
        return;
    }
    else if (what == "quantity") {
        int quantity = std::stoi(toWhat);
        this->repo->updateQuantity(id, quantity);
        return;
    }
    else if (what == "price") {
        double price = std::stod(toWhat);
        this->repo->updatePrice(id, price);
        return;
    }

    throw std::runtime_error("Not a valid field!");

}

std::vector<std::string> Controller::getElementByPos(int pos) {
    return this->repo->getElementByPos(pos);
}

void Controller::updateAll(int id, std::string size, std::string colour, double price, int quantity,
                           std::string photograph) {
    this->repo->updateAll(id, std::move(size), std::move(colour), price, quantity, std::move(photograph));
}
