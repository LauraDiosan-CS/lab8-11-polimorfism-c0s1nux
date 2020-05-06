#pragma once

#include <list>
#include "serializer.h"
#include <iostream>
#include <fstream>
#include "repoTemplate.h"
#include "repoFile.h"

using namespace std;


template<class T>
class RepositoryFileCSV :public Repository<T>
{
private:
	const char* fileName;
	Serializer<T>* serializer;
public:
	RepositoryFileCSV();
	~RepositoryFileCSV();
	RepositoryFileCSV(const char*, Serializer<T>*);
	void saveToFile();
	void loadFromFile(const char*);
	int addElem(T&);
	int delElem(T&);
	void updateElem(T, T&);
};

template<class T> RepositoryFileCSV<T>::RepositoryFileCSV() :Repository<T>()
{
	fileName = "";
}

template<class T> RepositoryFileCSV<T>::~RepositoryFileCSV()
{
}
template<class T> RepositoryFileCSV<T>::RepositoryFileCSV(const char* fileName, Serializer<T>* serial)
{
	this->fileName = fileName;
	serializer = serial;
	loadFromFile(fileName);
}

template<class T> void RepositoryFileCSV<T>::saveToFile()
{
	if (this->fileName == NULL)
		return;
	ofstream fout(this->fileName);
	for (T t : this->getAll())
	{
		fout << t.toStringWithDelimiter(",") << "\n";
	}
	fout.close();
}

template<class T> void RepositoryFileCSV<T>::loadFromFile(const char* fileName)
{
	if (fileName == NULL)
		return;
		this->fileName = fileName;
		ifstream fin(this->fileName);
		Repository<T>::clear();
		string line;
		if (fin.is_open()) {
			while (getline(fin, line))
				Repository<T>::addElem(serializer->fromString(line, ','));;
			fin.close();
		}
}

template<class T> int RepositoryFileCSV<T>::addElem(T& object) {
	int result = Repository<T>::addElem(object);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}

template<class T> int RepositoryFileCSV<T>::delElem(T& object) {
	int result = Repository<T>::delElem(object);
	if (result != 2) {
		saveToFile();
		return 1;
	}
	return 2;
}
template<class T> void RepositoryFileCSV<T>::updateElem(T oldObject, T& newObject)
{
	Repository<T>::updateElem(oldObject, newObject);
	saveToFile();
}