//
// Created by Alex on 20.03.2021.
//

#ifndef A45_ALEX62493_TRENCHCOAT_H
#define A45_ALEX62493_TRENCHCOAT_H
#include <iostream>
#include <string>


class TrenchCoat {

private:
    std::string size;
    std::string colour;
    std::string photograph;
    double price;
    int quantity, id;

public:
    /*
     * The default constructor, which needs all the info in the order: size, colour, price, quantity, photograph
     */
    TrenchCoat(std::string size, std::string colour, double price, int quantity, std::string photograph, int id);

    /*
     * The copy constructor, which only needs another dress to copy from
     */
    TrenchCoat(const TrenchCoat &d);

    /*
     * This are the getters
     */
    std::string getSize();
    std::string getColour();
    std::string getPhotograph();
    double getPrice() const;
    int getQuantity() const;
    int getId() const;

    /*
     * Updates
     */
    void updateSize(std::string size);
    void updateColour(std::string colour);
    void updatePhotograph(std::string photograph);
    void updatePrice(double price);
    void updateQuantity(int quantity);

    /*
     * the copy is implemented in the = operator
     */
    TrenchCoat &operator=(const TrenchCoat &trenchCoat);
    TrenchCoat &operator=(const TrenchCoat *trenchCoat);
    friend std::istream& operator>> (std::istream& is, TrenchCoat* trenchCoat);
    friend std::ostream& operator<< (std::ostream& is, const TrenchCoat* trenchCoat);
};


#endif //A45_ALEX62493_TRENCHCOAT_H
