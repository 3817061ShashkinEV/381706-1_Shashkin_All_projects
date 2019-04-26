#pragma once
#include <iostream>
#include "MyException.h"

template <class T> 
class TElem
{
protected:
	string key;
	T data;
public:
	TElem(string _key = "", T _data = 0);
	TElem(TElem &obj);
	TElem<T>& operator=(TElem &obj); 
	bool operator==(TElem &obj);
	void SetKey(string _key);
	string GetKey();
	void SetData(T _data);
	T GetData();
	T& GetDataAddress();
};//TElem
// ---------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(string _key, T _data)
{
	key = _key;
	data = _data;
}
// ---------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(TElem &obj)
{
	key = obj.key;
	data = obj.data;
}
// ---------------------------------------------------------------------------
template <class T>
TElem<T>& TElem<T>::operator=(TElem &obj)
{
	if (this != &obj)
	{
		key = obj.key;
		data = obj.data;
	}
	return *this;
}
// ---------------------------------------------------------------------------
template <class T>
bool TElem<T>::operator==(TElem &obj)
{
	if (key != obj.key)
		return 0;
	if (data != obj.data)
		return 0;
	return 1;
}
// ---------------------------------------------------------------------------
template <class T>
void TElem<T>::SetKey(string _key)
{
	key = _key;
}
// ---------------------------------------------------------------------------
template <class T>
string TElem<T>::GetKey()
{
	return key;
}
// ---------------------------------------------------------------------------
template <class T>
void TElem<T>::SetData(T _data)
{
	data = _data;
}
// ---------------------------------------------------------------------------
template <class T>
T TElem<T>::GetData()
{
	return data;
}
// ---------------------------------------------------------------------------
template <class T>
T& TElem<T>::GetDataAddress()
{
	return data;
}