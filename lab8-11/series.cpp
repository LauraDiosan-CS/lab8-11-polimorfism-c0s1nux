#include "series.h"
#include <string>
#include <vector>
using namespace std;

Series::Series() {
	productionName = NULL;
	modelName = NULL;
	numberOfProducts = 0;
}

Series::~Series() 
{
}

Series::Series(const Series& aSeries) {
	this->productionName = new char[strlen(aSeries.productionName) + 1];
	strcpy_s(this->productionName, strlen(aSeries.productionName) + 1, aSeries.productionName);
	this->modelName = new char[strlen(aSeries.modelName) + 1];
	strcpy_s(this->modelName, strlen(aSeries.modelName) + 1, aSeries.modelName);
	this->numberOfProducts = aSeries.numberOfProducts;
}

Series::Series(const char* productionName, const char* modelName, int numberOfProducts) {
	this->productionName = new char[strlen(productionName) + 1];
	strcpy_s(this->productionName, strlen(productionName) + 1, productionName);
	this->modelName = new char[strlen(modelName) + 1];
	strcpy_s(this->modelName, strlen(modelName) + 1, modelName);
	this->numberOfProducts = numberOfProducts;
}

char* Series::getProductionName() {
	return this->productionName;
}

char* Series::getModelName() {
	return this->modelName;
}

int Series::getNumberOfProducts() {
	return this->numberOfProducts;
}

void Series::setProductionName(const char* aProductionName) {
	if (this->productionName) {
		delete[] this->productionName;
	}
	this->productionName = new char[strlen(aProductionName) + 1];
	strcpy_s(this->productionName, strlen(aProductionName) + 1, aProductionName);
}

void Series::setModelName(const char* aModel) {
	if (this->modelName) {
		delete[] this->modelName;
	}
	this->modelName = new char[strlen(aModel) + 1];
	strcpy_s(this->modelName, strlen(aModel) + 1, aModel);
}

void Series::setNumberOfProducts(int aNumberOfProducts) {
	this->numberOfProducts = aNumberOfProducts;
}

Series::Series(string line, char delimiter) {
	vector<string> tokens = splitLine(line, delimiter);
	this->productionName = new char[tokens[0].length() + 1];
	strcpy_s(this->productionName, tokens[0].length() + 1, tokens[0].c_str());
	this->modelName = new char[tokens[1].length() + 1];
	strcpy_s(this->modelName, tokens[1].length() + 1, tokens[1].c_str());
	numberOfProducts = stoi(tokens[2]);
}

Series* Series::clone() {
	Series* newSeries = new Series();
	newSeries->setProductionName(this->productionName);
	newSeries->setModelName(this->modelName);
	newSeries->setNumberOfProducts(this->numberOfProducts);
	return newSeries;
}

bool Series::operator==(const Series& aSeries) {
	return (strcmp(productionName, aSeries.productionName) == 0)
		and (strcmp(modelName, aSeries.modelName) == 0)
		and numberOfProducts == aSeries.numberOfProducts;
}

ostream& operator<<(ostream& os, Series aSeries) {
	os << aSeries.getProductionName() << " " << aSeries.getModelName() << " " << aSeries.getNumberOfProducts() << "\n";
	return os;
}

Series& Series::operator =(const Series& aSeries) {
	if (this == &aSeries) return *this;
	if (aSeries.productionName) {
		if (this->productionName)delete[]this->productionName;
		this->productionName = new char[strlen(aSeries.productionName) + 1];
		strcpy_s(this->productionName, strlen(aSeries.productionName) + 1, aSeries.productionName);
	}
	if (aSeries.modelName) {
		if (this->modelName)delete[]this->modelName;
		this->modelName = new char[strlen(aSeries.modelName) + 1];
		strcpy_s(this->modelName, strlen(aSeries.modelName) + 1, aSeries.modelName);
	}
	this->numberOfProducts = aSeries.numberOfProducts;
	return *this;
}

string Series::toString() {
	string string1, string2;
	string1 = this->productionName;
	string2 = this->modelName;
	return  string1 + " " + string2 + " " + to_string(this->numberOfProducts);
}
string Series::toStringWithDelimiter(char delimiter) {
	string string1, string2;
	string1 = this->productionName;
	string2 = this->modelName;
	return  string1 + delimiter + string2 + delimiter + to_string(this->numberOfProducts);
}