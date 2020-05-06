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
using namespace std;

int main() {
	creationTestsForPhones();
	Sleep(1000);
	creationTestsForDrones();
	Sleep(1000);
	system("CLS");
	repoTests();
	Sleep(1000);
	repoFileTests();
	Sleep(1000);
	system("CLS");
	cout << "----------------------------------------------------------------\n";
	cout << "Tests finished!\n";
	cout << "----------------------------------------------------------------\n";
	Sleep(2000);
	system("CLS");
	SerializerSeries* serial = new SerializerSeries();
	SerializerUser* user = new SerializerUser();
	RepositoryFileHTML<Series*>repof("things.html", serial);
	RepositoryFile<User*> repo("users.txt", ' ', user);
	Service serv(repof, repo);
	Console Console(serv);
	Console.runConsole();
	return 0;
}