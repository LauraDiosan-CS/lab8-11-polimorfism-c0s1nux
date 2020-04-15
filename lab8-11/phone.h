#pragma once
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Phone {
protected:
	char* productionName;
	char* modelName;
	int numberOfProducts;
	vector<string> listOfOperators;
public:
	Phone();
	Phone(const Phone&);
	Phone(const char*, const char*, int, vector<string>);
	bool operator==(const Phone&);
	char* getProductionName();
	char* getModelName();
	int getNumberOfProducts();
	vector<string> getListOfOperators();
	void setProductionName(const char*);
	void setModelName(const char*);
	void setNumberOfProducts(int);
	void setListOfOperators(vector<string>);
	~Phone();
};