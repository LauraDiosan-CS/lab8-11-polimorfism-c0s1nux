#include <iostream>
#include <assert.h>
#include <Windows.h>
#include "phone.h"
#include "drone.h"
#include "series.h"
#include "repoTemplate.h"
#include "repoFile.h"
#include "repoFileCSV.h"
#include "repoFileHTML.h"
#include "serializerSeries.h"
#include "serializerUser.h"
#include "service.h"

using namespace std;

void serviceHTMLTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for services!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(500);
	system("CLS");
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for service with HTML repository.";
	SerializerSeries* serial = new SerializerSeries();
	SerializerUser* user = new SerializerUser();
	RepositoryFileHTML<Series*>repof("tests.html", serial);
	RepositoryFile<User*> repo("users.txt", ' ', user);
	Service serv(repof, repo);
	vector<string> operators;
	string anOperator;
	anOperator = "Vodafone";
	operators.push_back(anOperator);
	Phone phone1("OnePlus", "7T", 1001, operators);
	Phone phone2("yo", "yoo", 1001, operators);
	Drone drone1("sup", "sup", 1001, 100);
	Drone drone2("sup2", "sup2", 10501, 1020);
	Drone drone3("haha", "mizkif", 2000, 300);
	Series* series1 = new Phone(phone1);
	Series* series2 = new Phone(phone2);
	Series* series3 = new Drone(drone1);
	Series* series4 = new Drone(drone2);
	Series* series5 = new Drone(drone3);
	serv.addElem(series1);
	serv.addElem(series2);
	serv.addElem(series3);
	serv.addElem(series4);
	list<Series*> goodList = serv.getAllSeries();
	assert(goodList.size() == 4);
	Sleep(500);
	cout << ".";
	serv.delElem(series1);
	goodList = serv.getAllSeries();
	Sleep(500);
	cout << ".\n";
	assert(goodList.size() == 3);
	serv.updateElem(series2, series5);
	assert(serv.findPositionOfElem(series5) == 0);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	repof.delElem(series5);
	repof.delElem(series3);
	repof.delElem(series4);
}

void serviceCSVTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for service with CSV repository.";
	SerializerSeries* serial = new SerializerSeries();
	SerializerUser* user = new SerializerUser();
	RepositoryFileCSV<Series*>repof("testsCSV.csv", serial);
	RepositoryFile<User*> repo("users.txt", ' ', user);
	Service serv(repof, repo);
	vector<string> operators;
	string anOperator;
	anOperator = "Vodafone";
	operators.push_back(anOperator);
	Phone phone1("OnePlus", "7T", 1001, operators);
	Phone phone2("yo", "yoo", 1001, operators);
	Drone drone1("sup", "sup", 1001, 100);
	Drone drone2("sup2", "sup2", 10501, 1020);
	Drone drone3("haha", "mizkif", 2000, 300);
	Series* series1 = new Phone(phone1);
	Series* series2 = new Phone(phone2);
	Series* series3 = new Drone(drone1);
	Series* series4 = new Drone(drone2);
	Series* series5 = new Drone(drone3);
	serv.addElem(series1);
	serv.addElem(series2);
	serv.addElem(series3);
	serv.addElem(series4);
	list<Series*> goodList = serv.getAllSeries();
	assert(goodList.size() == 4);
	Sleep(500);
	cout << ".";
	serv.delElem(series1);
	goodList = serv.getAllSeries();
	Sleep(500);
	cout << ".\n";
	assert(goodList.size() == 3);
	serv.updateElem(series2, series5);
	assert(serv.findPositionOfElem(series5) == 0);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	repof.delElem(series5);
	repof.delElem(series3);
	repof.delElem(series4);
}