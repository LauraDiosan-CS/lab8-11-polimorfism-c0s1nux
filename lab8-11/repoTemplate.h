#pragma once

#include <list>
#include <algorithm> 
#include <iterator>
#include <iostream>
#include "series.h"

using namespace std;

template <class T>class Repository {
protected:
	list<T> elem;
public:
	Repository<T>();
	~Repository();
	virtual int addElem(T);
	list<T> getAll();
	virtual int delElem(T);
	virtual void updateElem(T oldObject, T newObject);
	int findPositionOfElem(T);
	int getSize();
	T getItemFromPos(int);
	void clear();
	int findElem(T);
};



template <class T> Repository<T>::Repository()
{
}

template <class T> Repository<T>::~Repository()
{
}

template<class T> int Repository<T>::addElem(T object)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == object->toString())
		{
			return 2;
		}
	}
	elem.push_back(object->clone());
	return 1;
}

template<class T> list<T> Repository<T>::getAll()
{
	return elem;
}

template<class T> int Repository<T>::delElem(T object)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{

		if ((*it)->toString() == object->toString())
		{
			elem.erase(it);
			return 1;
		}
	}
	return 2;  
}

template<class T> void Repository<T>::updateElem(T oldObject, T newObject)
{
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{

		if ((*it)->toString() == oldObject->toString())
		{
			oldObject = newObject->clone();
		}
	}
}

template<class T> int Repository<T>::findPositionOfElem(T object)
{
	typename list<T>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == object->toString())
		{
			return i;
		}
		i++;
	}
	return -1;
}

template<class T> int Repository<T>::getSize()
{
	return elem.size();
}

template<class T> T Repository<T>::getItemFromPos(int i) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;

	}
	return T();
}

template <class T> void Repository<T>::clear() {
	elem.clear();
}

template<class T> int Repository<T>::findElem(T object)
{
	typename list<T>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == object->toString())
		{
			return i;
		}
		i++;
	}
	return -1;
}