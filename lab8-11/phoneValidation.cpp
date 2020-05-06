#include "phoneValidation.h"

using namespace std;

PhoneException::PhoneException(vector<string> _errors) : errors{ _errors }
{
}

vector<string> PhoneException::getErrors() const
{
	return this->errors;
}

void PhoneValidation::validatePhone(Phone aPhone) {
	vector<string> errors;
	if (aPhone.getNumberOfProducts() < 100) {
		errors.push_back("There must be a minimum of 100 products.\n");
	}
	if (aPhone.getListOfOperators().size() < 1) {
		errors.push_back("The list of operators must have more than 1 operator.\n");
	}
	if(errors.size() > 0)
		throw PhoneException(errors);
}