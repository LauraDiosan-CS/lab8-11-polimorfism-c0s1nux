#include <iostream>
#include <assert.h>
#include <Windows.h>
#include <cstring>
#include <vector>
#include "phone.h"
#include "series.h"
#include "drone.h"
using namespace std;

void creationTestsForPhones() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for all objects!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(2000);
	system("CLS");
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for creation of phones.";
	vector<string> strVec;
	strVec.push_back("Vodafone");
	strVec.push_back("Orange");
	Phone phone1("xd", "xdd", 5, strVec);
	Phone phone2 = phone1;
	Phone phone3(phone1);
	assert(strcmp(phone1.getProductionName(), "xd") == 0);
	assert(strcmp(phone1.getModelName(), "xdd") == 0);
	assert(phone1.getNumberOfProducts() == 5);
	Sleep(1000);
	cout << ".";
	assert(phone1.getListOfOperators() == strVec);
	assert(strcmp(phone3.getProductionName(), "xd") == 0);
	assert(strcmp(phone3.getModelName(), "xdd") == 0);
	assert(phone3.getNumberOfProducts() == 5);
	Sleep(1000);
	cout << ".\n";
	assert(phone3.getListOfOperators() == strVec);
	assert(phone2 == phone1);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
}
void creationTestsForDrones() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for creation of drones.";
	Drone drone1("XD", "XDD", 5, 4);
	Drone drone2 = drone1;
	Drone drone3(drone1);
	assert(strcmp(drone1.getProductionName(), "XD") == 0);
	assert(strcmp(drone1.getModelName(), "XDD") == 0);
	assert(drone1.getNumberOfProducts() == 5);
	Sleep(1000);
	cout << ".";
	assert(drone1.getNumberOfRotors() == 4);
	assert(strcmp(drone3.getProductionName(), "XD") == 0);
	assert(strcmp(drone3.getModelName(), "XDD") == 0);
	assert(drone3.getNumberOfProducts() == 5);
	Sleep(1000);
	cout << ".\n";
	assert(drone3.getNumberOfRotors() == 4);
	assert(drone2 == drone1);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
}
void creationTestsForSeries(){
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for creation of series.";
	Series series1("yo", "yoo", 123);
	Series series2 = series1;
	Series series3(series1);
	assert(strcmp(series1.getProductionName(), "yo") == 0);
	assert(strcmp(series1.getModelName(), "yoo") == 0);
	assert(series1.getNumberOfProducts() == 123);
	Sleep(1000);
	cout << ".";
	assert(strcmp(series3.getProductionName(), "yo") == 0);
	assert(strcmp(series3.getModelName(), "yoo") == 0);
	assert(series3.getNumberOfProducts() == 123);
	Sleep(1000);
	cout << ".\n";
	assert(series2 == series1);
	Sleep(1000);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(1000);
	system("CLS");
	cout << "All object related tests ran successfully! Moving on!\n";
}