#pragma once
#include "NewStack.h"
#include "MyException.h"

template <class T>
class TMStack
{
protected:
  int n;
  int size;
  T* mas;
  TNewStack<T>** mStack;
  int CountFree();
  void Repack(int _num);
public:
  TMStack(int _n = 1, int _size = 5);
  TMStack(TMStack<T> &obj);
	~TMStack();
  int GetSize();
  void SetElem(int _n, T _elem);
  T GetElem(int _n);
  bool IsFull(int _n);
  bool IsEmpty(int _n);
};//TMStack
// ---------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(int _n, int _size)
{
  if (_n <= 0 || _size <= 0)
    throw TMyException("Error! Incorrect size or number of stack! \n");
  else
  {
    n = _n;
    size = _size;
		mStack = new TNewStack<T>*[n];
    mas = new T[size];
    int* tmp1 = new int[n];
    for (int i = 0; i < n; i++)
      tmp1[i] = size / n;
    tmp1[0] += size % n;
		T** tmp2 = new T*[n];
    tmp2[0] = mas;
    for (int i = 1; i < n; i++)
      tmp2[i] = tmp2[i - 1] + tmp1[i - 1];
    for (int i = 0; i < n; i++)
      mStack[i] = new TNewStack<T>(tmp1[i], tmp2[i]);
  }
}
// ---------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(TMStack<T> &obj)
{
  n = obj.n;
  size = obj.size;
  if (size == 0)
  {
    mas = NULL;
    mStack = NULL;
  }
  else
  {
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = obj.mas[i];
    mStack = new TNewStack<T>*[n];
    int* tmp1 = new int[n];
    for (int i = 0; i < n; i++)
      tmp1[i] = obj.mStack[i]->GetSize();
		T** tmp2 = new T*[n];
    tmp2[0] = mas;
    for (int i = 0; i < n; i++)
      tmp2[i] = tmp1[i - 1] + tmp2[i - 1];
    for (int i = 0; i < n; i++)
    {
      mStack[i] = new TNewStack<T>(*obj.mStack[i]);
      mStack[i]->SetM(tmp1[i], tmp2[i]);
    }
  }
}
// ---------------------------------------------------------------------------
template <class T>
TMStack<T>::~TMStack()
{
	if (mas != 0)
		delete[] mas;
	mas = NULL;
}
// ---------------------------------------------------------------------------
template <class T>
int TMStack<T>::GetSize()
{
  return size;
}
// ---------------------------------------------------------------------------
template <class T>
void TMStack<T>::SetElem(int _n, T _elem)
{
  if (_n < 0 || _n >= n)
    throw TMyException("Error! Index is out of range!\n");
	else if (this->CountFree() == 0)
		throw TMyException("Error! No free mem!\n");
  else if (IsFull(_n))
    Repack(_n);
  mStack[_n]->PutElem(_elem);
}
// ---------------------------------------------------------------------------
template <class T>
T TMStack<T>::GetElem(int _n)
{
  if (_n < 0 || _n >= n)
    throw TMyException("Error! Index is out of range!\n");
  if (IsEmpty(_n))
    throw TMyException("Error! MultiStack is empty!\n");
  return mStack[_n]->Get();
}
// ---------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsFull(int _n)
{
  if (_n < 0 || _n >= n)
    throw TMyException("Error! Index is out of range!\n");
  else
    return (mStack[_n]->GetFreeMem() == 0);
}
// ---------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsEmpty(int _n)
{
  if (_n < 0 || _n >= n)
    throw TMyException("Error! Index is out of range!\n");
  else
    return (mStack[_n]->GetFreeMem() == mStack[_n]->GetSize());
}
// ---------------------------------------------------------------------------
template <class T>
int TMStack<T>::CountFree()
{
  int count = 0;
  for (int i = 0; i < n; i++)
    count += mStack[i]->GetFreeMem();
  return count;
}
// ---------------------------------------------------------------------------
template <class T>
void TMStack<T>::Repack(int _num)
{
	int fMem = CountFree();
	int addEv = fMem / n;
	int addFull = fMem % n;
	int* newSize = new int[n];
	T** newStart = new T*[n];
	T** oldStart = new T*[n];
	for (int i = 0; i < n; i++)
		newSize[i] = addEv + mStack[i]->GetTop();
	newSize[_num] += addFull;
	newStart[0] = oldStart[0] = mas;
	for (int i = 1; i < n; i++)
	{
		newStart[i] = newStart[i - 1] + newSize[i - 1];
		oldStart[i] = oldStart[i - 1] + mStack[i - 1]->GetSize();
	}
	for (int i = 0; i < n; i++)
	{
		if (newStart[i] <= oldStart[i])
			for (int j = 0; j < mStack[i]->GetTop(); j++)
				newStart[i][j] = oldStart[i][j];
		else
		{
			int s;
			for (s = i + 1; s < n; s++)
				if (newStart[s] <= oldStart[s])
					break;
			for (int j = n - 1; j >= i; j--)
				for (int r = mStack[j]->GetTop() - 1; r >= 0; r--)
					newStart[j][r] = oldStart[j][r];
			i = s - 1;
		}
	}
	for (int i = 0; i < n; i++)
		mStack[i]->SetM(newSize[i], newStart[i]);
	delete[] newSize;
	delete[] newStart;
	delete[] oldStart;
}
