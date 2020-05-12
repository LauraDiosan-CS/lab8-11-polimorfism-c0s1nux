#include "console.h"
#include <iostream>
#include <string.h>
#include <Windows.h>

using namespace std;

int Console::login() {
	cout << "----------------------------------------------------------------\n";
	cout << "LOGIN SYSTEM 1.0\n";
	cout << "----------------------------------------------------------------\n";
	cout << "Your username: ";
	string user;
	cin >> user;
	cout << "----------------------------------------------------------------\n";
	cout << "Your password: ";
	string pass;
	cin >> pass;
	cout << "----------------------------------------------------------------\n";
	return service.login(user, pass);
}

void Console::add() {
	cout << "----------------------------------------------------------------\n";
	cout << "What do you want to add?\n";
	cout << "1. Phone.\n";
	cout << "2. Drone.\n";
	cout << "----------------------------------------------------------------\n";
	int option;
	cout << "Option: ";
	cin >> option;
	if (option == 1)
	{
		try {
			cout << "----------------------------------------------------------------\n";
			Phone aPhone;
			cin >> aPhone;
			service.validatePhone(aPhone);
			Series* aSeries = new Phone(aPhone);
			int result = service.addElem(aSeries);
			if (result == 1)
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Phone added successfully!\n";
			}
			else
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Phone not added!\n";
			}
			cout << "----------------------------------------------------------------\n";
			Sleep(2000);

		}
		catch (PhoneException err) {
			cout << "----------------------------------------------------------------\n";
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i];
			cout << "----------------------------------------------------------------\n";
			Sleep(3000);
		}
	}
	else
	{
		try {
			cout << "----------------------------------------------------------------\n";
			Drone aDrone;
			cin >> aDrone;
			Series* aSeries = new Drone(aDrone);
			service.validateSeries(aSeries);
			int result = service.addElem(aSeries);
			if (result == 1)
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Drone added successfully!\n";
			}
			else
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Drone not added!\n";
			}
			cout << "----------------------------------------------------------------\n";
			Sleep(2000);
		}
		catch (SeriesException err) {
			cout << "----------------------------------------------------------------\n";
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i];
			cout << "----------------------------------------------------------------\n";
			Sleep(3000);
			
		}
	}
}

void Console::del() {
	cout << "----------------------------------------------------------------\n";
	cout << "What do you want to remove?\n";
	cout << "1. Phone.\n";
	cout << "2. Drone.\n";
	cout << "----------------------------------------------------------------\n";
	int option;
	cout << "Option: ";
	cin >> option;
	if (option == 1)
	{
		cout << "----------------------------------------------------------------\n";
		Phone aPhone;
		cin >> aPhone;
		Series* aSeries = new Phone(aPhone);
		int result = service.delElem(aSeries);
		if (result == 1)
		{
			cout << "----------------------------------------------------------------\n";
			cout << "Phone removed successfully!\n";
		}
		else
		{
			cout << "----------------------------------------------------------------\n";
			cout << "Phone was not removed!\n";
		}
		cout << "----------------------------------------------------------------\n";
		Sleep(2000);
	}
	else
	{
		cout << "----------------------------------------------------------------\n";
		Drone aDrone;
		cin >> aDrone;
		Series* aSeries = new Drone(aDrone);
		int result = service.delElem(aSeries);
		if (result == 1)
		{
			cout << "----------------------------------------------------------------\n";
			cout << "Drone removed successfully!\n";
		}
		else
		{
			cout << "----------------------------------------------------------------\n";
			cout << "Drone was not removed!\n";
		}
		cout << "----------------------------------------------------------------\n";
		Sleep(2000);
	}
}

void Console::update() {
	cout << "----------------------------------------------------------------\n";
	cout << "What do you want to update?\n";
	cout << "1. Phone.\n";
	cout << "2. Drone.\n";
	cout << "----------------------------------------------------------------\n";
	int option;
	cout << "Option: ";
	cin >> option;
	if (option == 1)
	{
		try {
			system("CLS");
			cout << "----------------------------------------------------------------\n";
			Phone oldPhone, newPhone;
			cout << "Introduceti telefonul vechi!\n\n";
			cin >> oldPhone;
			Series* oldSeries = new Phone(oldPhone);
			system("CLS");
			cout << "----------------------------------------------------------------\n";
			cout << "Introduceti telefonul nou!\n\n";
			cin >> newPhone;
			service.validatePhone(newPhone);
			Series* newSeries = new Phone(newPhone);
			int result = service.updateElem(oldSeries, newSeries);
			if (result == 1)
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Phone updated successfully!\n";
			}
			else
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Phone was not updated successfully!\n";
			}
			cout << "----------------------------------------------------------------\n";
			Sleep(2000);
		}
		catch (PhoneException err) {
			cout << "----------------------------------------------------------------\n";
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i];
			cout << "----------------------------------------------------------------\n";
			Sleep(3000);
		}
	}
	else
	{
		try {
			system("CLS");
			cout << "----------------------------------------------------------------\n";
			Drone oldDrone, newDrone;
			cout << "Introduceti drona veche!\n\n";
			cin >> oldDrone;
			Series* oldSeries = new Drone(oldDrone);
			system("CLS");
			cout << "----------------------------------------------------------------\n";
			cout << "Introduceti drona noua!\n\n";
			cin >> newDrone;
			Series* newSeries = new Drone(newDrone);
			service.validateSeries(newSeries);
			int result = service.updateElem(oldSeries, newSeries);
			if (result == 1)
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Drone updated successfully!\n";
			}
			else
			{
				cout << "----------------------------------------------------------------\n";
				cout << "Drone was not updated successfully!\n";
			}
			cout << "----------------------------------------------------------------\n";
			Sleep(2000);
		}
		catch (SeriesException err) {
			cout << "----------------------------------------------------------------\n";
			for (unsigned i = 0; i < err.getErrors().size(); i++)
				cout << err.getErrors()[i];
			cout << "----------------------------------------------------------------\n";
			Sleep(3000);
		}
	}
}

void Console::searchByProductionName() {
	cout << "----------------------------------------------------------------\n";
	cout << "Dati numele producatorului pe care il cautati: ";
	char* productionName = new char[200];
	cin >> productionName;
	cout << "Searching";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".";
	Sleep(300);
	cout << ".\n";
	Sleep(300);
	cout << "----------------------------------------------------------------\n";
	list<Series*> goodList = service.searchByProductionName(productionName);
	if (goodList.size() == 0)
	{
		cout << "There are no items with that production name!\n";
		cout << "-------------------------------------------------------------\n";
		Sleep(1000);
		return;
	}
	typename list<Series*>::iterator it;
	for (it = goodList.begin(); it != goodList.end(); ++it)
		cout << **it;
	cout << "----------------------------------------------------------------\n";
	Sleep(3000);
	delete[] productionName;
}

void Console::logout() {
	service.logout();
}

void Console::showAll() {
	if (service.getSize() == 0)
	{
		cout << "There are no objects in the file!\n";
		return;
	}
	for (int i = 0; i < service.getSize(); i++)
	{
		cout << (*service.getItemFromPos(i)).toString() << endl;
	}
}

void Console::showMenu() {
	cout << "----------------------------------------------------------------\n";
	cout << "1. Login.\n";
	cout << "2. Operate.\n";
	cout << "3. Logout.\n";
	cout << "----------------------------------------------------------------\n";
}

void Console::showSecondMenu() {
	cout << "----------------------------------------------------------------\n";
	cout << "1. Add an object.\n";
	cout << "2. Delete an object.\n";
	cout << "3. Update an object.\n";
	cout << "4. Show all objects.\n";
	cout << "5. Search by production name.\n";
	cout << "6. Exit.\n";
	cout << "----------------------------------------------------------------\n";
}

void Console::runConsole()
{
	bool isRunning = true;
	bool wasLoggedIn = false;
	while (isRunning) {
		showMenu();
		int option;
		cout << "Option: ";
		cin >> option;
		if (option == 1)
			if (wasLoggedIn == true)
			{
				cout << "You are already logged in!\n";
				cout << "----------------------------------------------------------------\n";
				Sleep(1000);
				system("CLS");
			}
			else
			{
				system("CLS");
				if (login())
				{
					cout << "Successfully logged in!\n";
					cout << "----------------------------------------------------------------\n";
					wasLoggedIn = true;
					Sleep(1000);
					system("CLS");
				}
				else
				{
					cout << "Wrong username and/or password!\n";
					cout << "----------------------------------------------------------------\n";
					Sleep(1000);
					system("CLS");
				}
			}
		else
			if (option == 2)
				if (wasLoggedIn == false)
				{
					cout << "You are not logged in and you can't operate any commands!\n";
					cout << "----------------------------------------------------------------\n";
					Sleep(1000);
					system("CLS");
				}
				else
				{
					system("CLS");
					bool secondMenuIsRunning = true;
					while (secondMenuIsRunning)
					{
						showSecondMenu();
						int secondOption;
						cout << "Option: ";
						cin >> secondOption;
						if (secondOption == 1)
						{
							system("CLS");
							add();
							system("CLS");
						}
						else
							if (secondOption == 2)
							{
								system("CLS");
								del();
								system("CLS");
							}
							else
								if (secondOption == 3)
								{
									system("CLS");
									update();
									system("CLS");
								}
								else
									if (secondOption == 4)
									{
										cout << "----------------------------------------------------------------\n";
										showAll();
										cout << "----------------------------------------------------------------\n";
										Sleep(3000);
										system("CLS");
									}
									else
										if (secondOption == 5)
										{
											system("CLS");
											searchByProductionName();
											system("CLS");
										}
										else
											if (secondOption == 6)
											{
												secondMenuIsRunning = false;
												system("CLS");
											}

					}

				}
			else
				if (option == 3)
				{
					if (wasLoggedIn == true)
					{
						logout();
						cout << "You have been successfully logged out!\n";
						cout << "----------------------------------------------------------------\n";
						wasLoggedIn = false;
						Sleep(1000);
						system("CLS");
						isRunning = false;
					}
					else
					{
						cout << "You were NOT logged in!\n";
						cout << "----------------------------------------------------------------\n";
						Sleep(1000);
						system("CLS");
					}
				}

	}
}

Console::~Console()
{

}