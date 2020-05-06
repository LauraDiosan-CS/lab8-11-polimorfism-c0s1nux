#include <iostream>
#include <assert.h>
#include <Windows.h>
#include "phone.h"
#include "drone.h"
#include "series.h"
#include "repoTemplate.h"
#include "repoFile.h"

using namespace std;

void repoTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for repositories and service!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(2000);
	system("CLS");
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for repository tests.";
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
	Sleep(1000);
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
	Sleep(1000);
	cout << ".\n";
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
}

void repoFileTests() {

}