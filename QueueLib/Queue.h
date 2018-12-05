#pragma once
#include <iostream>
#include <Stack.h>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TQueue : public TStack<T>
{
protected:
  int start;
  int count;
public:
  TQueue(int _size = 0);
  TQueue(TQueue<T> &obj);
  void Put(T elem);
  T Get();
  bool IsEmpty();
  bool IsFull();
};//TQueue
// ---------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(int _size) :TStack<T>(_size)
{
  start = 0;
  count = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(TQueue<T> &obj) :TStack<T>(obj)
{
  start = obj.start;
  count = obj.count;
}
// ---------------------------------------------------------------------------
template <class T>
void TQueue<T>::Put(T elem)
{
  if (IsFull())
    throw TMyException("Error! Queue is full!\n");
  else
  {
    TStack<T>::mas[start] = elem;
    start = (start + 1) % TStack<T>::size;
    count++;
  }
}
// ---------------------------------------------------------------------------
template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw TMyException("Error! Queue is empty!\n");
  else
  {
    T tmp = TStack<T>::mas[TStack<T>::top];
    TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::size;
    count--;
    return tmp;
  }
}
// ---------------------------------------------------------------------------
template <class T>
bool TQueue<T>::IsEmpty()
{
  if (count == 0)
    return true;
  else
    return false;
}
// ---------------------------------------------------------------------------
template <class T>
bool TQueue<T>::IsFull()
{
  if (count == TStack<T>::size)
    return true;
  else
    return false;
}