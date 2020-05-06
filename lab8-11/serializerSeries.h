#pragma once
#include <sstream>
#include "series.h"
#include "phone.h"
#include "drone.h"
#include "serializer.h"
class SerializerSeries :public Serializer<Series*> {
public:
	SerializerSeries() {}
	~SerializerSeries() {}
	inline Series* fromString(string, char);
};

Series* SerializerSeries::fromString(string line, char delimiter) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delimiter)) {
		tokens.push_back(item);
	}
	if (tokens.size() == 4) {
		try {
			int i = stoi(tokens[3]);
			Series* d = new Drone(line, delimiter);
			return d;
		}
		catch (...) {
			Series* d = new Phone(line, delimiter);
			return d;
		}
	}
}