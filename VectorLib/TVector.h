#pragma once

#include <iostream>

template <class T>
class TVector 
{
private:
	T *Vector;
	int Size;
public:
	TVector();
	TVector(int _size);
	TVector(TVector<T> &vec);
	~TVector();
};//TVector
