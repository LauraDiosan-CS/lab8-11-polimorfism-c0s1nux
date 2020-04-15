#pragma once

class Drone {
protected:
	char* productionName;
	char* modelName;
	int numberOfProducts;
	int numberOfRotors;
public:
	Drone();
	Drone(const Drone&);
	Drone(const char*, const char*, int, int);
	bool operator==(const Drone&);
	char* getProductionName();
	char* getModelName();
	int getNumberOfProducts();
	int getNumberOfRotors();
	void setProductionName(const char*);
	void setModelName(const char*);
	void setNumberOfProducts(int);
	void setNumberOfRotors(int);
	~Drone();
};