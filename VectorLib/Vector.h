#pragma once
#include <iostream>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TVector
{
protected:
  T* vector;
  int size;
  int StartIndex;
public:
  TVector(int _size=10, int _StartIndex=0);
  TVector(TVector<T> &obj);
  ~TVector();
  int GetSize();
  int GetStartIndex();
  T& operator[] (int index);
  bool operator==(const TVector<T> &obj);
  TVector<T>& operator=(const TVector<T> &obj);
  //Scalar operations
  TVector<T>& operator+(const T &Scalar);
  TVector<T>& operator-(const T &Scalar);
  TVector<T>& operator*(const T &Scalar);
  //Vector operations
  TVector<T> operator+(const TVector<T> &obj);
  TVector<T> operator-(const TVector<T> &obj);
  T operator*(const TVector<T> &obj);
	
	
  template <class T1>
  friend std::istream& operator >> (std::istream &A, TVector<T> &B);
	
  template <class T1>
  friend std::ostream& operator << (std::ostream &A, TVector<T> &B);
}; //TVector
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(int _size, int _StartIndex)
{
  if (_size > 0)
    if (_StartIndex >= 0 && _StartIndex<_size)
    {
      vector = new T[_size];
      size = _size;
      for (int i = 0; i < size; i++)
        vector[i] = 0;
      StartIndex = _StartIndex;
    }
    else
      throw TMyException("Error! Start index should not be negative or large than size!\n");
  else
    throw TMyException("Error! Size of vector must be positive!\n");
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(TVector &obj)
{
  size = obj.size;
  if (size != 0)
  {
    vector = new T[size];
    for (int i = 0; i < size; i++)
      vector[i] = obj.vector[i];
  }
  else
    vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::~TVector()
{
  if (vector != 0)
	  delete[] vector;
  vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetSize()
{
	return size;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetStartIndex()
{
  return StartIndex;
}
// ---------------------------------------------------------------------------
template <class T>
T& TVector<T> ::operator[] (int index)
{
  if (index >= 0 && index < size)
    return vector[index];
  throw TMyException("Error! Index is out of range!\n");
}
// ---------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator==(const TVector<T> &obj)
{
  if (size != obj.size)
    throw TMyException("Error! Vectors have different sizes!\n)");
  else
  {
    for (int i = 0; i < size; i++)
      if (vector[i] != obj.vector[i])
        return false;
  }
  return true;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &obj)
{
  if (this != &obj)
  {
    size = obj.size;
    if (size != 0)
    {
      if (vector != 0)
        delete[] vector;
      vector = new T[size];
      for (int i = 0; i < size; i++)
        vector[i] = obj.vector[i];
    }
    else
    {
      if (vector != 0)
        delete[]vector;
      vector = 0;
    }
  }
  return *this;
}
// ---------------------------------------------------------------------------
//Scalar operations
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator+(const T &Scalar)
{
  if (size == 0)
    vector = 0;
  else
  {
    for (int i = 0; i < size; i++)
      vector[i] += Scalar;
  }
  return *this;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator-(const T &Scalar)
{
  if (size == 0)
    vector = 0;
  else
  {
    for (int i = 0; i < size; i++)
      vector[i] -= Scalar;
  }
  return *this;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator*(const T &Scalar)
{
  
  if (size == 0)
    vector = 0;
  else
  {
    for (int i = 0; i < size; i++)
      vector[i] *= Scalar;
  }
  return *this;
}
// ---------------------------------------------------------------------------
//Vector operations
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &obj)
{
  TVector<T> rez;
  if (size == obj.size)
  {
    if (size == 0)
      rez.vector = 0;
    else
    {
      rez.size = size;
      rez.vector = new T[rez.size];
      for (int i = 0; i < rez.size; i++)
        rez.vector[i] = vector[i] + obj.vector[i];
    }
  }
  else
    throw TMyException("Error! Vectors have different sizes!\n");
  return rez;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &obj)
{
  TVector<T> rez;
  if (size == obj.size)
  {
    if (size == 0)
      rez.vector = 0;
    else
    {
      rez.size = size;
      rez.vector = new T[rez.size];
      for (int i = 0; i < rez.size; i++)
        rez.vector[i] = vector[i] - obj.vector[i];
    }
  }
  else
    throw TMyException("Error! Vectors have different sizes!\n");;
  return rez;
}
// ---------------------------------------------------------------------------
template <class T>
T TVector<T>::operator*(const TVector<T> &obj)
{
  T rez=0;
  if (size == obj.size)
  {
    if (size == 0)
      rez=0;
    else
    {
      for (int i = 0; i < size; i++)
        rez += (vector[i] * obj.vector[i]);
    }
  }
  else
    throw TMyException("Error! Vectors have different sizes!\n");;
  return rez;
}
// ---------------------------------------------------------------------------
template <class T>
std::istream& operator >> (std::istream &istr, TVector<T> &Vec)
{
  std::cout << "Enter vector size: ";
  istr >> Vec.size;
  Vec.vector = new T[Vec.size];
  std::cout << "Set the vector elementwise : ";
  for (int i = 0; i<Vec.size; i++)
    istr >> Vec.vector[i];
  return istr;
}
// ---------------------------------------------------------------------------
template <class T>
std::ostream& operator << (std::ostream &ostr, TVector<T> &Vec)
{
  ostr << "Size of vector: " << Vec.size << "\n";
  ostr << "The Vector: (";
  for (int i = 0; i<Vec.size-1; i++)
    ostr << Vec.vector[i] << ",";
  ostr << Vec.vector[Vec.size - 1];
  ostr << ")";
  return ostr;
}
