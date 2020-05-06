#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "series.h"
#include "yo.h"
using namespace std;

class Phone:public Series {
protected:
	vector<string> listOfOperators;
public:
	Phone(); 
	Phone(const Phone&); 
	Phone(const char*, const char*, int, vector<string>); 
	bool operator==(const Phone&);
	vector<string> getListOfOperators(); 
	Series* clone();  
	void setListOfOperators(vector<string>); 
	~Phone();
	Phone& operator= (const Phone&); 
	friend ostream& operator <<(ostream& os, Phone aPhone); 
	friend istream& operator>>(istream& is, Phone& aPhone);
	Phone(string, char); 
	string toString();
	string toStringWithDelimiter(char);
};