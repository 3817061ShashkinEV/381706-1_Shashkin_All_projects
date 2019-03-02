#pragma once
#include "Monom.h"

class TPolynom
{
protected:
	TMonom* start;
	int size;
	int count;
public:
	TPolynom(int _count = 3);
	TPolynom(TPolynom &obj);
	int GetSize();
	TMonom* GetStart();
	TPolynom operator-(TPolynom &obj);
	TPolynom operator+(TPolynom &obj);
	TPolynom& operator=(const TPolynom &obj);
	bool operator==(const TPolynom &obj);
	TPolynom operator*(TPolynom &obj);
	TPolynom& operator+=(TMonom &obj);
	TPolynom& operator-=(TMonom &obj);
	friend std::ostream& operator<<(std::ostream& ostr, TPolynom& obj);
};//TPolynom