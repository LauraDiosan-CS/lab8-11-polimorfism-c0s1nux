#include "drone.h"
#include <iostream>
#include <cstring>

using namespace std;

Drone::Drone() {
	productionName = NULL;
	modelName = NULL;
	numberOfProducts = 0;
	numberOfRotors = 0;
}

Drone::Drone(const Drone& aDrone) {
	this->productionName = new char[strlen(aDrone.productionName) + 1];
	strcpy_s(this->productionName, strlen(aDrone.productionName) + 1, aDrone.productionName);
	this->modelName = new char[strlen(aDrone.modelName) + 1];
	strcpy_s(this->modelName, strlen(aDrone.modelName) + 1, aDrone.modelName);
	this->numberOfProducts = aDrone.numberOfProducts;
	this->numberOfRotors = aDrone.numberOfRotors;
}

Drone::Drone(const char* productionName, const char* modelName, int numberOfProducts, int numberOfRotors) {
	this->productionName = new char[strlen(productionName) + 1];
	strcpy_s(this->productionName, strlen(productionName) + 1, productionName);
	this->modelName = new char[strlen(modelName) + 1];
	strcpy_s(this->modelName, strlen(modelName) + 1, modelName);
	this->numberOfProducts = numberOfProducts;
	this->numberOfRotors = numberOfRotors;
}

bool Drone::operator==(const Drone& aDrone) {
	return (strcmp(productionName, aDrone.productionName) == 0)
		and (strcmp(modelName, aDrone.modelName) == 0)
		and numberOfProducts == aDrone.numberOfProducts
		and (aDrone.numberOfRotors == numberOfRotors);
}

char* Drone::getProductionName() {
	return this->productionName;
}

char* Drone::getModelName() {
	return this->modelName;
}

int Drone::getNumberOfProducts() {
	return this->numberOfProducts;
}

int Drone::getNumberOfRotors() {
	return this->numberOfRotors;
}

void Drone::setProductionName(const char* aProductionName) {
	if (productionName) {
		delete[]productionName;
		productionName = NULL;
	}
	productionName = new char[strlen(aProductionName) + 1];
	strcpy_s(this->productionName, strlen(aProductionName) + 1, aProductionName);
}

void Drone::setModelName(const char* aModelName) {
	if (modelName) {
		delete[]modelName;
		modelName = NULL;
	}
	modelName = new char[strlen(aModelName) + 1];
	strcpy_s(this->modelName, strlen(aModelName) + 1, aModelName);
}

void Drone::setNumberOfProducts(int aNumberOfProducts) {
	this->numberOfProducts = aNumberOfProducts;
}

void Drone::setNumberOfRotors(int aNumberOfRotors) {
	this->numberOfRotors = aNumberOfRotors;
}

Drone::~Drone() {
	if (productionName) {
		delete[] productionName;
		productionName = NULL;
	}

	if (modelName) {
		delete[] modelName;
		modelName = NULL;
	}

	numberOfProducts = 0;
	numberOfRotors = 0;
}