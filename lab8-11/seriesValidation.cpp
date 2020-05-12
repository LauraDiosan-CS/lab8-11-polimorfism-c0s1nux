#include "seriesValidation.h"

using namespace std;

SeriesException::SeriesException(vector<string>_errors) : errors{ _errors } {}
vector<string> SeriesException::getErrors() const {
	return this->errors;
}

void SeriesValidation::validateSeries(Series* &aSeries) {
	vector<string> errors;
	if (aSeries->getNumberOfProducts() < 100) {
		errors.push_back("There must be a minimum of 100 products.\n");
	}
	if (errors.size() > 0)
		throw SeriesException(errors);
}