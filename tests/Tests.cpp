//
// Created by Alex on 22.03.2021.
//
#include "Tests.h"

void Tests::testTrenchCoats() {
    auto* t = new TrenchCoat("L", "Blue", 3, 4, "www.google.com", 0);
    auto* t1 = new TrenchCoat(*t);
    assert(t->getSize() == t1->getSize());
    assert(t->getColour() == t1->getColour());
    assert(t->getPhotograph() == t1->getPhotograph());
    assert(t->getPrice() == t1->getPrice());
    assert(t->getQuantity() == t1->getQuantity());
    assert(t->getId() == t1->getId());

    t->updatePrice(2);
    t->updateQuantity(3);
    t->updateSize("S");
    t->updateColour("Red");
    t->updatePhotograph("wwww");

    assert(t->getSize() == "S");
    assert(t->getColour() == "Red");
    assert(t->getPhotograph() == "wwww");
    assert(t->getPrice() == 2);
    assert(t->getQuantity() == 3);

    *t1 = t;

    assert(t->getSize() == t1->getSize());
    assert(t->getColour() == t1->getColour());
    assert(t->getPhotograph() == t1->getPhotograph());
    assert(t->getPrice() == t1->getPrice());
    assert(t->getQuantity() == t1->getQuantity());
    assert(t->getId() == t1->getId());

    *t1 = *t;

    assert(t->getSize() == t1->getSize());
    assert(t->getColour() == t1->getColour());
    assert(t->getPhotograph() == t1->getPhotograph());
    assert(t->getPrice() == t1->getPrice());
    assert(t->getQuantity() == t1->getQuantity());
    assert(t->getId() == t1->getId());

    delete t;
    delete t1;
}

void Tests::testDynamicArray() {
    auto* d = new DynamicArray<TrenchCoat>();
    assert(d->getSize() == 0);
    auto* t = new TrenchCoat("L", "Blue", 3, 4, "www.google,com", 0);
    d->addElement(t);
    auto* t1 = new TrenchCoat("L", "Blue", 3, 20, "www.google.com", 0);
    d->addElement(t1);
    assert(d->getSize() == 2);
    assert(d->getElement(0)->getQuantity() != d->getElement(1)->getQuantity());

    d->deleteElement(0);
    assert(d->getSize() == 1);
    assert(d->getElement(0)->getQuantity() == 20);
    delete d;
}

void Tests::testDataBase() {
    std::vector<TrenchCoat*> dynamicArray;
    auto* d = new DataBase(dynamicArray);

    std::vector<std::string> sd = d->getPrintList();
    assert(sd[0] == "Id\t\tSize\t\tColour\t\tPrice\t\tQuantity\t\tPhotograph");

    try {
        d->throwError(0);
        assert(false);
    }
    catch (std::runtime_error &e) {
        assert(true);
    }

    d->addElement("L", "Blue", 34, 12, "www.google.com", 0);
    d->addElement("M", "Red", 74, 22, "www.com", 1);
    d->addElement("S", "Lime", 66, 36, "www", 2);

    assert(d->getSize() == 3);

    d->deleteElement(1);
    d->deleteElement(0);
    assert(d->getSize() == 1);

    sd = d->getPrintList();
    assert(sd[1] == "2\t\tS\t\tLime\t\t66.00\t\t36\t\twww");

    auto* trenchCoat = new TrenchCoat("S", "Lime", 66, 36, "www", 2);
    assert(d->checkIfUnique(*trenchCoat) == false);
    trenchCoat->updatePrice(33);
    assert(d->checkIfUnique(*trenchCoat) == true);
    delete trenchCoat;

    try {
        d->addElement("S", "Lime", 66, 36, "www", 2);
        assert(false);
    } catch (std::runtime_error &e) {
        assert(true);
    }

    d->updateQuantity(2, 0);
    d->updatePrice(2, 0);

    d->updateColour(2, "Blue");
    d->updateSize(2, "L");
    d->updatePhotograph(2, "www.com");

    sd = d->getPrintList();
    assert(sd[1] == "2\t\tL\t\tBlue\t\t0.00\t\t0\t\twww.com");

    d->addElement("L", "red", 1, 1, "www.x", 3);
    int i = 0;
    std::vector<std::string> idk = std::move(d->getBuyList("", i));
    assert(i == 1);

    idk = std::move(d->getBuyList("L", i));
    assert(i == 1);

    idk = std::move(d->getBuyList("S", i));
    assert(i == 0);

    delete d;
}

void Tests::testController() {
    std::vector<TrenchCoat*> dynamicArray;
    auto* dataBase = new DataBase(dynamicArray);
    auto* d = new Controller(dataBase);

    d->addElement("L", "Blue", 34, 12, "www.google.com");
    d->addElement("M", "Red", 74, 22, "www.com");
    d->addElement("S", "Lime", 66, 36, "www");

    d->updateObject(0, "size", "S");

    try {
        d->updateObject(0, "SSS", "ADSDSAD");
        assert(false);
    } catch (std::runtime_error &e) {
        assert(true);
    }

    d->updateObject(0, "colour", "Khaki");
    d->updateObject(0, "price", "21");
    d->updateObject(0, "quantity", "0");
    d->updateObject(0, "photograph", "www.yahoo.com");

    d->removeElement(1);
    int i = 0;
    std::vector<std::string> sd = d->getPrintList(i);

    assert(i == 2);
    assert(sd[1] == "0\t\tS\t\tKhaki\t\t21.00\t\t0\t\twww.yahoo.com");

    try {
        d->updateObject(0, "size", "ADSDSAD");
        assert(false);
    } catch (ValidatorException &e) {
        assert(true);
    }

    try {
        d->addElement("S", "Lime", -2, 12, "www");
        assert(false);
    }
    catch (ValidatorException &e) {
        assert(true);
    }

    try {
        d->addElement("DS", "Lime", 34, 12, "www");
        assert(false);
    }
    catch (ValidatorException &e) {
        assert(true);
    }

    try
    {
        d->updateObject(0, "price", "-2");
        assert(false);
    }
    catch (ValidatorException &e)
    {
        assert(true);
    }

    try
    {
        d->updateObject(0, "quantity", "-3");
        assert(false);
    }
    catch (ValidatorException &e)
    {
        assert(true);
    }

    std::vector<std::string>().swap(sd);

    delete d;
}

void Tests::testCart()
{
    Cart* c = new Cart;
    assert(c->getPrice() == 0);
    auto* t = new TrenchCoat("S", "Blue", 34, 12, "www.google.com", 0);
    c->addElement(t);
    assert(c->getPrice() == 34);
    auto* t1 = new TrenchCoat("M", "Red", 45.5, 13, "www.yahoo.com", 0);
    c->addElement(t1);
    assert(c->getPrice() == 79.5);
    c->buyAll();
    assert(t->getQuantity() == 11);
    assert(t1->getQuantity() == 12);

    int i = 0;
    std::vector<std::string> idk = c->getPrintList(i);
    assert(i == 3);

    delete c;
    delete t;
    delete t1;

     std::vector<std::string>().swap(idk);
}

void Tests::testUserServ()
{
    std::vector<TrenchCoat*> da;
    auto* db = new DataBase(da);
    auto* c = new Cart();
    auto* us = new UserServ(db, c);

    db->addElement("S", "Blue", 314, 235, "www", 0);
    db->addElement("L", "Red", 141, 12, "www1", 1);
    db->addElement("L", "Green", 34, 13, "www2", 2);
    db->addElement("L", "White", 144, 1, "www3", 3);
    db->addElement("S", "Black", 37.5, 0, "www4", 4);

    int k;
   std::vector<std::string> kd;

    try
    {
        kd = std::move(us->getBuyList("SD", k));
        assert(false);
    }
    catch (ValidatorException &e)
    {
        assert(true);
    }

    kd = std::move(us->getBuyList("", k));
    assert(k == 4);


    kd = us->getBuyList("S", k);
    assert(k == 1);

    std::vector<std::string>().swap(kd);

    kd = us->getBuyList("L", k);
    assert(k == 3);

    us->addToCart(kd[0]);
    us->addToCart(kd[2]);

    std::vector<std::string>().swap(kd);

    assert(us->getPrice() == 285);

    kd = us->getShoppingCart(k);
    assert(k == 3);

    std::vector<std::string>().swap(kd);

    us->buyAll();

    assert(db->getElement(3)->getQuantity() == 0);
    assert(db->getElement(1)->getQuantity() == 11);

    delete us;
    delete db;
}

void Tests::testAll() {
    this->testTrenchCoats();
    this->testDynamicArray();
    this->testDataBase();
    this->testController();
    this->testCart();
    this->testUserServ();
}