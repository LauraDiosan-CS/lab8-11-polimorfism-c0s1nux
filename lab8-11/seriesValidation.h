#pragma once
#include "series.h"
#include <string>
#include <vector>

using namespace std;

class SeriesException
{
protected:
    vector<string>errors;
public:
    SeriesException(vector<string> _errors);
    vector<string> getErrors() const;
};

class SeriesValidation {
public:
    SeriesValidation() {
    }
    virtual void validateSeries(Series*& );
};