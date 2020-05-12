#include <iostream>
#include "testsForObjects.h"
#include "repoTests.h"
#include <Windows.h>
#include "console.h"
#include "repoFileCSV.h"
#include "repoFileHTML.h"
#include "serializerSeries.h"
#include "serializerUser.h"
#include "repoFile.h"
#include "series.h"
#include "serviceTests.h"

using namespace std;

int main() {
	creationTestsForPhones();
	Sleep(500);
	creationTestsForDrones();
	Sleep(500);
	system("CLS");
	repoTests();
	Sleep(500);
	repoHTMLTests();
	Sleep(500);
	repoCSVTests();
	Sleep(500);
	system("CLS");
	serviceHTMLTests();
	Sleep(500);
	serviceCSVTests();
	Sleep(500);
	system("CLS");
	cout << "----------------------------------------------------------------\n";
	cout << "Tests finished!\n";
	cout << "----------------------------------------------------------------\n";
	Sleep(1000);
	system("CLS");
	SerializerSeries* serial = new SerializerSeries();
	SerializerUser* user = new SerializerUser();
	int option;
	cout << "----------------------------------------------------------------\n";
	cout << "Choose what file to work with!\n";
	cout << "1. CSV.\n";
	cout << "2. HTML.\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Option: ";
	cin >> option;
	while (option != 1 && option != 2)
	{
		cout << "Incorrect option!";
		Sleep(500);
		system("CLS");
		cout << "----------------------------------------------------------------\n";
		cout << "Choose what file to work with!\n";
		cout << "1. CSV.\n";
		cout << "2. HTML.\n";
		cout << "-------------------------------------------------------------\n";
		cout << "Option: ";
		cin >> option;
		if (option == 1 || option == 2)
			break;
	}
	system("CLS");
	if (option == 1)
	{
		RepositoryFileCSV<Series*>repof("things.csv", serial);
		RepositoryFile<User*> repo("users.txt", ' ', user);
		Service serv(repof, repo);
		Console Console(serv);
		Console.runConsole();
	}
	else
	{
		RepositoryFileHTML<Series*>repof("things.html", serial);
		RepositoryFile<User*> repo("users.txt", ' ', user);
		Service serv(repof, repo);
		Console Console(serv);
		Console.runConsole();
	}
	return 0;
}