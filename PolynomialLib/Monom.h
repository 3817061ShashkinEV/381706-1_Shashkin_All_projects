#pragma once
#include "MyException.h"

class TMonom
{
protected:
	TMonom* next;
	int* degree;
	int count;
	double coefficient;
public:
	TMonom();
	TMonom(int _count, int* _degree, double _coefficient);
	TMonom(const TMonom &obj);
	~TMonom();
	TMonom* GetNext();
	int* GetDegree();
	double GetCoefficient();
	int GetCount();
	void SetNext(TMonom* _next);
	void SetDegree(int* _degree);
	void SetCoefficient(double _cofficient);
	void SetCount(int _count);
	TMonom& operator=(const TMonom &obj);
	TMonom operator+(TMonom &obj);
	TMonom operator+=(TMonom &obj);
	TMonom operator*(const TMonom &obj) const;
	TMonom operator*=(TMonom &obj);
	TMonom operator-(TMonom &obj);
	TMonom operator-=(TMonom &obj);
	bool operator==(TMonom &obj);
	bool operator>(TMonom &obj);
	bool operator<(TMonom &obj);
	friend istream& operator>>(istream &istr, TMonom &obj);
	friend ostream& operator<<(ostream &ostr, TMonom &obj);
};//TMonom
