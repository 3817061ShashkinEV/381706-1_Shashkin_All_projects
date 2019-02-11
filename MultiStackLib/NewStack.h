#pragma once
#include <iostream>
#include "Stack.h"
#include <../MyExceptionLib/MyException.h>

template <class T>
class TNewStack :public TStack<T>
{
public:
  TNewStack(int _size, T* _mas);
  TNewStack(TNewStack<T> &obj);
  void SetM(int _size, T* _mas);
  int GetFreeMem();
  int GetSize();
  int GetTop();
  void Put(T _elem);
  T Get();
};//TNewStack
// ---------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas)
{
  if (_size <= 0)
    throw TMyException("Error! Size must be positive!\n");
  else 
  {
    TStack<T>::size = _size;
    TStack<T>::top = 0;
    TStack<T>::mas = _mas;
   
  }
}
// ---------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack(TNewStack<T> &obj)
{
  TStack<T>::size = obj.size;
  TStack<T>::top = obj.top;
  TStack<T>::mas = obj.mas;
}
// ---------------------------------------------------------------------------
template <class T>
void TNewStack<T>::SetM(int _size, T* _mas)
{
  if (_size <= 0)
    throw TMyException("Error! Size must be positive!/n");
  TStack<T>::size = _size;
  TStack<T>::mas = _mas;
}
// ---------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetFreeMem()
{
  return TStack<T>::size - TStack<T>::top;
}
// ---------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetSize()
{
  return TStack<T>::size;
}
// ---------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetTop()
{
  return TStack<T>::top;
}
// ---------------------------------------------------------------------------
template <class T>
void TNewStack<T>::Put(T _elem)
{
  TStack<T>::mas[TStack<T>::top] = _elem;
  TStack<T>::top++;
}
// ---------------------------------------------------------------------------
template <class T>
T TNewStack<T>::Get()
{
  TStack<T>::top--;
  return TStack<T>::mas[TStack<T>::top];
}
