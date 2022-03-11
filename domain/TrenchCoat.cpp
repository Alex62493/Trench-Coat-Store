//
// Created by Alex on 20.03.2021.
//
#include "TrenchCoat.h"
#include <string>
#include <cstdlib>
#include <utility>

TrenchCoat::TrenchCoat(std::string size, std::string colour, double price, int quantity, std::string photograph, int id) {
    this->size = std::move(size);
    this->colour = std::move(colour);
    this->photograph = std::move(photograph);
    this->quantity = quantity;
    this->price = price;
    this->id = id;
}

TrenchCoat::TrenchCoat(const TrenchCoat &d) {
    this->size = d.size;
    this->colour = d.colour;
    this->photograph = d.photograph;
    this->quantity = d.quantity;
    this->price = d.price;
    this->id = d.id;
}

double TrenchCoat::getPrice() const {
    return this->price;
}

std::string TrenchCoat::getColour() {
    return this->colour;
}

std::string TrenchCoat::getPhotograph() {
    return this->photograph;
}

std::string TrenchCoat::getSize() {
    return this->size;
}

int TrenchCoat::getQuantity() const {
    return this->quantity;
}

void TrenchCoat::updatePrice(double price) {
    this->price = price;
}

void TrenchCoat::updateColour(std::string colour) {
    this->colour = std::move(colour);
}

void TrenchCoat::updatePhotograph(std::string photograph) {
    this->photograph = std::move(photograph);
}

void TrenchCoat::updateSize(std::string size) {
    this->size = std::move(size);
}

void TrenchCoat::updateQuantity(int quantity) {
    this->quantity = quantity;
}

TrenchCoat &TrenchCoat::operator=(const TrenchCoat *trenchCoat){
    this->size = trenchCoat->size;
    this->colour = trenchCoat->colour;
    this->photograph = trenchCoat->photograph;
    this->quantity = trenchCoat->quantity;
    this->price = trenchCoat->price;
    this->id = trenchCoat->id;
    return *this;
}

TrenchCoat &TrenchCoat::operator=(const TrenchCoat& trenchCoat){
    this->size = trenchCoat.size;
    this->colour = trenchCoat.colour;
    this->photograph = trenchCoat.photograph;
    this->quantity = trenchCoat.quantity;
    this->price = trenchCoat.price;
    this->id = trenchCoat.id;
    return *this;
}

int TrenchCoat::getId() const {
    return this->id;
}

std::ostream &operator<<(std::ostream &os, const TrenchCoat* trenchCoat) {
    os << trenchCoat->id << "\n" << trenchCoat->size << "\n" << trenchCoat->colour <<"\n" << trenchCoat->price << "\n" << trenchCoat->quantity << "\n" << trenchCoat->photograph << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, TrenchCoat *trenchCoat) {
    is >> trenchCoat->id >> trenchCoat->size;
    std::getline(is, trenchCoat->colour);
    std::getline(is, trenchCoat->colour);
    is >> trenchCoat->price >> trenchCoat->quantity;
    std::getline(is, trenchCoat->photograph);
    std::getline(is, trenchCoat->photograph);
    return is;
}

