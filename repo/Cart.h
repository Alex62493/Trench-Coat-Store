#pragma once

#include "DynamicArray.h"
#include "TrenchCoat.h"
#include <string>
#include <vector>

class Cart {

private:
	std::vector<TrenchCoat*> list;
	double price;

public:
	Cart();
	/*
	* Adds an new item to the list
	* I'll get the address of the original, so it can decrease the quantity
	*/
	void addElement(TrenchCoat* t);

	/*
	* It will decrease the quantity of all the items in the cart, effectively buying them
	*/
	void buyAll();

	/*
	* Returns the total price of the elements in te cart
	*/
	double getPrice() const;

	/*
	 * returns a list of strings to print
	 */
    std::vector<std::string> getPrintList(int &i);
};