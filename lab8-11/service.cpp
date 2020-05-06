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
	seriesValidator.validateSeries(aSeries);
	repository.addElem(aSeries);
	return 1;
}

void Service::delElem(Series*& aSeries) {
	if (repository.findElem(aSeries) == -1) {
		throw exception("Item was not found!\n");
	}
	else {
		repository.delElem(aSeries);
	}
}

void Service::updateElem(Series* oldSeries, Series*& newSeries) {
	seriesValidator.validateSeries(newSeries);
	repository.updateElem(oldSeries, newSeries);
}

void Service::validatePhone(Phone aPhone) {
	phoneValidator.validatePhone(aPhone);
}