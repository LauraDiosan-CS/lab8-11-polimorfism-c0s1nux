#pragma once
#include "phone.h"
#include "seriesValidation.h"

class PhoneException
{
private:
	vector<string> errors;

public:
	PhoneException(vector<string>);
	vector<string> getErrors() const;
};

class PhoneValidation : public SeriesValidation {
public:
    PhoneValidation() {
	}
    void validatePhone(Phone);
};