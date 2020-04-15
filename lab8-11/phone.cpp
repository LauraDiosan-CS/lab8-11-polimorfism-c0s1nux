#include "phone.h"

using namespace std;

Phone::Phone() {
	productionName = NULL;
	modelName = NULL;
	numberOfProducts = 0;
	listOfOperators.clear();
}

Phone::Phone(const Phone& aPhone) {
	this->productionName = new char[strlen(aPhone.productionName) + 1];
	strcpy_s(this->productionName, strlen(aPhone.productionName) + 1, aPhone.productionName);
	this->modelName = new char[strlen(aPhone.modelName) + 1];
	strcpy_s(this->modelName, strlen(aPhone.modelName) + 1, aPhone.modelName);
	this->numberOfProducts = aPhone.numberOfProducts;
	vector<string>listOfOperators(aPhone.listOfOperators);
}

Phone::Phone(const char* productionName, const char* modelName, int numberOfProducts, vector<string> listOfOperators) {
	this->productionName = new char[strlen(productionName) + 1];
	strcpy_s(this->productionName, strlen(productionName) + 1, productionName);
	this->modelName = new char[strlen(modelName) + 1];
	strcpy_s(this->modelName, strlen(modelName) + 1, modelName);
	this->numberOfProducts = numberOfProducts;
	this->listOfOperators = listOfOperators;
}

bool Phone::operator==(const Phone& aPhone) {
	return (strcmp(productionName, aPhone.productionName) == 0)
		and (strcmp(modelName, aPhone.modelName) == 0) 
		and numberOfProducts == aPhone.numberOfProducts
		and (aPhone.listOfOperators == listOfOperators);
}

char* Phone::getProductionName() {
	return this->productionName;
}

char* Phone::getModelName() {
	return this->modelName;
}

int Phone::getNumberOfProducts() {
	return this->numberOfProducts;
}

vector<string> Phone::getListOfOperators() {
	return this->listOfOperators;
}

void Phone::setProductionName(const char* aProductionName) {
	if (productionName) {
		delete[]productionName;
		productionName = NULL;
	}
	productionName = new char[strlen(aProductionName) + 1];
	strcpy_s(this->productionName, strlen(aProductionName) + 1, aProductionName);
}

void Phone::setModelName(const char* aModelName) {
	if (modelName) {
		delete[]modelName;
		modelName = NULL;
	}
	modelName = new char[strlen(aModelName) + 1];
	strcpy_s(this->modelName, strlen(aModelName) + 1, aModelName);
}

void Phone::setNumberOfProducts(int aNumberOfProducts) {
	this->numberOfProducts = aNumberOfProducts;
}

void Phone::setListOfOperators(vector<string> aListOfOperators) {
	if (!listOfOperators.empty()) {
		listOfOperators.clear();
	}
	vector<string>listOfOperators(listOfOperators);
}

Phone::~Phone() {
	if (productionName) {
		delete[] productionName;
		productionName = NULL;
	}

	if (modelName) {
		delete[] modelName;
		modelName = NULL;
	}

	numberOfProducts = 0;

	if (!listOfOperators.empty()) {
		listOfOperators.clear();
	}
}