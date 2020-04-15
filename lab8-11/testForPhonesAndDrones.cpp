#include <iostream>
#include <assert.h>
#include "phone.h"
#include "drone.h"
#include <Windows.h>
#include <cstring>
#include <vector>
using namespace std;

void creationTestsForPhoneAndDrone() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for creation of phones and drones.";
	vector<string> strVec;
	strVec.push_back("Vodafone");
	strVec.push_back("Orange");
	Phone phone1("xd", "xdd", 5, strVec);
	Phone phone2;
	char* a = new char[10];
	strcpy_s(a, sizeof "xd", "xd");
	char* b = new char[10];
	strcpy_s(b, sizeof "xdd", "xdd");
	assert(strcmp(phone1.getProductionName(), a) == 0);
	assert(strcmp(phone1.getModelName(), b) == 0);
	assert(phone1.getNumberOfProducts() == 5);
	assert(phone1.getListOfOperators() == strVec);
	Sleep(1000);
	cout << ".";
	Drone drone1("XD", "XDD", 5, 4);
	assert(strcmp(drone1.getProductionName(), "XD") == 0);
	assert(strcmp(drone1.getModelName(), "XDD") == 0);
	assert(drone1.getNumberOfProducts() == 5);
	assert(drone1.getNumberOfRotors() == 4);
	Sleep(1000);
	cout << ".";
	delete[]a;
	a = NULL;
	delete[]b;
	b = NULL;
	Sleep(1000);
	cout << ".\n";
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(1000);
}