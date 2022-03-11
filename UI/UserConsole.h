#pragma once
#include "../serv/UserServ.h"
#include "../repo/DataBase.h"
#include "../repo/Cart.h"
#include "../serv/HTMLFileServ.h"
#include "../serv/CSVFileService.h"
#include "../serv/UserFileServ.h"
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

class UserConsole {
	
private:
	UserServ* us;
	polymorphism::UserFileServ* fileServ;

public:
	explicit UserConsole(DataBase* db, const std::string& fileType);
	~UserConsole();
	void start();

private:
	void goTroughList();
	bool seeCart();
};