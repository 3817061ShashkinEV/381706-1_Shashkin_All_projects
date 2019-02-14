#pragma once
#include <iostream>
#include "Queue.h"
#include <../MyExceptionLib/MyException.h>

template <class T>
class TArrayList
{
private:
	T* mas;
	int* nextIndex;
	int* prevIndex;
	int size;
	int start;
	int end;
	int count;
	TQueue<int> fElem;
public:
	TArrayList(int _size = 10);
	TArrayList(TArrayList<T> &obj);
	~TArrayList();
	void Put(int _index, T _elem);
	void PutStart(T _elem);
	void PutEnd(T _elem);
	T Get(int _index);
	T GetStart();
	T GetEnd();
	bool IsFull();
	bool IsEmpty();
};//TArrList
// ---------------------------------------------------------------------------
template <class T>
TArrayList<T>::TArrayList(int _size = 10) : fElem(_size)
{
	if (_size <= 0)
		throw TMyException("Error! Size must be positive!\n");
	else
	{
		size = _size;
		count = 0;
		start = -1;
		end = -1;
		mas = new T[size];
		nextIndex = new T[size];
		prevIndex = new T[size];
		for (int i = 0; i < size; i++)
		{
			nextIndex[i] = -2;
			prevIndex[i] = -2;
			fElem.Put(i);
		}
	}
}
// ---------------------------------------------------------------------------
template <class T>
TArrayList<T>::TArrayList(TArrayList<T> &obj)
{
	size = obj.size;
	count = obj.count;
	start = obj.start;
	end = obj.end;
	mas = new T[size];
	nextIndex = new T[size];
	prevIndex = new T[size];
	fElem = obj.fElem;
	for (int i = 0; i < size; i++)
	{
		mas[i] = obj.mas[i];
		nextIndex[i] = obj.nextIndex[i];
		prevIndex[i] = obj.prevIndex[i];
	}
}
// ---------------------------------------------------------------------------
template <class T>
TArrayList<T>::~TArrayList()
{
	delete[] mas;
	delete[] nextIndex;
	delete[] prevIndex;
}
// ---------------------------------------------------------------------------
template <class T>
void TArrayList<T>::Put(int _index, T _elem)
{
	if (IsFull())
		throw TMyException("Error! List is full!\n");
	else if (_index<1 || _index>count - 1)
		throw TMyException("Error! Index is out of range!\n");
	else
	{
		int freeIndex = fElem.Get();
		mas[freeIndex] = _elem;
		int tmp1 = start;
		int tmp2 = nextIndex[start];
		for (int i = 0; i < _index - 1; i++)
		{
			tmp1 = tmp2;
			tmp2 = nextIndex[tmp2];
		}
		nextIndex[freeIndex] = tmp2;
		nextIndex[tmp1] = freeIndex;
		prevIndex[freeIndex] = tmp1;
		prevIndex[tmp2] = freeIndex;
		count++;
	}
}
// ---------------------------------------------------------------------------
template <class T>
void TArrayList<T>::PutStart(T _elem)
{
	if (IsFull())
		throw TMyException("Error! List is full!\n");
	else
	{
		int freeIndex = fElem.Get();
		mas[freeIndex] = _elem;
		nextIndex[freeIndex] = start;
		if (start != -1)
			prevIndex[start] = freeIndex;
		else
			end = freeIndex;
		start = freeIndex;
		count++;
	}
}
// ---------------------------------------------------------------------------
template <class T>
void TArrayList<T>::PutEnd(T _elem)
{
	if (IsFull())
		throw TMyException("Error! List is full!\n");
	else
	{
		int freeIndex = fElem.Get();
		mas[freeIndex] = _elem;
		if (end != -1)
			nextIndex[end] = freeIndex;
		else
		{
			start = freeIndex;
			prevIndex[freeIndex] = -1;
		}
		prevIndex[freeIndex] = end;
		end = freeIndex;
		count++;
	}
}
// ---------------------------------------------------------------------------
template <class T>
T TArrayList<T>::Get(int _index)
{
	if (IsEmpty())
		throw TMyException("Error! List is empty!\n");
	else
	{
		if (_index < 1 || _index>count - 1)
			throw TMyException("Error! Index is out of range!\n");
		else
		{
			int index = start;
			for (int i = 0; i < _index; i++)
				index = nextIndex[index];
			nextIndex[prevIndex[index]] = nextIndex[index];
			prevIndex[nextIndex[index]] = prevIndex[index];
			T tmp = mas[index];
			fElem.Put(index);
			count--;
			return tmp;
		}
	}
}
// ---------------------------------------------------------------------------
template <class T>
T TArrayList<T>::GetStart()
{
	if (IsEmpty())
		throw TMyException("Error! List is empty!\n");
	else
	{
		T elem = mas[start];
		fElem.Put(start);
		int newStart = nextIndex[start];
		nextIndex[start] = prevIndex[start] = -2;
		if (newStart != -1)
			prevIndex[newStart] = -1;
		count--;
		start = newStart;
		return elem;
	}
}
// ---------------------------------------------------------------------------
template <class T>
T TArrayList<T>::GetEnd()
{
	if (IsEmpty())
		throw TMyException("Error! List is empty!\n");
	else
	{
		T elem = mas[end];
		int newEnd = prevIndex[end];
		prevIndex[end] = nextIndex[end] = -2;
		fElem.Put(end);
		end = newEnd;
		if (newEnd != -1)
			nextIndex[newEnd] = -1;
		else
			start = -1;
		count--;
		return elem;
	}
}
// ---------------------------------------------------------------------------
template <class T>
bool TArrayList<T>::IsFull()
{
	if (count == size)
		return true;
	return false;
}
// ---------------------------------------------------------------------------
template <class T>
bool TArrayList<T>::IsEmpty()
{
	if (count == 0)
		return true;
	return false;
}