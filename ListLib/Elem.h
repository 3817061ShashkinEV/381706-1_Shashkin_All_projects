#pragma once
#include <iostream>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TElem
{
protected:
  T elem;
  TElem<T>* next;
public:
  TElem(T _elem = 0, TElem<T>* _next = 0);
  TElem(TElem<T> &obj);
  T GetElem();
  TElem<T>* GetNext();
  void SetElem(T _elem);
  void SetNext(TElem<T>* _next);
};//TElem
// ---------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(T _elem, TElem<T>* _next)
{
  elem = _elem;
  next = _next;
}
// ---------------------------------------------------------------------------
template <class T>
TElem<T>::TElem(TElem<T> &obj)
{
  elem = obj.elem;
  next = obj.next;
}
// ---------------------------------------------------------------------------
template <class T>
T TElem<T>::GetElem()
{
  return elem;
}
// ---------------------------------------------------------------------------
template <class T>
TElem<T>* TElem<T>::GetNext()
{
  return next;
}
// ---------------------------------------------------------------------------
template <class T>
void TElem<T>::SetElem(T _elem)
{
  elem = _elem;
}
// ---------------------------------------------------------------------------
template <class T>
void TElem<T>::SetNext(TElem<T>* _next)
{
  next = _next;
}
