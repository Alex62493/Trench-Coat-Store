#include "Cart.h"

Cart::Cart()
{
	this->list.clear();
	this->price = 0;
}

void Cart::addElement(TrenchCoat* t)
{
	this->list.push_back(t);
	this->price += t->getPrice();
}

void Cart::buyAll()
{
	for (TrenchCoat* elem : this->list)
	{
	    elem->updateQuantity(elem->getQuantity() - 1);
	}
}

double Cart::getPrice() const
{
	return this->price;
}

std::vector<std::string> Cart::getPrintList(int &i) {
	std::vector<std::string> printList;
	printList.emplace_back("Id\tSize\tColour\tPrice\tQuantity\tPhotograph");

	for (TrenchCoat* elem : this->list)
	{
        printList.push_back(std::to_string(elem->getId()) + "\t" + elem->getSize() + "\t" + elem->getColour() + "\t" + std::to_string(elem->getPrice()).substr(0, std::to_string(elem->getPrice()).find('.') + 3) + "\t" + std::to_string(elem->getQuantity()) + "\t" + elem->getPhotograph());
	}

	i = this->list.size() + 1;

	return printList;
}
