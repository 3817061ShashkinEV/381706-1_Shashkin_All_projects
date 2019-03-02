#pragma once
#include <iostream>
#include <Elem.h>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TList
{
protected:
  TElem<T>* begin;
  int size;
public:
  TList();
  TList(TList<T> &obj);
  void PutBegin(T _elem);
  void PutEnd(T _elem);
  void PutElem(int _index, T _elem);
  T GetBegin();
  T GetEnd();
  T GetElem(int _index);
  bool IsEmpty();
  bool IsFull();
};//TList
// ---------------------------------------------------------------------------
template <class T>
TList<T>::TList()
{
  begin = 0;
  size = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &obj)
{
  TElem<T>* tmp1 = obj.begin;
  TElem<T>* tmp2;
  if (obj.begin == 0)
  {
    begin = 0;
    size = 0;
  }
  else
  {
    size = obj.size;
    begin = new TElem<T>(*obj.begin);
    tmp2 = begin;
    while (tmp1->GetNext() != 0)
    {
      tmp2->SetNext(new TElem<T>(*(tmp1->GetNext())));
      tmp1=tmp1->GetNext();
      tmp2=tmp2->GetNext();
    }
  }
}
// ---------------------------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T _elem)
{
	if (this->IsFull())
		throw TMyException("Error! List is full!\n");
  if (begin == 0)
  {
    TElem<T>* tmp = new TElem<T>(_elem, 0);
    begin = tmp;
  }
  else
  {
    TElem<T>* tmp= new TElem<T>(_elem, begin);
    begin = tmp;
  }
  size++;
}
// ---------------------------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T _elem)
{
	if (this->IsFull())
		throw TMyException("Error! List is full!\n");
  if (begin != 0)
  {
    TElem<T>* tmp = begin;
    while (tmp->GetNext() != 0)
      tmp = tmp->GetNext();
    tmp->SetNext(new TElem<T>(_elem, 0));
  }
  else
    begin = new TElem<T>(_elem, 0);
  size++;
}
// ---------------------------------------------------------------------------
template <class T>
void TList<T>::PutElem(int _index, T _elem)
{
	if (this->IsFull())
		throw TMyException("Error! List is full!\n");
  if (_index < 1 || _index > size-1)
    throw("Error! Index is out of range!\n");
  else
  {
    TElem<T>* tmp = begin;
    int i = 0;
    while (i != _index - 1)
    {
      tmp->GetNext();
      i++;
    }
    TElem<T>* rez = new TElem<T>(_elem, tmp->GetNext());
    tmp->SetNext(rez);
    size++;
  }
}
// ---------------------------------------------------------------------------
template <class T>
T TList<T>::GetBegin()
{
  if (IsEmpty())
    throw TMyException("Error! List is empty!\n");
  else
  {
    TElem<T>* tmp1 = begin;
    T tmp2 = begin->TElem<T>::GetElem();
    begin=begin->TElem<T>::GetNext();
    delete tmp1;
    size--;
    return tmp2;
  }
}
// ---------------------------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
	if (IsEmpty())
		throw TMyException("Error! List is empty!\n");
	else
	{
		size--;
		TElem<T>* tmp1 = begin;
		TElem<T>* tmp2 = begin->GetNext();
		if (tmp2 == 0)
		{
			T tmp3 = tmp1->TElem<T>::GetElem();
			delete tmp1;
			begin = 0;
			return tmp3;
		}
		else
		{
			while (tmp2->GetNext() != 0)
			{
				tmp1 = tmp2;
				tmp2 = tmp2->GetNext();
			}
			T tmp3 = tmp2->GetElem();
			delete tmp2;
			tmp1->SetNext(0);
			return tmp3;
		}
	}
}
// ---------------------------------------------------------------------------
template <class T>
T TList<T>::GetElem(int _index) 
{
  if (IsEmpty())
    throw TMyException("Error! List is empty!/n");
  else
  {
    if (_index < 1 || _index > size-1)
      throw TMyException("Error! Index is out of range!/n");
    else
    {
      int i = 0;
			size--;
      TElem<T> *tmp1 = begin;
      TElem<T> *tmp2 = begin->GetNext();
      while (i != _index-1)
      {
        tmp1 = tmp2;
        tmp2 = tmp2->GetNext();
        i++;
      }
      T rez = tmp2->GetElem();
      tmp1->SetNext(tmp2->GetNext());
      delete tmp2;
      return rez;
    }
  }
}
// ---------------------------------------------------------------------------
template <class T>
bool TList<T>::IsEmpty()
{
  if (begin == 0)
    return true;
  else
    return false;
}
// ---------------------------------------------------------------------------
template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TElem<T>* tmp = new TElem<T>();
		if (tmp == NULL)
			return true;
		else
		{
			delete tmp;
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}