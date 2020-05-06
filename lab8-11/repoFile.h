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
	void loadFromFile(const char*, const char);
	int addElem( T&);
	int delElem( T&);
	void updateElem(T, T&);
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
		fout << t.toStringWithDelimiter(this->delimiter) <<"\n";
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

template<class T> int RepositoryFile<T>::addElem(T& object) {
	int result = Repository<T>::addElem(object);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}

template<class T> int RepositoryFile<T>::delElem(T& object) {
	int result = Repository<T>::delElem(object);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}

template<class T> void RepositoryFile<T>::updateElem(T oldObject, T& newObject)
{
	Repository<T>::updateElem(oldObject, newObject);
	saveToFile();
}
