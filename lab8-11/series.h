#pragma once
#include <iostream>
#include <string>
#include "yo.h"
using namespace std;

class Series {
protected:
	char* productionName;
	char* modelName;
	int numberOfProducts;
public:
	Series();
	virtual ~Series();
	Series(const Series&);
	Series(const char*, const char*, int);

	char* getProductionName();
	char* getModelName();
	int getNumberOfProducts();
	void setProductionName(const char*);
	void setModelName(const char*);
	void setNumberOfProducts(int);
	Series(string, char);
	virtual Series* clone();
	virtual bool operator==(const Series&);
	friend ostream& operator <<(ostream& os, Series);
	virtual Series& operator= (const Series&);
	virtual string toString();
	virtual string toStringWithDelimiter(char);
};