//
// Created by Alex on 22.03.2021.
//

#include "AdminConsole.h"

AdminConsole::AdminConsole(Controller *d, FileServ *fs) {
    this->serv = d;
    this->fileServ = fs;
}

AdminConsole::~AdminConsole() {
    delete this->serv;
}

void AdminConsole::start() {
    bool works = true;
    while (works)
    {
        AdminConsole::printMenu();
        std::string whatToDo;
        std::cin >> whatToDo;
        if (whatToDo == "exit")
            works = false;
        else if (whatToDo == "add")
            this->addElement();
        else if (whatToDo == "delete")
            this->removeElement();
        else if (whatToDo == "update")
            this->updateElement();
        else if (whatToDo == "print")
            this->printAll();
        else
            std::cout << "That is not a valid command!";
        std::cout << "\n\n";
    }
}

void AdminConsole::printMenu() {
    std::cout << "\tadd - add a new trench coat to the inventory\n";
    std::cout << "\tdelete - removes a trench coat from the inventory\n";
    std::cout << "\tupdate - updates an element from the inventory, based on id\n";
    std::cout << "\tprint - prints all trench coats\n";
    std::cout << "\texit - exits the user mode\n";
    std::cout << ">>>";
}

void AdminConsole::addElement() {
    int quantity, id;
    double price;
    std::string size;
    std::string colour;
    std::string photograph;
    std::cout << "\nInput the size: ";
    std::cin >> size;
    std::cout << "\nInput the colour: ";
    std::cin >> colour;
    std::cout << "\nInput the price: ";
    std::cin >> price;
    std::cout << "\nInput the quantity: ";
    std::cin >> quantity;
    std::cout << "\nInput the photo: ";
    std::cin >> photograph;

    try {
        id = this->serv->addElement(size, colour, price, quantity, photograph);
    } catch (ValidatorException &e) {
        std::cout << "\n";
        std::cout << e.what();
        return;
    }

    std::cout << "\nThe coat was added in the system. The ID is: " << id;
    this->fileServ->backupEverything();
}

void AdminConsole::removeElement() {
    int id;
    std::cout << "\nPlease enter the ID of the coat you want to remove: ";
    std::cin >> id;

    try {
        this->serv->removeElement(id);
    } catch (std::runtime_error &e) {
        std::cout << "\n";
        std::cout << e.what();
        return;
    }

    std::cout << "\n The coat was removed from the system!";
    this->fileServ->backupEverything();
}

void AdminConsole::updateElement() {
    int id;
    std::string what;
    std::string toWhat;
    std::cout << "\nPlease enter the ID of the coat you want to update: ";
    std::cin >> id;
    std::cout << "\nPlease enter the field you want to update (size, colour, price, quantity, photograph): ";
    std::cin >>what;
    std::cout << "\nPlease enter the value you want to update to: ";
    std::cin >> toWhat;

    try {
        this->serv->updateObject(id, what, toWhat);
    } catch (std::runtime_error &e) {
        std::cout << "\n";
        std::cout << e.what();
        return;
    } catch (ValidatorException &e) {
        std::cout << "\n";
        std::cout << e.what();
        return;
    }

    std::cout << "\nThe field was updated!";
    this->fileServ->backupEverything();
}

void AdminConsole::printAll() {
    int len;
    std::vector<std::string> pString = this->serv->getPrintList(len);

    std::cout << "\n";
    for (int i = 0; i <= len; i++)
    {
        std::cout << pString[i] << "\n";
    }
}