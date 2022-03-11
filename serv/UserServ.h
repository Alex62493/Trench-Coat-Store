#pragma once
#include "../repo/Cart.h"
#include "../repo/DataBase.h"
#include <vector>
#include <string>

class UserServ {
private:
	Cart* cart;
	DataBase* db;

public:
	explicit UserServ(DataBase* dataBase, Cart* c);
	~UserServ();

	/*
	* Searches the string c for the id, then add's the element with that id from the data base to the cart
	*/
	void addToCart(std::string c);

	/*
	 * Get a list of strings which need to be printed
	 * Then it filters out the ones with quantity 0 or the ones that have the size different than the inputed one
	*/
	std::vector<std::string> getBuyList(std::string size, int& i);

	/*
	 * Returns all the element from the cart, in the form of a list of strings
	*/
	std::vector<std::string> getShoppingCart(int& i);

	/*
	* Returns the total price
	*/
	double getPrice();

	/*
	* Calls the buyAll function in the cart
	*/
	void buyAll();

	static void split(const std::string& str, const std::string& delim, std::vector<std::string>& parts);
};