#pragma once
#include <iostream>
#include <exception>

class TMyException :public std::exception
{
public:
	TMyException(char *msg) :exception(msg) {}
}; //TMyException
   // ---------------------------------------------------------------------------
template <class T>
class TVector
{
	T* vector;
	int len;
public:
	TVector();
	TVector(int _len, T* _vector);
	TVector(TVector &obj);
	~TVector();
	void ClearVector();
	int GetLen();
	void ChangeLenOfVector(int size, const char IncrOrDecr);
	TVector<T> operator+(TVector<T> &obj);
	TVector<T> operator-(TVector<T> &obj);
	T operator*(TVector<T> &obj);
	TVector<T>& operator*(T num);
	TVector<T>& operator/(T num);
	TVector<T>& operator=(TVector<T> &obj);
	T& operator[] (int index);
	
	template <class T>
	friend std::istream& operator >> (std::istream &A, TVector<T> &B);
	
	template <class T>
	friend std::ostream& operator << (std::ostream &A, TVector<T> &B);
}; //TVector
   // ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector()
{
	vector = 0;
	len = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(TVector &obj)
{
	len = obj.len;
	if (len != 0)
	{
		vector = new T[len];
		for (int i = 0; i < len; i++)
			vector[i] = obj.vector[i];
	}
	else
		vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(int _len, T* _vector)
{
	len = _len;
	vector = new T[len];
	for (int i = 0; i < len; i++)
		vector[i] = _vector[i];
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
void TVector<T>::ClearVector()
{
	if (vector != 0)
		delete[] vector;
	vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetLen()
{
	return len;
}
// ---------------------------------------------------------------------------
template <class T>
void TVector<T>::ChangeLenOfVector(int size, const char IncrOrDecr)
{
	if (IncrOrDecr == '+' || IncrOrDecr == '-')
	{
		if (IncrOrDecr == '+')
		{
			if (vector != 0)
			{
				T* tmp = new T[len];;
				for (int i = 0; i < len; i++)
					tmp[i] = vector[i];
				len += size;
				delete[] vector;
				vector = new T[len];
				for (int i = 0; i < len - size; i++)
					vector[i] = tmp[i];
				delete[] tmp;
				for (int i = len - size; i < len; i++)
					vector[i] = 0;
			}
		}
		else if (IncrOrDecr == '-')
		{
			if (vector != 0)
			{
				T* tmp = new T[len];;
				for (int i = 0; i < len; i++)
					tmp[i] = vector[i];
				len -= size;
				delete[] vector;
				vector = new T[len];
				for (int i = 0; i < len; i++)
					vector[i] = tmp[i];
				delete[] tmp;
			}
		}
	}
	else
		throw TMyException("Вторым параметром могут быть только '+'-увелечение размера вектора или '-'-умньшение размера вектора!\n");
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+(TVector<T> &obj)
{
	TVector<T> rez;
	if (len == obj.len)
	{
		if (len == 0)
			rez.vector = 0;
		else
		{
			rez.len = len;
			rez.vector = new T[rez.len];
			for (int i = 0; i < rez.len; i++)
				rez.vector[i] = vector[i] + obj.vector[i];
		}
	}
	else
		throw TMyException("Векторы разных размеров!\n");
	return rez;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(TVector<T> &obj)
{
	TVector<T> rez;
	if (len == obj.len)
	{
		if (len == 0)
			rez.vector = 0;
		else
		{
			rez.len = len;
			rez.vector = new T[rez.len];
			for (int i = 0; i < rez.len; i++)
				rez.vector[i] = vector[i] - obj.vector[i];
		}
	}
	else
		throw TMyException("Векторы разных размеров!\n");;
	return rez;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator*(T num)
{
	if (len == 0)
		vector = 0;
	else
	{
		for (int i = 0; i < len; i++)
			vector[i] *= num;
	}
	return *this;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator/(T num)
{
	if (num != 0)
	{
		if (len == 0)
			vector = 0;
		else
		{
			for (int i = 0; i < len; i++)
				vector[i] /= num;
		}
	}
	else
		throw TMyException("На ноль делить нельзя!\n");
	return *this;
}
// ---------------------------------------------------------------------------
template <class T>
T TVector<T>::operator*(TVector<T> &obj)
{
	T rez=0;
	if (len == obj.len)
	{
		if (len == 0)
			rez=0;
		else
		{
			for (int i = 0; i < len; i++)
				rez += (vector[i] * obj.vector[i]);
		}
	}
	else
		throw TMyException("Векторы разных размеров!\n");;
	return rez;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator=(TVector<T> &obj)
{
	if (this != &obj)
	{
		len = obj.len;
		if (len != 0)
		{
			if (vector != 0)
				delete[] vector;
			vector = new T[len];
			for (int i = 0; i < len; i++)
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
template <class T>
T& TVector<T> ::operator[] (int index)
{
	if (index >= 0 && index < len)
		return vector[index];
	throw TMyException("Выход за границы вектора!\n");
}
// ---------------------------------------------------------------------------
template <class T>
std::istream& operator >> (std::istream &A, TVector<T> &B)
{
	std::cout << "Введите размер вектора: ";
	A >> B.len;
	B.vector = new T[B.len];
	std::cout << "Задайте вектор поэлементно: ";
	for (int i = 0; i<B.len; i++)
		A >> B.vector[i];
	return A;
}
// ---------------------------------------------------------------------------
template <class T>
std::ostream& operator << (std::ostream &A, TVector<T> &B)
{
	A << "Размер вектора: " << B.len << "\n";
	A << "Вектор: (";
	for (int i = 0; i<B.len-1; i++)
		A << B.vector[i] << ",";
	A << B.vector[B.len - 1];
	A << ")";
	return A;
}