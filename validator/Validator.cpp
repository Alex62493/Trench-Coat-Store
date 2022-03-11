//
// Created by Alex on 12.04.2021.
//

#include "Validator.h"

void Validator::checkSize(const std::string& size)
{
    if (size != "XS" && size !="S" && size != "M" && size != "L" && size != "XL" && size != "XXL") {
        throw ValidatorException("Not a valid size!");
    }
}

void Validator::checkIfPricePositive(double a)
{
    if (a < 0)
        throw ValidatorException("The price cannot be positive!");
}

void  Validator::checkIfQuantityPositive(int a)
{
    if (a < 0)
        throw ValidatorException("The price cannot be positive!");
}

void Validator::checkIfColourExists(const std::string &colour)
{
    if (colour.empty())
        throw ValidatorException("The photograph link cannot be empty!");
}

void Validator::checkIfPhotographExists(const std::string &photograph)
{
    if (photograph.empty())
        throw ValidatorException("The trench coat must have a colour!");
}

void Validator::checkAll(TrenchCoat* trenchCoat)
{
    this->checkSize(trenchCoat->getSize());
    this->checkIfQuantityPositive(trenchCoat->getQuantity());
    this->checkIfPricePositive(trenchCoat->getPrice());
    this->checkIfColourExists(trenchCoat->getColour());
    this->checkIfPhotographExists(trenchCoat->getPhotograph());
}