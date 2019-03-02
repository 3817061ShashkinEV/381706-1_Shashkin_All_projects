#include "Polynom.h"

TPolynom::TPolynom(int _count)
{
	if (_count <= 0)
		throw TMyException("Error! Count must be positive!\n");
	count = _count;
	size = 0;
	start = NULL;
}
// ---------------------------------------------------------------------------
TPolynom::TPolynom(TPolynom &obj)
{
	count = obj.count;
	size = obj.size;
	if (obj.start == 0)
		start = NULL;
	else
	{
		start = new TMonom(*obj.start);
		TMonom* tmp1 = obj.start;
		TMonom* tmp2 = start;
		while (tmp1->GetNext() != 0)
		{
			tmp2->SetNext(new TMonom(*(tmp1->GetNext())));
			tmp2 = tmp2->GetNext();
			tmp1 = tmp1->GetNext();
		}
		tmp2->SetNext(NULL);
	}
}
// ---------------------------------------------------------------------------
int TPolynom::GetSize()
{
	return size;
}
// ---------------------------------------------------------------------------
TMonom* TPolynom::GetStart()
{
	return start;
}
// ---------------------------------------------------------------------------
TPolynom TPolynom::operator-(TPolynom &obj)
{
	if (this->count != obj.count)
		throw TMyException("Error! Size must be equal!\n");
	TPolynom rez(count);
	TMonom* tmp1 = start;
	TMonom* tmp2 = obj.start;
	TMonom *tmp = rez.start;
	while ((tmp1 != 0) && (tmp2 != 0))
	{
		TMonom *t;
		if ((*tmp1) == (*tmp2))
		{
			TMonom k = (*tmp1);
			k -= (*tmp2);
			t = new TMonom(k);
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) < (*tmp2))
		{
			t = new TMonom((*tmp2));
			if (t->GetCoefficient() == 0)
				continue;
			t->SetCoefficient(t->GetCoefficient() * (-1));
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) > (*tmp2))
		{
			t = new TMonom((*tmp1));
			if (t->GetCoefficient() == 0)
				continue;
			tmp1 = tmp1->GetNext();
		}
		if (t->GetCoefficient() == 0)
			continue;
		if (tmp == 0)
		{
			tmp = t;
			rez.start = t;
			rez.size++;
		}
		else
		{
			tmp->SetNext(t);
			rez.size++;
			tmp = tmp->GetNext();
		}
	}
	while (tmp1 != 0)
	{
		if (tmp1->GetCoefficient() == 0)
			continue;
		tmp->SetNext(new TMonom(*tmp1));
		tmp1 = tmp1->GetNext();
		rez.size++;
		tmp = tmp->GetNext();
	}
	while (tmp2 != 0)
	{
		if (tmp2->GetCoefficient() == 0)
			continue;
		TMonom t(*tmp2);
		t.SetCoefficient(t.GetCoefficient() * (-1));
		tmp->SetNext(&t);
		tmp2 = tmp2->GetNext();
		rez.size++;
		tmp = tmp->GetNext();
	}
	return rez;
}
// ---------------------------------------------------------------------------
TPolynom TPolynom::operator+(TPolynom &obj)
{
	if (this->count != obj.count)
		throw TMyException("Error! Size must be equal!\n");
	TPolynom rez(count);
	TMonom* tmp1 = start;
	TMonom* tmp2 = obj.start;
	TMonom *tmp = rez.start;
	while ((tmp1 != 0) && (tmp2 != 0))
	{
		TMonom *t;
		if ((*tmp1) == (*tmp2))
		{
			TMonom k = (*tmp1);
			k += (*tmp2);
			t = new TMonom(k);
			if (t->GetCoefficient() == 0)
				continue;
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) < (*tmp2))
		{
			t = new TMonom((*tmp2));
			if (t->GetCoefficient() == 0)
				continue;
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) > (*tmp2))
		{
			t = new TMonom((*tmp1));
			if (t->GetCoefficient() == 0)
				continue;
			tmp1 = tmp1->GetNext();
		}
		if (tmp == 0)
		{
			tmp = t;
			rez.start = t;
			rez.size++;
		}
		else
		{
			tmp->SetNext(t);
			rez.size++;
			tmp = tmp->GetNext();
		}
	}
	if (tmp1 == 0)
		tmp1 = tmp2;
	while (tmp1 != 0)
	{
		if (tmp1->GetCoefficient() == 0)
			continue;
		tmp->SetNext(new TMonom(*tmp1));
		tmp1 = tmp1->GetNext();
		rez.size++;
		tmp = tmp->GetNext();
	}
	return rez;
}
// ---------------------------------------------------------------------------
TPolynom& TPolynom::operator=(const TPolynom &obj)
{
	if (*this == obj)
		return *this;
	if (this->count != obj.count)
		throw TMyException("Error! Size must be equal!\n");
	else
	{
		size = obj.size;
		TMonom* tmp1 = start;
		TMonom* tmp2 = start;
		while (tmp1 != 0)
		{
			tmp1 = tmp1->GetNext();
			delete tmp2;
			tmp2 = tmp1;
		}
		tmp1 = obj.start->GetNext();
		tmp2 = new TMonom(*obj.start);
		start = tmp2;
		while (tmp1 != 0)
		{
			tmp2->SetNext(new TMonom(*tmp1));
			tmp2 = tmp2->GetNext();
			tmp1 = tmp1->GetNext();
		}
		return *this;
	}
}
// ---------------------------------------------------------------------------
bool TPolynom::operator==(const TPolynom &obj)
{
	if (this->count != obj.count)
		throw TMyException("Error! Size must be equal!\n");
	if (this->size != obj.size)
		return false;
	TMonom* tmp1 = start;
	TMonom* tmp2 = obj.start;
	while (tmp1 != 0)
	{
		if (!(*tmp1 == *tmp2))
			return false;
		if (tmp1->GetCoefficient() != tmp2->GetCoefficient())
			return false;
		tmp1 = tmp1->GetNext();
		tmp2 = tmp2->GetNext();
	}
	return true;
}
// ---------------------------------------------------------------------------
TPolynom TPolynom::operator*(TPolynom &obj)
{
	if (this->count != obj.count)
		throw TMyException("Error! Size must be equal!\n");
	TPolynom rez(count);
	TMonom* tmp1 = start;
	TMonom* tmp2 = obj.start;
	while (tmp1 != 0)
	{
		if (tmp1->GetCoefficient() == 0)
			continue;
		while (tmp2 != 0)
		{
			if (tmp2->GetCoefficient() == 0)
				continue;
			TMonom tmp = (*tmp1);
			tmp *= (*tmp2);
			TMonom* f = new TMonom(tmp);
			f->SetNext(NULL);
			rez += *f;
			tmp2 = tmp2->GetNext();
		}
		tmp1 = tmp1->GetNext();
		tmp2 = obj.start;
	}
	return rez;
}
// ---------------------------------------------------------------------------
TPolynom& TPolynom::operator+=(TMonom &obj)
{
	if (this->count != obj.GetCount())
		throw TMyException("Error! Size must be equal!\n");
	if (obj.GetCoefficient() == 0)
		return *this;
	if (start == 0)
		start = new TMonom(obj);
	else
	{
		TMonom* tmp1;
		TMonom* tmp2;
		tmp1 = start;
		tmp2 = start->GetNext();
		if (*start < obj)
		{
			TMonom* tmp = new TMonom(obj);
			tmp->SetNext(start);
			start = tmp;
		}
		else if (*start == obj)
		{
			*start += obj;
			if (start->GetCoefficient() == 0)
			{
				TMonom* temp = start->GetNext();
				delete[] start;
				start = temp;
			}
		}
		else
		{
			while (tmp2 != 0)
			{
				if (*tmp2 == obj)
				{
					*tmp2 += obj;
					if (tmp2->GetCoefficient() == 0)
					{
						start->SetNext(tmp2->GetNext());
						delete[] tmp2;
					}
					return *this;
				}
				if (*tmp2 < obj)
				{
					TMonom* tmp = new TMonom(obj);
					tmp1->SetNext(tmp);
					tmp->SetNext(tmp2);
					size++;
					return *this;
				}
				tmp1 = tmp2;
				tmp2 = tmp2->GetNext();
			}
			tmp1->SetNext(new TMonom(obj));
		}
	}
	size++;
	return *this;
}
// ---------------------------------------------------------------------------
TPolynom& TPolynom::operator-=(TMonom &obj)
{
	if (this->count != obj.GetCount())
		throw TMyException("Error! Size must be equal!\n");
	if (obj.GetCoefficient() == 0)
		return *this;
	obj.SetCoefficient(obj.GetCoefficient() * (-1));
	if (start == 0)
		start = new TMonom(obj);
	else
	{
		TMonom* tmp1;
		TMonom* tmp2;
		tmp1 = start;
		tmp2 = start->GetNext();
		if (*start < obj)
		{
			TMonom* tmp = new TMonom(obj);
			tmp->SetNext(start);
			start = tmp;
		}
		else if (*start == obj)
		{
			*start -= obj;
			if (start->GetCoefficient() == 0)
			{
				TMonom* temp = start->GetNext();
				delete[] start;
				start = temp;
			}
		}
		else
		{
			while (tmp2 != 0)
			{
				if (*tmp2 == obj)
				{
					*tmp2 -= obj;
					if (tmp2->GetCoefficient() == 0)
					{
						start->SetNext(tmp2->GetNext());
						delete[] tmp2;
					}
					size++;
					return *this;
				}
				if (*tmp2 < obj)
				{
					TMonom* tmp = new TMonom(obj);
					tmp1->SetNext(tmp);
					tmp->SetNext(tmp2);
					size++;
					return *this;
				}
				tmp1 = tmp2;
				tmp2 = tmp2->GetNext();
			}
			tmp1->SetNext(new TMonom(obj));
		}
	}
	size++;
	return *this;
}
// ---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& ostr, TPolynom& obj)
{
	TMonom *tmp = obj.start;
	if (tmp != 0)
	{
		ostr << *tmp;
		tmp = tmp->GetNext();
	}
	while (tmp != 0)
	{
		if (tmp->GetCoefficient() != 0)
			ostr << " + " << *tmp;
		tmp = tmp->GetNext();
	}
	return ostr;
}