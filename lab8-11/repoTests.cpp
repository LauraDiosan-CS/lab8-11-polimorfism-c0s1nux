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

using namespace std;

void repoTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for repositories!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(500);
	system("CLS");
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for repository.";
	vector<string> operators;
	string anOperator;
	anOperator = "Vodafone";
	operators.push_back(anOperator);
	Series* series1 = new Phone("yo", "a 10 wtf", 1, operators);
	Series* series2 = new Phone("yoo", "b 15 is", 2, operators);
	Series* series3 = new Phone("yooo", "c 19 this", 3, operators);
	Series* series4 = new Phone("yoooo", "d 7 damn", 4, operators);
	Repository<Series*> rep;
	rep.addElem(series1);
	rep.addElem(series2);
	rep.addElem(series3);
	rep.addElem(series4);
	Sleep(500);
	cout << ".";
	assert(rep.getSize() == 4);
	assert(*rep.getAll().front() == *series1);
	assert(*rep.getAll().back() == *series4);
	assert(*rep.getItemFromPos(0) == *series1);
	Series* series5 = new Phone("yoooo", "d 7 oop", 4, operators);
	Series* series6 = new Phone("something", "not", 1, operators);
	assert(rep.findElem(series4) == 3);
	assert(rep.findElem(series6) == -1);
	rep.delElem(series3);
	assert(rep.findElem(series3) == -1);
	assert(rep.getSize() == 3);
	Sleep(500);
	cout << ".\n";
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
}

void repoHTMLTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for HTML repository.";
	SerializerSeries* serial = new SerializerSeries();
	RepositoryFileHTML<Series*>repof("tests.html", serial);
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
	repof.addElem(series1);
	repof.addElem(series2);
	repof.addElem(series3);
	repof.addElem(series4);
	list<Series*> goodList = repof.getAll();
	assert(goodList.size() == 4);
	Sleep(500);
	cout << ".";
	repof.delElem(series1);
	goodList = repof.getAll();
	Sleep(500);
	cout << ".\n";
	assert(goodList.size() == 3);
	repof.updateElem(series2, series5);
	assert(repof.findPositionOfElem(series5) == 0);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	repof.delElem(series5);
	repof.delElem(series3);
	repof.delElem(series4);
}

void repoCSVTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for CSV repository.";
	SerializerSeries* serial = new SerializerSeries();
	RepositoryFileHTML<Series*>repof("testsCSV.csv", serial);
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
	repof.addElem(series1);
	repof.addElem(series2);
	repof.addElem(series3);
	repof.addElem(series4);
	list<Series*> goodList = repof.getAll();
	assert(goodList.size() == 4);
	Sleep(500);
	cout << ".";
	repof.delElem(series1);
	goodList = repof.getAll();
	Sleep(500);
	cout << ".\n";
	assert(goodList.size() == 3);
	repof.updateElem(series2, series5);
	assert(repof.findPositionOfElem(series5) == 0);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	repof.delElem(series5);
	repof.delElem(series3);
	repof.delElem(series4);
}