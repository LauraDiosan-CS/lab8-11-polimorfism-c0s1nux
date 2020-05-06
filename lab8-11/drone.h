#pragma once

#include "series.h"
#include "yo.h"
using namespace std;

class Drone:public Series {
protected:
	int numberOfRotors;
public:
	Drone();
	Drone(const Drone&);
	Drone(const char*, const char*, int, int);
	bool operator==(const Drone&);
	int getNumberOfRotors();
	void setNumberOfRotors(int);
	~Drone();
	Drone& operator= (const Drone&);
	friend ostream& operator <<(ostream& os, Drone aDrone);
	friend istream& operator>>(istream& is, Drone& aDrone);
	Drone(string, char);
	void fromString(string, char);
	string toString();
	string toStringWithDelimiter(char);
	Series* clone();
};