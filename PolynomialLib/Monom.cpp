#include "Monom.h"



TMonom::TMonom()
{
	next = NULL;
	degree = NULL;
	count = 0;
	coefficient = 0;
}
// ---------------------------------------------------------------------------
TMonom::TMonom(int _count, int* _degree, double _coefficient)
{
	if (_count < 0)
		throw TMyException("Error! Negative size!\n");
	else if (_count == 0)
	{
		next = NULL;
		degree = NULL;
		count = _count;
		coefficient = _coefficient;
	}
	else
	{
		count = _count;
		coefficient = _coefficient;
		next = NULL;
		degree = new int[_count];
		for (int i = 0; i < _count; i++)
		{
			if (_degree[i] >= 0)
				degree[i] = _degree[i];
			else
				throw TMyException("Error! Negative degree!\n");
		}
	}
}
// ---------------------------------------------------------------------------
TMonom::TMonom(const TMonom &obj)
{
	count = obj.count;
	coefficient = obj.coefficient;
	next = obj.next;
	degree = new int[count];
	for (int i = 0; i < count; i++)
		degree[i] = obj.degree[i];
}
// ---------------------------------------------------------------------------
TMonom::~TMonom()
{
	if (degree != 0)
		delete[] degree;
	degree = NULL;
}
// ---------------------------------------------------------------------------
TMonom* TMonom::GetNext()
{
	return next;
}
// ---------------------------------------------------------------------------
int* TMonom::GetDegree()
{
	return degree;
}
// ---------------------------------------------------------------------------
double TMonom::GetCoefficient()
{
	return coefficient;
}
// ---------------------------------------------------------------------------
int TMonom::GetCount()
{
	return count;
}
// ---------------------------------------------------------------------------
void TMonom::SetNext(TMonom* _next)
{
	next = _next;
}
// ---------------------------------------------------------------------------
void TMonom::SetDegree(int* _degree)
{
	for (int i = 0; i < count; i++)
	{
		if (_degree[i] >= 0)
			degree[i] = _degree[i];
		else
			throw TMyException("Error! Negative degree!\n");
	}
}
// ---------------------------------------------------------------------------
void TMonom::SetCoefficient(double _cofficient)
{
	coefficient = _cofficient;
}
// ---------------------------------------------------------------------------
void TMonom::SetCount(int _count)
{
	if (_count < 0)
		throw TMyException("Error! Negative size!\n");
	else if (_count == 0)
	{
		if (degree != 0)
			delete[] degree;
		degree = NULL;
		count = 0;
	}
	else
	{
		int *tmp = new int[count];
		for (int i = 0; i < count; i++)
			tmp[i] = degree[i];
		delete[] degree;
		degree = new int[_count];
		int i = 0;
		if (count < _count)
		{
			for (; i < count; i++)
				degree[i] = tmp[i];
			for (; i < _count; i++)
				degree[i] = 0;
		}
		if (_count < count)
			for (; i < _count; i++)
				degree[i] = tmp[i];
		count = _count;
	}
}
// ---------------------------------------------------------------------------
TMonom& TMonom::operator=(const TMonom &obj)
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	coefficient = obj.coefficient;
	count = obj.count;
	next = obj.next;
	delete[] degree;
	degree = new int[count];
	for (int i = 0; i < count; i++)
		degree[i] = obj.degree[i];
	return *this;
}
// ---------------------------------------------------------------------------
TMonom TMonom::operator+(TMonom &obj)
{
	TMonom tmp(obj);
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	if (!(*this == obj))
		throw TMyException("Error! Degrees must be equal!\n");
	tmp.coefficient = coefficient + obj.coefficient;
	return tmp;
}
// ---------------------------------------------------------------------------
TMonom TMonom::operator+=(TMonom &obj)
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	if (!(*this == obj))
		throw TMyException("Error! Degrees must be equal!\n");
	coefficient += obj.coefficient;
	return *this;
}
// ---------------------------------------------------------------------------
TMonom TMonom::operator*(const TMonom &obj) const
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	TMonom tmp(obj);
	tmp.coefficient = coefficient * obj.coefficient;
	for (int i = 0; i < count; i++)
		tmp.degree[i] = degree[i] + obj.degree[i];
	return tmp;
}
// ---------------------------------------------------------------------------
TMonom TMonom::operator*=(TMonom &obj)
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	coefficient = coefficient * obj.coefficient;
	for (int i = 0; i < count; i++)
		degree[i] += obj.degree[i];
	return *this;
}
// ---------------------------------------------------------------------------
TMonom TMonom::operator-(TMonom &obj)
{
	TMonom tmp(obj);
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	if (!(*this == obj))
		throw TMyException("Error! Degrees must be equal!\n");
	tmp.coefficient = coefficient - obj.coefficient;
	return tmp;
}
// ---------------------------------------------------------------------------
TMonom TMonom::operator-=(TMonom &obj)
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	if (!(*this == obj))
		throw TMyException("Error! Degrees must be equal!\n");
	coefficient -= obj.coefficient;
	return *this;
}
// ---------------------------------------------------------------------------
bool TMonom::operator==(TMonom &obj)
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	for (int i = 0; i < count; i++)
		if (degree[i] != obj.degree[i])
			return false;
	return true;
}
// ---------------------------------------------------------------------------
bool TMonom::operator>(TMonom &obj)
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	if (*this == obj)
		throw TMyException("Monoms must be equeal!\n");
	for (int i = 0; i < count; i++)
	{
		if (degree[i] == obj.degree[i])
			continue;
		else if (degree[i] > obj.degree[i])
			return true;
		else
			return false;
	}
	return true;
}
// ---------------------------------------------------------------------------
bool TMonom::operator<(TMonom &obj)
{
	if (count != obj.count)
		throw TMyException("Error! Sizes must be equal!\n");
	if (*this == obj)
		throw TMyException("Monoms must be equeal!\n");
	for (int i = 0; i < count; i++)
	{
		if (degree[i] == obj.degree[i])
			continue;
		else if (degree[i] < obj.degree[i])
			return true;
		else
			return false;
	}
	if (coefficient > obj.coefficient)
		return false;
	return true;
}
// ---------------------------------------------------------------------------
istream& operator>>(istream &istr, TMonom &obj)
{
	istr >> obj.coefficient;
	for (int i = 0; i < obj.count; i++)
		istr >> obj.degree[i];
	return istr;
}
// ---------------------------------------------------------------------------
ostream& operator<<(ostream &ostr, TMonom &obj)
{
	ostr << obj.coefficient;
	if (obj.coefficient != 0)
		for (int i = 0; i < obj.count; i++)
			if (obj.degree[i] != 0)
			{
				ostr << "*x" << i;
				if (obj.degree[i] != 1)
					ostr << "^" << obj.degree[i];
			}
	return ostr;
}