#include "service.h"
#include "user.h"
#include "seriesValidation.h"
#include "phoneValidation.h"

Service::~Service()
{
}

bool Service::login(string user, string pass)
{
	User* userr = new User(user, pass);
	this->loggedInUser = (*userr);
	return ((repositoryUser.findElem(userr) != -1) and (!this->loggedInUser.getUsername().empty()));
}

bool Service::loggedIn() {
	return !this->loggedInUser.getUsername().empty();
}
void Service::logout()
{
	this->loggedInUser.setUsername("");
	this->loggedInUser.setPassword("");
}

list<Series*> Service::getAllSeries()
{
	return repository.getAll();
}

int Service::getSize() {
	return repository.getSize();
}

Series* Service::getItemFromPos(int i) {
	return repository.getItemFromPos(i);
}

int Service::addElem(Series*& aSeries) {
	int result = repository.addElem(aSeries);
	return result;
}

int Service::delElem(Series*& aSeries) {
	if (repository.findElem(aSeries) == -1) {
		return -1;
	}
	else {
		int result = repository.delElem(aSeries);
		return result;
	}
}

int Service::updateElem(Series*& oldSeries, Series* newSeries) {
	int result = repository.updateElem(oldSeries, newSeries);
	return result;
}

void Service::validatePhone(Phone aPhone) {
	phoneValidator.validatePhone(aPhone);
}

list<Series*> Service::searchByProductionName(char* aProductionName) {
	return repository.searchByProductionName(aProductionName);
}

int Service::findPositionOfElem(Series* aSeries) {
	return repository.findElem(aSeries);
}

void Service::validateSeries(Series* aSeries) {
	seriesValidator.validateSeries(aSeries);
}