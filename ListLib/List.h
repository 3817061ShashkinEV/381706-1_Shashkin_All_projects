#pragma once
#include <iostream>
#include <Elem.h>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TList
{
protected:
  TElem<T>* begin;
public:
  TList();
  TList(TList<T> &obj);
  void PutBegin(T _elem);
  void PutEnd(T _elem);
  T GetBegin();
  T GetEnd();
  bool IsEmpty();
  bool IsFull();
};//TList
// ---------------------------------------------------------------------------
template <class T>
TList<T>::TList()
{
  begin = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &obj)
{
  TElem<T>* tmp1 = obj.begin;
  TElem<T>* tmp2;
  if (obj.begin == 0)
    begin = 0;
  else
  {
    begin = new TElem<T>(*obj.begin);
    tmp2 = begin;
    while (tmp1->GetNext() != 0)
    {
      tmp2->SetNext(new TElem<T>(*(tmp1->GetNext())));
      tmp1->GetNext();
      tmp2->GetNext();
    }
  }
}
// ---------------------------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T _elem)
{
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
}
// ---------------------------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T _elem)
{
  if (begin != 0)
  {
    TElem<T>* tmp = begin;
    while (tmp->GetNext() != 0)
      tmp = tmp->GetNext();
    tmp->SetNext(new TElem<T>(_elem, 0));
  }
  else
    begin = new TElem<T>(_elem, 0);
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
    begin->TElem<T>::GetNext();
    delete tmp1;
    return tmp2;
  }

}
// ---------------------------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
  if(IsEmpty())
    throw TMyException("Error! List is empty!\n");
  else
  {
    if (begin->TElem<T>::GetNext() == 0)
    {
      T rez = begin->TElem<T>::GetElem();
      begin = begin->TElem<T>::GetNext();
      return rez;
    }
    else
    {
      TElem<T> *tmp1 = begin;
      while (tmp1->GetNext()->GetNext() != 0)
        tmp1 = tmp1->GetNext();
      TElem<T> *tmp2 = tmp1->GetNext();
      T rez = tmp2->GetElem();
      delete tmp2;
      tmp1->SetNext(0);
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
    if (tmp == 0)
      return false;
    else
    {
      delete tmp;
      return true;
    }
  }
  catch (...)
  {
    return false;
  }
}