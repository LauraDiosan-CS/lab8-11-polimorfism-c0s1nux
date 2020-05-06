#pragma once
#include "repoTemplate.h"
#include "repoFile.h"
#include "user.h"
#include "series.h"
#include "phone.h"
#include "drone.h"
#include "phoneValidation.h"
#include "seriesValidation.h"

class Service
{
private:
	Repository<Series*> repository;
	Repository<User*>& repositoryUser;
	PhoneValidation phoneValidator;
	SeriesValidation seriesValidator;
	User loggedInUser;
public:
	~Service();
	Service(Repository<Series*> r, Repository<User*>& rep) :repository(r), repositoryUser(rep) { repository = r; repositoryUser = rep; };
	bool login(string, string);
	bool loggedIn();
	void logout();
	list<Series*> getAllSeries();
	int getSize();
	Series* getItemFromPos(int);
	int addElem(Series*&);
	void delElem(Series*&);
	void updateElem(Series*, Series*&);
	void validatePhone(Phone);
};