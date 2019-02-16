#pragma once
#include "List.h"
#include "MyException.h"

template <class T>
class TStackList : public TList<T>
{
protected:
	int len;
public:
	TStackList(int _len = 5);
	TStackList(TStackList<T> &obj);
	void Put(T elem);
	T Get();
	int GetSize();
	int GetMaxSize();
	bool IsFull();
	bool IsEmpty();
};//TStackList
// ---------------------------------------------------------------------------
template <class T>
TStackList<T>::TStackList(int _len) : TList<T>()
{
	if (_len <= 0)
		throw TMyException("Error! Incorrect size!\n");
	len = _len;
}
// ---------------------------------------------------------------------------
template <class T>
TStackList<T>::TStackList(TStackList<T> &obj)
{
	TList<T>::size = obj.size;
}
// ---------------------------------------------------------------------------
template <class T>
void TStackList<T>::Put(T elem)
{
	if (this->IsFull())
		throw TMyException("Error! StackList is full!\n");
	TList<T>::PutBegin(elem);
}
// ---------------------------------------------------------------------------
template <class T>
T TStackList<T>::Get()
{
	if (this->IsEmpty())
		throw TMyException("Error! StackList is empty!\n");
	return TList<T>::GetBegin();
}
// ---------------------------------------------------------------------------
template <class T>
int TStackList<T>::GetSize()
{
	return TList<T>::size;
}
// ---------------------------------------------------------------------------
template <class T>
int TStackList<T>::GetMaxSize()
{
	return len;
}
// ---------------------------------------------------------------------------
template <class T>
bool TStackList<T>::IsFull()
{
	if (TList<T>::size == len)
		return true;
	return false;
}
// ---------------------------------------------------------------------------
template <class T>
bool TStackList<T>::IsEmpty()
{
	if (TList<T>::size == 0)
		return true;
	return false;
}