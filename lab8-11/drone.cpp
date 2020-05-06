#include "drone.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Drone::Drone() {
	numberOfRotors = 0;
}

Drone::Drone(const Drone& aDrone):Series(aDrone) {
	this->numberOfRotors = aDrone.numberOfRotors;
}

Drone::Drone(const char* productionName, const char* modelName, int numberOfProducts, int numberOfRotors):Series(productionName, modelName, numberOfProducts){
	this->numberOfRotors = numberOfRotors;
}

bool Drone::operator==(const Drone& aDrone) {
	return (Series::operator==(aDrone) and aDrone.numberOfRotors == numberOfRotors);
}

int Drone::getNumberOfRotors() {
	return this->numberOfRotors;
}

void Drone::setNumberOfRotors(int aNumberOfRotors) {
	this->numberOfRotors = aNumberOfRotors;
}

Drone::~Drone() {
	numberOfRotors = 0;
}

Drone& Drone::operator=(const Drone& aDrone) {
	if (this == &aDrone)
		return *this;
	if (this->productionName) {
		delete[] this->productionName;
		this->productionName = new char[strlen(aDrone.productionName) + 1];
		strcpy_s(this->productionName, strlen(aDrone.productionName) + 1, aDrone.productionName);
	}
	if (this->modelName) {
		delete[] this->modelName;
		this->modelName = new char[strlen(aDrone.modelName) + 1];
		strcpy_s(this->modelName, strlen(aDrone.modelName) + 1, aDrone.modelName);
	}
	this->numberOfProducts = aDrone.numberOfProducts;
	this->numberOfRotors = aDrone.numberOfRotors;
	return *this;
}

ostream& operator<<(ostream& os, Drone aDrone) {
	os << aDrone.getProductionName() << " " << aDrone.getModelName() << " " << aDrone.getNumberOfProducts() << " " << aDrone.getNumberOfRotors() << "\n";
	return os;
}

istream& operator>>(istream& is, Drone& aDrone) {
	char* productionName = new char[20];
	char* modelName = new char[20];
	int numberOfProducts, numberOfRotors;
	cout << "Give production name: ";
	is >> productionName;
	cout << "Give model name: ";
	is >> modelName;
	cout << "Give number of products: ";
	is >> numberOfProducts;
	cout << "Give number of rotors: ";
	is >> numberOfRotors;
	aDrone.setProductionName(productionName);
	aDrone.setModelName(modelName);
	aDrone.setNumberOfProducts(numberOfProducts);
	aDrone.setNumberOfRotors(numberOfRotors);
	return is;
}

Series* Drone::clone() {
	Drone* newSeries = new Drone();
	newSeries->setProductionName(this->productionName);
	newSeries->setModelName(this->modelName);
	newSeries->setNumberOfProducts(this->numberOfProducts);
	newSeries->setNumberOfRotors(this->numberOfRotors);
	return newSeries;
}

Drone::Drone(string line, char delimiter) {
	vector<string> tokens = splitLine(line, delimiter);
	this->productionName = new char[tokens[0].length() + 1];
	strcpy_s(this->productionName, tokens[0].length() + 1, tokens[0].c_str());

	this->modelName = new char[tokens[1].length() + 1];
	strcpy_s(this->modelName, tokens[1].length() + 1, tokens[1].c_str());
	numberOfProducts = stoi(tokens[2]);
	numberOfRotors = stoi(tokens[3]);
}

void Drone::fromString(string line, char delimiter) {
	vector<string> tokens = splitLine(line, delimiter);
	this->productionName = new char[tokens[0].length() + 1];
	strcpy_s(this->productionName, tokens[0].length() + 1, tokens[0].c_str());

	this->modelName = new char[tokens[1].length() + 1];
	strcpy_s(this->modelName, tokens[1].length() + 1, tokens[1].c_str());
	numberOfProducts = stoi(tokens[2]);
	numberOfRotors = stoi(tokens[3]);
}

string Drone::toString() {
	string string1, string2;
	string1 = this->productionName;
	string2 = this->modelName;
	return  string1 + " " + string2 + " " + to_string(this->numberOfProducts) + " " + to_string(this->numberOfRotors);
}

string Drone::toStringWithDelimiter(char delimiter) {
	string string1, string2;
	string1 = this->productionName;
	string2 = this->modelName;
	return  string1 + delimiter + string2 + delimiter + to_string(this->numberOfProducts) + delimiter + to_string(this->numberOfRotors);
}