#pragma once
#include <iostream>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TVector
{
protected:
  T* vector;
  int size;
public:
  TVector(int _size=10);
  TVector(TVector<T> &obj);
  ~TVector();
  int GetSize();
  T& operator[] (int index);
  bool operator==(const TVector<T> &obj);
  TVector<T>& operator=(const TVector<T> &obj);
  //Scalar operations
  TVector<T> operator+(const T &Scalar);
  TVector<T> operator-(const T &Scalar);
  TVector<T> operator*(const T &Scalar);
  //Vector operations
  TVector<T> operator+(const TVector<T> &obj);
  TVector<T> operator-(const TVector<T> &obj);
  T operator*(const TVector<T> &obj);
	
  template <class T1>
  friend std::istream& operator >> (std::istream &istr, TVector<T1> &vec);

  template <class T1>
  friend std::ostream& operator << (std::ostream &ostr, TVector<T1> &vec);
}; //TVector
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(int _size)
{
  if (_size >= 0)
  {
    if (_size == 0)
    {
      size = 0;
      vector = NULL;
    }
    else
    {
      size = _size;
      vector = new T[size];
      for (int i = 0; i < size; i++)
      {
        vector[i] = 0;
      }
    }
  }
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
    vector = NULL;
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
    return false;
  else
  {
    for (int i = 0; i < size; i++)
      if (!(this->vector[i] == obj.vector[i]))
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
TVector<T> TVector<T>::operator+(const T &scalar)
{
  TVector<T> rez(size);
  if (size == 0)
    vector = 0;
  else
  {
    for (int i = 0; i < size; i++)
      rez.vector[i] =vector[i] + scalar;
  }
  return rez;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(const T &scalar)
{
  TVector<T> rez(size);
  if (size == 0)
    vector = 0;
  else
  {
    for (int i = 0; i < size; i++)
      rez.vector[i] = vector[i]-scalar;
  }
  return rez;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator*(const T &scalar)
{
  TVector<T> rez(size);
  if (size == 0)
    vector = 0;
  else
  {
    for (int i = 0; i < size; i++)
      rez.vector[i] = vector[i]*scalar;
  }
  return rez;
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
template <class T1>
std::istream& operator >> (std::istream &istr, TVector<T1> &vec)
{
  std::cout << "Enter vector size: ";
  istr >> vec.size;
  vec.vector = new T1[vec.size];
  std::cout << "Set the vector elementwise : ";
  for (int i = 0; i<vec.size; i++)
    istr >> vec.vector[i];
  return istr;
}
// ---------------------------------------------------------------------------
template <class T1>
std::ostream& operator << (std::ostream &ostr, TVector<T1> &vec)
{
  ostr << "(";
  for (int i = 0; i<vec.size-1; i++)
    ostr << vec.vector[i] << ",";
  ostr << vec.vector[vec.size - 1];
  ostr << ")";
  return ostr;
}
