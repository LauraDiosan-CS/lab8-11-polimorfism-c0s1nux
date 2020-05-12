#pragma once
#include <iostream>
#include <fstream>
#include "repoTemplate.h"
#include "serializer.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;
template <class T>
class RepositoryFile : public Repository<T> {
protected:
	const char* fileName;
	char delimiter;
	Serializer<T>* serializer;
public:
	RepositoryFile();
	~RepositoryFile();
	RepositoryFile(const char*, const char, Serializer<T>*);
	void saveToFile();
	int addElem(T);
	void loadFromFile(const char*, const char);
	int delElem(T);
	int updateElem(T, T);
	int findElem(T);
	list<T> searchByProductionName(char*);
};

template <class T> RepositoryFile<T>::RepositoryFile() :Repository<T>()
{
	this->fileName = "";
	delimiter = ' ';
}

template <class T>RepositoryFile<T>::~RepositoryFile()
{
}

template <class T>RepositoryFile<T>::RepositoryFile(const char* fileName, const char delimiter, Serializer<T>* serial) :Repository<T>()
{
	this->fileName = fileName;
	serializer = serial;
	loadFromFile(fileName, delimiter);
}

template<class T> void RepositoryFile<T>::saveToFile()
{
	if (this->fileName == NULL)
		return;
	ofstream fout(this->fileName);
	for (T t : this->getAll())
	{
		fout << t->toStringWithDelimiter(this->delimiter) <<"\n";
	}
	fout.close();
}

template<class T> void RepositoryFile<T>::loadFromFile(const char* fileName, const char delimiter)
{
	if (this->fileName == NULL)
		return;
	this->fileName = fileName;
	this->delimiter = delimiter;
	ifstream fin(this->fileName);
	Repository<T>::clear();
	string line;
	if (fin.is_open()) {
		while (getline(fin, line))
			Repository<T>::addElem(serializer->fromString(line, delimiter));
		fin.close();
	}
}

template<class T> int RepositoryFile<T>::addElem(T object) {
	int result = Repository<T>::addElem(object);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}

template<class T> int RepositoryFile<T>::delElem(T object) {
	int result = Repository<T>::delElem(object);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}

template<class T> int RepositoryFile<T>::updateElem(T oldObject, T newObject)
{
	int result = Repository<T>::updateElem(oldObject, newObject);
	if (result != 2) {
		return 1;
		saveToFile();
	}
	return 2;
}

template<class T> int RepositoryFile<T>::findElem(T object)
{
	int result = Repository<T>::findElem(object);
	if (result == -1)
		return -1;
	else
		return result;
}

template<class T> list<T> RepositoryFile<T>::searchByProductionName(char* aProductionName) {
	list<T> goodList = Repository<T>::searchByProductionName(aProductionName);
	return goodList;
}