#pragma once

#include <sstream>
#include "user.h"
#include "phone.h"
#include "drone.h"
#include "serializer.h"

class SerializerUser :public Serializer<User*> {
public:
	SerializerUser() {}
	~SerializerUser() {}
	inline User* fromString(string, char);
};

User* SerializerUser::fromString(string line, char delim) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	User* u = new User(line, delim);
	return u;
}