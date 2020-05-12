#pragma once

#include <list>
#include <iostream>
#include <fstream>
#include "repoTemplate.h"
#include "serializer.h"
#include "repoFile.h"

using namespace std;


template<class T>
class RepositoryFileHTML :public RepositoryFile<T>
{
private:
	const char* fileName;
	Serializer<T>* serializer;
public:
	RepositoryFileHTML();
	~RepositoryFileHTML();
	RepositoryFileHTML(const char*, Serializer<T>*);
	void saveToFile();
	void loadFromFile(const char*);
	int addElem(T);
	int delElem(T);
	int updateElem(T, T);
	int findElem(T);
	list<T> searchByProductionName(char*);
};

template<class T> RepositoryFileHTML<T>::RepositoryFileHTML() :RepositoryFile<T>()
{
	fileName = "";
}

template<class T> RepositoryFileHTML<T>::~RepositoryFileHTML()
{
}
template<class T> RepositoryFileHTML<T>::RepositoryFileHTML(const char* fileName, Serializer<T>* serial)
{
	this->fileName = fileName;
	serializer = serial;
	loadFromFile(fileName);
}

template<class T> void RepositoryFileHTML<T>::saveToFile()
{
	if (this->fileName == NULL)
		return;
	ofstream fout(this->fileName);
	for (T t : this->getAll())
	{
		fout << t->toStringWithDelimiter('/') << "\n";
	}
	fout.close();
}

template<class T> void RepositoryFileHTML<T>::loadFromFile(const char* fileName)
{
	if (fileName == NULL)
		return;
	this->fileName = fileName;
	ifstream fin(this->fileName);
	this->clear();
	string line;
	if (fin.is_open()) {
		while (getline(fin, line))
			RepositoryFile<T>::addElem(serializer->fromString(line, '/'));
		fin.close();
	}
}

template<class T> int RepositoryFileHTML<T>::addElem(T object) {
	int result = RepositoryFile<T>::addElem(object);
	if (result == 1) {
		saveToFile();
		return 1;
	}
	return 2;
}

template<class T> int RepositoryFileHTML<T>::delElem(T object) {
	int result = RepositoryFile<T>::delElem(object);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}
template<class T> int RepositoryFileHTML<T>::updateElem(T oldObject, T newObject)
{
	int result = RepositoryFile<T>::updateElem(oldObject, newObject);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}

template<class T> int RepositoryFileHTML<T>::findElem(T object)
{
	int result = RepositoryFile<T>::findElem(object);
	if (result == -1)
		return -1;
	else
		return result;
}

template<class T> list<T> RepositoryFileHTML<T>::searchByProductionName(char* aProductionName) {
	list<T> goodList = RepositoryFile<T>::searchByProductionName(aProductionName);
	return goodList;
}