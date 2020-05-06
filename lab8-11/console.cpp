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
	cout << "2. Drone\n";
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
				cout << "Phone added successfully!\n";
			else
				cout << "Phone not added!\n";
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
			service.addElem(aSeries);
			cout << "Drone added successfully!\n";
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

void Console::logout() {
	service.logout();
}

void Console::showAll() {
	list <Series*>::iterator it;
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
	cout << "2. Delete an object. WIP\n";
	cout << "3. Update an object. WIP\n";
	cout << "4. Show all objects.\n";
	cout << "5. Exit.\n";
	cout << "----------------------------------------------------------------\n";
}

void Console::runConsole()
{
	/*bool checkIfDone = true;
	while (checkIfDone) {
		cout << "----------------------------------------------------------------\n";
		cout << "LOG IN SYSTEM 1.0\n";
		if (login()) {
			system("CLS");
			while (service.loggedIn() and checkIfDone) {
				cout << "----------------------------------------------------------------\n";
				cout << "1. Show all." << "\n";
				cout << "2. Log out." << "\n";
				cout << "3. Exit." << "\n";
				cout << "Please choose an option: ";
				int opt;
				cin >> opt;
				cout << "----------------------------------------------------------------\n";
				switch (opt) {
					//case 1: {addProj(); break; }
					//case 2: {findProj(); break; }
					//case 3: {delProj(); break; }
					//case 4: {updateProj(); break; }
				case 1: {
					showAll();
					cout << "----------------------------------------------------------------\n";
					Sleep(3000);
					system("CLS");
					break;
				}
				case 2: {logout(); cout << "You have been logged out." << "\n"; break; }
				case 3: {checkIfDone = false; }
				}
			}
		}
			else
				cout << "incorrect username or password." << "\n";
		}*/
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
				Sleep(2000);
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
					Sleep(2000);
					system("CLS");
				}
				else
				{
					cout << "Wrong username and/or password!\n";
					cout << "----------------------------------------------------------------\n";
					Sleep(2000);
					system("CLS");
				}
			}
		else
			if (option == 2)
				if (wasLoggedIn == false)
				{
					cout << "You are not logged in and you can't operate any commands!\n";
					cout << "----------------------------------------------------------------\n";
					Sleep(2000);
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
									secondMenuIsRunning = false;
									system("CLS");
								}
								else
									{
										cout << "----------------------------------------------------------------\n";
										cout << "All the other options are being worked on! :)\n";
										cout << "----------------------------------------------------------------\n";
										Sleep(2000);
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
						Sleep(2000);
						system("CLS");
					}
					else
					{
						cout << "You were NOT logged in!\n";
						cout << "----------------------------------------------------------------\n";
						Sleep(2000);
						system("CLS");
					}
				}

	}
}

			

Console::~Console()
{

}