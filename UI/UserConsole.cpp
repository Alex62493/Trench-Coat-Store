#include "UserConsole.h"

UserConsole::UserConsole(DataBase* db, const std::string& fileType)
{
    auto* cart = new Cart();
	this->us = new UserServ(db, cart);

    if (fileType == "csv") {
        auto *c = new polymorphism::CSVFileService("cart.csv", cart);
        this->fileServ = c;
    } else {
        auto *c = new polymorphism::HTMLFileServ("cart.html", cart);
        this->fileServ = c;
    }
}

UserConsole::~UserConsole()
{
	delete this->us;
	delete this->fileServ;
}

void UserConsole::start()
{
	this->goTroughList();
}

void UserConsole::goTroughList()
{
	int nr, total, current = 0;
	bool right = false;
	std::vector<std::string> trenchCoats;
    std::string size;
	while (!right)
	{
		std::cout << "Please enter the size you want to search for: ";
		std::getline(std::cin, size);
        std::getline(std::cin, size);
		std::cout << "\n";
		try
		{
			trenchCoats = this->us->getBuyList(size, nr);
			right = true;
		}
		catch (ValidatorException &e)
		{
			std::cout << e.what() << "\n";
		}
	}

	total = nr;
	std::vector<int> boughtItems;
	while (right)
	{
		if (total == 0)
		{
			std::cout << "There are no more trench coats you can buy, you will be redirected to the cart\n";
			this->seeCart();
			break;
		}

		bool bought = false;
		for (int i : boughtItems)
		{
			if (i == current)
			{
				bought = true;
				break;
			}
		}

		if (!bought)
		{
			std::string command;
			std::string aux;
			aux = trenchCoats[current];
			std::vector<std::string> p;
			UserServ::split(aux, "\t", p);
			//ShellExecuteA(NULL, NULL, "chrome.exe", p[5], NULL, SW_SHOWMAXIMIZED);
			while (true)
			{
				std::cout << "\nId\t\tSize\t\tColour\t\tPrice\t\tQuantity\tPhotograph\n" << trenchCoats[current] << "\n\n";
				std::cout << "What do you want to do?\n";
				std::cout << "\tadd - adds the otem to the cart\n";
				std::cout << "\tnext - goes to the next item\n";
				std::cout << "\tcart - see the cart\n";
				std::cout << "\texit - exits the user mode\n";

				std::cout << ">>>";
				std::cin >> command;

				if (command == "add")
				{
					this->us->addToCart(trenchCoats[current]);
					boughtItems.push_back(current);
					total--;
					std::cout << "\nTotal price is: " << this->us->getPrice() << "\n";
                    this->fileServ->writeInFile();
					break;
				}
				else if (command == "next")
				{
					break;
				}
				else if (command == "cart")
				{
					bool complete = this->seeCart();
					if (complete)
					{
						right = false;
						break;
					}
					else
					{
						std::cout << "\n";
					}
				}
				else if (command == "exit")
				{
					std::cout << "See you again!\n";
					right = false;
					break;
				}
			}
		}

		current++;
		if (current == nr)
		{
			current = 0;
		}
	}
}

bool UserConsole::seeCart()
{
	int nr;
	std::vector<std::string> cart = this->us->getShoppingCart(nr);

    this->fileServ->openFile();

	std::string command;
	std::cout << "\nTotal price is: " << this->us->getPrice() <<"\n";
	std::cout << "\nDo you want to buy all of them now? (yes/no)\n";

	while (true)
	{
		std::cin >> command;
		if (command == "yes")
		{
			this->us->buyAll();
			std::cout << "Thanks you for the purchase!\n\n";
			return true;
		}
		else if (command == "no")
		{
			return false;
		}
		else
		{
			std::cout << "Wrong command!\n";
		}
	}
}