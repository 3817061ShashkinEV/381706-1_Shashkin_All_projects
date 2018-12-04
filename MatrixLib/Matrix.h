#pragma once
#include <iostream>
#include <Vector.h>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int _size = 10);
  TMatrix(const TMatrix<T> &obj);
  TMatrix(const TVector<TVector<T> > &obj);
  bool operator==(const TMatrix<T> &obj);
  TMatrix<T>& operator=(const TMatrix<T> &obj);
  TMatrix<T> operator+(const TMatrix<T> &obj);
  TMatrix<T> operator-(const TMatrix<T> &obj);
  TMatrix<T> operator*(const TMatrix<T> &obj);

  template <class T1>
  friend std::istream& operator >> (std::istream &A, TMatrix<T> &B);

  template <class T1>
  friend std::ostream& operator << (std::ostream &A, TMatrix<T> &B);
};//TMatrix
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int _size) : TVector<TVector<T>> (_size)
{
  if (_size > 0)
    for (int i = 0; i < _size; i++)
      vector[i] = TVector<T>(_size - i, i);
  else
    throw TMyException("Error! Size must be positive!\n");
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &obj) : TVector<TVector<T>>(obj) {}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &obj) : TVector<TVector<T>>(obj) {}
// ---------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &obj)
{
  return TVector<TVector<T>>::operator==(obj);
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &obj)
{
  TVector<TVector<T>>::operator=(obj);
  return *this;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &obj)
{
  if (size != obj.size)
    throw TMyException("Error! Matrices have different sizes!\n");
  else
    return TVector<TVector<T>>::operator+(obj);
  
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &obj)
{
  if (size != obj.size)
    throw TMyException("Error! Matrices have different sizes!\n");
  else
    return TVector<TVector<T>>::operator-(obj);
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &obj)
{
  if (size != obj.size)
    throw TMyException("Error! Matrices have different sizes!\n");
  else
    return TVector<TVector<T>>::operator*(obj);
}
// ---------------------------------------------------------------------------
template <class T>
std::istream& operator >> (std::istream &istr, TMatrix<T> &Matrix)
{
  for (int i = 0; i < Matrix.size; i++)
    istr >> Matrix.vector[i];
  return istr;
}
// ---------------------------------------------------------------------------
template <class T>
std::ostream& operator << (std::ostream &ostr, TMatrix<T> &Matrix)
{
  for (int i = 0; i < Matrix.size; i++)
  {
    ostr << Matrix.vector[i];
    if (i != Matrix.size - 1)
      ostr << " ";
    else
      ostr << "\n";
  }
  return ostr;
}
