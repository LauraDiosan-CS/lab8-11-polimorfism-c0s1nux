#include "phone.h"
#include <iostream>

using namespace std;

Phone::Phone() {
	listOfOperators.clear();
}

Phone::Phone(const Phone& aPhone):Series(aPhone) {
	this->listOfOperators = aPhone.listOfOperators;
}

Phone::Phone(const char* productionName, const char* modelName, int numberOfProducts, vector<string> listOfOperators):Series(productionName, modelName, numberOfProducts) {
	this->listOfOperators = listOfOperators;
}

bool Phone::operator==(const Phone& aPhone) {
	return (Series::operator==(aPhone) and (aPhone.listOfOperators == listOfOperators));
}

vector<string> Phone::getListOfOperators() {
	return this->listOfOperators;
}

Series* Phone::clone() {
	Phone* newSeries = new Phone();
	newSeries->setProductionName(this->productionName);
	newSeries->setModelName(this->modelName);
	newSeries->setNumberOfProducts(this->numberOfProducts);
	newSeries->setListOfOperators(this->listOfOperators);
	return newSeries;
}

void Phone::setListOfOperators(vector<string> aListOfOperators) {
	if (!listOfOperators.empty()) {
		listOfOperators.clear();
	}
	this->listOfOperators = aListOfOperators;
}

Phone::~Phone() {
	if (!listOfOperators.empty()) {
		listOfOperators.clear();
	}
}

Phone& Phone::operator=(const Phone& aPhone) {
	if (this == &aPhone)
		return *this;
	if (this->productionName) {
		delete[] this->productionName;
		this->productionName = new char[strlen(aPhone.productionName) + 1];
		strcpy_s(this->productionName, strlen(aPhone.productionName) + 1, aPhone.productionName);
	}
	if (this->modelName){
		delete[] this->modelName;
	this->modelName = new char[strlen(aPhone.modelName) + 1];
	strcpy_s(this->modelName, strlen(aPhone.modelName) + 1, aPhone.modelName);
}
	this->numberOfProducts = aPhone.numberOfProducts;
	this->listOfOperators = aPhone.listOfOperators;
	return *this;
}

ostream& operator<<(ostream& os, Phone aPhone) {
	os << aPhone.getProductionName() << " " << aPhone.getModelName() << " " << aPhone.getNumberOfProducts() << " ";
	int i;
	for (i = 0; i < aPhone.getListOfOperators().size() - 1; i++)
		os << aPhone.getListOfOperators()[i] << "-";
	os << aPhone.getListOfOperators()[i]<<"\n";
	return os;
}

Phone::Phone(string line, char delimiter) {
	vector<string> tokens = splitLine(line, delimiter);
	this->productionName = new char[tokens[0].length() + 1];
	strcpy_s(this->productionName, tokens[0].length() + 1, tokens[0].c_str());

	this->modelName = new char[tokens[1].length() + 1];
	strcpy_s(this->modelName, tokens[1].length() + 1, tokens[1].c_str());

	numberOfProducts = stoi(tokens[2]);

	vector <string> tok = splitLine(tokens[3], '-');
	for (int i = 0; i < tok.size(); i++) {
		this->listOfOperators.push_back(tok[i]);
	}
}

string Phone::toString() {
	string string1, string2, string3;
	string1 = this->productionName;
	string2 = this->modelName;
	string3 = this->listOfOperators[0];
	for (int i = 1; i < this->listOfOperators.size(); i++)
	{
		string3 = string3 + "-" + this->listOfOperators[i];
	}
	return  string1 + " " + string2 + " " + to_string(this->numberOfProducts) + " " + string3;
}
string Phone::toStringWithDelimiter(char delimiter) {
	string string1, string2, string3;
	string1 = this->productionName;
	string2 = this->modelName;
	string3 = this->listOfOperators[0];
	for (int i = 1; i < this->listOfOperators.size(); i++)
	{
		string3 = string3 + "-" + this->listOfOperators[i];
	}
	return  string1 + delimiter + string2 + delimiter + to_string(this->numberOfProducts) + delimiter + string3;
}

istream& operator>>(istream& is, Phone& aPhone)
{
	char* productionName = new char[20];
	char* modelName = new char[20];
	char* anOperator = new char[20];
	vector<string> operators;
	int numberOfProducts, numberOfOperators;
	cout << "Give production name: ";
	is >> productionName;
	cout << "Give model name: ";
	is >> modelName;
	cout << "Give number of products: ";
	is >> numberOfProducts;
	cout << "Give number of operators: ";
	is >> numberOfOperators;
	for (int i = 1; i <= numberOfOperators; i += 1)
	{
		cout << "Operator " << i << " is: ";
		is >> anOperator;
		operators.push_back(anOperator);
	}
	aPhone.setProductionName(productionName);
	aPhone.setModelName(modelName);
	aPhone.setNumberOfProducts(numberOfProducts);
	aPhone.setListOfOperators(operators);
	return is;
}