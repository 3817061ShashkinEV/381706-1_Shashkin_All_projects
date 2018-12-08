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
  void PutBegin(T _begin);
  void PutEnd(T _end);
  T GetBegin();
  T GetEnd();
  T GetElem(T* _index);
  T* GetIndex(T _elem);
  bool IsEmpty();
  bool IsFull();
};//TList
// ---------------------------------------------------------------------------
template <class T>
TList<T>::TList()
{

}
// ---------------------------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &obj)
{

}
// ---------------------------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T _begin)
{

}
// ---------------------------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T _end)
{

}
// ---------------------------------------------------------------------------
template <class T>
T TList<T>::GetBegin()
{

}
// ---------------------------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{

}
// ---------------------------------------------------------------------------
template <class T>
T TList<T>::GetElem(T* _index)
{

}
// ---------------------------------------------------------------------------
template <class T>
T* TList<T>::GetIndex(T _elem)
{

}
// ---------------------------------------------------------------------------
template <class T>
bool TList<T>::IsEmpty()
{

}
// ---------------------------------------------------------------------------
template <class T>
bool TList<T>::IsFull()
{

}