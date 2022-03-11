//
// Created by Alex on 12.04.2021.
//

#ifndef A45_ALEX62493_VALIDATOR_H
#define A45_ALEX62493_VALIDATOR_H
#include <string>
#include "TrenchCoat.h"
#include "../exceptions/ValidatorException.h"

class Validator {
public:
    static void checkSize(const std::string& size);
    static void checkIfColourExists(const std::string& colour);
    static void checkIfPhotographExists(const std::string& photograph);
    static void checkIfQuantityPositive(int a);
    static void checkIfPricePositive(double a);
    void checkAll(TrenchCoat* trenchCoat);
};


#endif //A45_ALEX62493_VALIDATOR_H
