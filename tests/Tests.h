//
// Created by Alex on 22.03.2021.
//
#include "DynamicArray.h"
#include "TrenchCoat.h"
#include "../repo/DataBase.h"
#include "../serv/Controller.h"
#include "../repo/Cart.h"
#include "../serv/UserServ.h"
#include <cassert>
#include <string>
#include <vector>

#ifndef A45_ALEX62493_TESTS_H
#define A45_ALEX62493_TESTS_H


class Tests {
public:
    static void testTrenchCoats();
    static void testDynamicArray();
    static void testDataBase();
    static void testController();
    static void testCart();
    static void testUserServ();
    void testAll();
};


#endif //A45_ALEX62493_TESTS_H
