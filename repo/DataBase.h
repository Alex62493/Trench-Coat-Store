//
// Created by Alex on 21.03.2021.
//

#include "DynamicArray.h"
#include "TrenchCoat.h"
#include <string>

#ifndef A45_ALEX62493_DATABASE_H
#define A45_ALEX62493_DATABASE_H
#include <vector>
#include <exception>
#include "../validator/Validator.h"


class DataBase {

private:
    std::vector<TrenchCoat*> list;
    Validator validator;

public:
    explicit DataBase(std::vector<TrenchCoat*> dynamicArray);
    ~DataBase();

    /*
     * Adds an element with those characteristics
     */
    void addElement(std::string size, std::string colour, double price, int quantity, std::string photograph, int id);

    /*
     * Removes an element
     */
    void deleteElement(int id);

    /*
     * Updates an element
     */
    void updateColour(int id, std::string colour);
    void updatePhotograph(int id, std::string photograph);
    void updateSize(int id, std::string size);
    void updatePrice(int id, double price);
    void updateQuantity(int id, int quantity);
    void updateAll(int id, std::string size , std::string colour, double price, int quantity, std::string photograph);

    /*
     * Search and returns the position of a element with a certain id
     * if the id doesnt exit, -1 is returned
     */
    int searchId(int id);

    /*
     * Throws an error if the id doesn't exit in the list
     */
    int throwError(int id);

    /*
     * returns a list of strings to print
     */
    std::vector<std::string> getPrintList();

    int getSize();

    bool checkIfUnique(TrenchCoat d);

    TrenchCoat* getElement(int id);
    std::vector<std::string> getElementByPos(int pos);

    /*
     * returns a list of strings to print
     */
    std::vector<std::string> getBuyList(const std::string& size, int& len);
    friend std::istream& operator>> (std::istream& is, DataBase* db);
    friend std::ostream& operator<< (std::ostream& os, DataBase* db);

    std::vector<std::string> getPrintListGUI();
};


#endif //A45_ALEX62493_DATABASE_H
