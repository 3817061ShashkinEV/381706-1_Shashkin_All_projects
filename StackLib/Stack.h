#pragma once
#include <iostream>
#include "../MyExceptionLib/MyException.h"

template <class T>
class TStack
{
protected:
  int top;
  int size;
  T* mas;
public:
  TStack(int _size=0);
  TStack(TStack<T> &obj);
  ~TStack();
  void Put(T elem);
  void Clear();
  T Get();
  T ShowTop();
  int GetSize();
  bool IsEmpty();
  bool IsFull();
  TStack<T>& operator=(const TStack<T> &obj);
  int operator!=(const TStack<T>& stack) const;
  int operator==(const TStack<T>& stack) const;
};//TStack
// ---------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(int _size)
{
  if (_size < 0)
    throw TMyException("Error! Size must be positive!\n");
  else if (_size == 0)
  {
    size = 0;
    top = 0;
    mas = NULL;
  }
  else
  {
    size = _size;
    top = 0;
    mas = new T [size];
    for (int i = 0; i < size; i++)
      mas[i] = 0;
  }
}
// ---------------------------------------------------------------------------
template <class T>
TStack<T>::TStack(TStack<T> &obj)
{
  size = obj.size;
  top = obj.top;
  if (size == 0)
    mas = NULL;
  else
  {
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = obj.mas[i];
  }
}
// ---------------------------------------------------------------------------
template <class T>
TStack<T>::~TStack()
{
	if(mas!=0)
		delete[] mas;
	mas = NULL;
}
// ---------------------------------------------------------------------------
template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T> &obj)
{
	if (this != &obj)
	{
		delete[] mas;
		top = obj.top;
		size = obj.size;
		mas = new T[size];
		for (int i = 0; i < size; i++)
			mas[i] = obj.mas[i];
	}
	return *this;
}
// ---------------------------------------------------------------------------
template <class T>
T TStack<T>::ShowTop()
{
	if (IsEmpty())
		throw TMyException("Error! Stack is empty!\n");
	else
		return mas[top - 1];
}
// ---------------------------------------------------------------------------
template <class T>
int TStack<T>::GetSize()
{
	return size;
}
// ---------------------------------------------------------------------------
template <class T>
void TStack<T>::Put(T elem)
{
  if (IsFull())
    throw TMyException("Error! Stack is full!\n");
  else
  {
    mas[top] = elem;
    top++;
  }
}
// ---------------------------------------------------------------------------
template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw TMyException("Error! Stack is empty!\n");
  else
  {
    top--;
    return mas[top];
  }
}
// ---------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsEmpty()
{
  if (top == 0)
    return true;
  else
    return false;
}
// ---------------------------------------------------------------------------
template <class T>
bool TStack<T>::IsFull()
{
  if (top >= size)
    return true;
  else
    return false;
}
// ---------------------------------------------------------------------------
template <class T>
int TStack<T>::operator!=(const TStack<T>& stack) const
{
  return !(*this == stack);
}
// ---------------------------------------------------------------------------
template <class T>
int TStack<T>::operator==(const TStack<T>& stack) const
{
  if (top != stack.top)
    return 0;
  if (size != stack.size)
    return 0;
  for (int i = 0; i < top; i++)
    if (mas[i] != stack.mas[i])
      return 0;
  return 1;
}
// ---------------------------------------------------------------------------
template <class T>
void TStack<T>::Clear()
{
	if (mas != 0)
		delete[] mas;
	mas = NULL;
}