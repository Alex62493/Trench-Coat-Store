//
// Created by Alex on 21.03.2021.
//

#include "../repo/DataBase.h"
#include <string>
#include <cstdlib>
#include <string>
#include <vector>

#ifndef A45_ALEX62493_CONTROLLER_H
#define A45_ALEX62493_CONTROLLER_H


class Controller {
    friend class FileServ;

private:
    DataBase* repo;
    int nextId;

public:
    explicit Controller(DataBase* dataBase);
    ~Controller();


    /*
     * Transfers these to the repo and adds an element to the list
     * The id of the element will be nextId, which increases after
    */
    int addElement(std::string size, std::string colour, double price, int quantity, std::string photograph);

    /*
     * I removes the element with that id
     * Will get an error if it doesnt exist
    */
    void removeElement(int id);

    /*
     * Will update an object  with the id id
     * 'what' is what will be updated (colour, size, photograph, price, quantity)
     * the id can't be changed
    */
    void updateObject(int id, const std::string& what, const std::string& toWhat);

    /*
     * Get a list of strings which need to be printed
    */
    std::vector<std::string> getPrintList(int &i);

    std::vector<std::string> getPrintListGUI(int &i);

    int getSize();
    std::vector<std::string> getElementByPos(int pos);
    void updateAll(int id, std::string size, std::string colour, double price, int quantity, std::string photograph);
};


#endif //A45_ALEX62493_CONTROLLER_H
