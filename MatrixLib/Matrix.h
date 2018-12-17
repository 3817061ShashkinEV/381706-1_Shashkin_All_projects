#pragma once
#include <iostream>
#include <../VectorLib/Vector.h>
#include <../MyExceptionLib/MyException.h>

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int _size = 10);
  TMatrix(TMatrix<T> &obj);
  TMatrix(TVector<TVector<T> > &obj);
  bool operator==(const TMatrix<T> &obj);
  TMatrix<T>& operator=(const TMatrix<T> &obj);
  TMatrix<T> operator+(const TMatrix<T> &obj);
  TMatrix<T> operator-(const TMatrix<T> &obj);
  TMatrix<T> operator*(const TMatrix<T> &obj);
  TMatrix<T> operator/(TMatrix<T> &obj);

  template <class T1>
  friend std::istream& operator >> (std::istream &istr, TMatrix<T1> &matrix);

  template <class T1>
  friend std::ostream& operator << (std::ostream &ostr, TMatrix<T1> &matrix);
};//TMatrix
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int _size) : TVector<TVector<T> > (_size)
{
  if (_size <= 0)
    throw TMyException("Error! Size must be positive!\n");
  else
    for (int i = 0; i < _size; i++)
      this->vector[i] = TVector<T>(_size - i);
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(TMatrix<T> &obj) : TVector<TVector<T> >(obj) {}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(TVector<TVector<T> > &obj) : TVector<TVector<T> >(obj) {}
// ---------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &obj)
{
  return TVector<TVector<T> >::operator==(obj);
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &obj)
{
  TVector<TVector<T> >::operator=(obj);
  return *this;
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &obj)
{
  if (this->size != obj.size)
    throw TMyException("Error! Matrices have different sizes!\n");
  else
    return TVector<TVector<T> >::operator+(obj);
  
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &obj)
{
  if (this->size != obj.size)
    throw TMyException("Error! Matrices have different sizes!\n");
  else
    return TVector<TVector<T> >::operator-(obj);
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &obj)
{
  if (this->size != obj.size)
    throw TMyException("Error! Matrices have different sizes!\n");
  else
  {
    TMatrix<T> rez(this->size);
    for (int i = 0; i < this->size; i++)
      for (int j = i; j < this->size; j++)
        for (int k = i; k <= j; k++)
          rez.vector[i][j - i] += this->vector[i][k - i] * obj.vector[k][j - k];
    return rez;
  }
}
// ---------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T> &obj)
{
  if (this->size != obj.size)
    throw TMyException("Error! Matrices have different sizes!\n");
  double determinant = 1;
  for (int i = 0; i < this->size; i++)
    determinant *= this->vector[i][0];
  if (determinant == 0)
    throw TMyException("Error! Determinant of the right matrix equals zero!\n");
  TMatrix<T> copyObj(obj);
  TMatrix<T> rez(this->size);
  for (int i = 0; i < this->size; i++)
  {
    rez[i][0] = 1;
    for (int j = 0; j < (this->size - i); j++)
    {
      copyObj[i][j] = copyObj[i][j]/copyObj[i][0];
      rez[i][j] = rez[i][j]/copyObj[i][0];
    }
  }
  for (int i = 1; i < this->size; i++)
    for (int j = 0; j < i; j++)
    {
      T tmp = copyObj[j][i - j];
      for (int k = i - j, l = 0; k < (this->size - j); k++)
      {
        copyObj[j][k] = copyObj[j][k] - copyObj[i][l] * tmp;
        rez[j][k] = rez[j][k] - rez[i][l++] * tmp;
      }
    }
  return ((*this)*rez);
}
// ---------------------------------------------------------------------------
template <class T1>
std::istream& operator >> (std::istream &istr, TMatrix<T1> &matrix)
{
  for (int i = 0; i < matrix.size; i++)
    istr >> matrix.vector[i];
  return istr;
}
// ---------------------------------------------------------------------------
template <class T1>
std::ostream& operator << (std::ostream &ostr, TMatrix<T1> &matrix)
{
  for (int i = 0; i < matrix.size; i++)
  {
    for (int j = 1; j <= i; j++)
      ostr << " ";
      ostr << matrix.vector[i];
      ostr << "\n";
  }
  return ostr;
}
