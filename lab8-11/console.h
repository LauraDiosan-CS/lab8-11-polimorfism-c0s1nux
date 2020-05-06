#pragma once

#include "service.h"

class Console {
private:
	Service service;
public:
	Console(Service& serv):service(serv) {
	};
	int login();
	void logout();
	void showMenu();
	void showSecondMenu();
	void add();
	void showAll();
	void runConsole();
	//void delProj();
	//void findProj();
	//void updateProj();      // WORK IN PROGRESS!
	~Console();
};