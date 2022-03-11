#include "UserServ.h"

#include <utility>

UserServ::UserServ(DataBase* dataBase, Cart* c)
{
	this->db = dataBase;
	this->cart = c;
}

UserServ::~UserServ()
{
	delete this->cart;
}

void UserServ::addToCart(std::string c)
{
	int id;
	const std::string& aux = c;
	std::vector<std::string> parts;
	UserServ::split(aux, "\t", parts);
	id = atoi(parts[0].c_str());
	this->cart->addElement(this->db->getElement(id));
}

std::vector<std::string> UserServ::getBuyList(std::string size, int& i)
{
	return this->db->getBuyList(size, i);
}

std::vector<std::string> UserServ::getShoppingCart(int& i)
{
	return this->cart->getPrintList(i);
}

double UserServ::getPrice()
{
	return this->cart->getPrice();
}

void UserServ::buyAll()
{
	this->cart->buyAll();
}

void UserServ::split(const std::string &str, const std::string &delim, std::vector<std::string> &parts) {
    size_t start, end = 0;
    while (end < str.size()) {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != std::string::npos)) {
            start++;
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == std::string::npos)) {
            end++;
        }
        if (end-start != 0) {
            parts.push_back(std::string(str, start, end-start));
        }
    }
}