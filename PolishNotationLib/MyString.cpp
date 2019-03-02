#include "MyString.h"

TMyString::TMyString()
{
	len = 0;
	str = 0;
}
// ---------------------------------------------------------------------------
TMyString::TMyString(char* _str)
{
	if (_str == 0)
		throw TMyException("Error! String is empty!\n");
	else
	{
		char tmp = 1;
		int size = 0;
		while (tmp != '\0')
		{
			size++;
			tmp = _str[size];
		}
		len = size + 1;
		str = new char[len];
		for (int i = 0; i < len - 1; i++)
			str[i] = _str[i];
		str[len - 1] = '\0';
	}
}
// ---------------------------------------------------------------------------
TMyString::TMyString(TMyString &obj)
{
	len = obj.len;
	if (len != 0)
	{
		str = new char[len];
		for (int i = 0; i < len; i++)
			str[i] = obj.str[i];
	}
	else
		str = 0;
}
// ---------------------------------------------------------------------------
TMyString::~TMyString()
{
	if (str != 0)
		delete[] str;
	str = NULL;
}
// ---------------------------------------------------------------------------
int TMyString::GetLen()
{
	return len;
}
// ---------------------------------------------------------------------------
void TMyString::DeleteStr()
{
	if (str != 0)
		delete[] str;
	str = NULL;
}
// ---------------------------------------------------------------------------
TMyString TMyString::operator+(TMyString &obj)
{
	TMyString rez;
	rez.len = len + obj.len - 1;
	rez.str = new char[rez.len];
	for (int i = 0; i < len; i++)
		rez.str[i] = str[i];
	for (int i = len - 1; i < rez.len; i++)
		rez.str[i] = obj.str[i - len + 1];
	return rez;
}
// ---------------------------------------------------------------------------
TMyString& TMyString::operator=(TMyString &obj)
{
	if (this != &obj)
	{
		len = obj.len;
		if (len != 0)
		{
			if (str != 0)
				delete[] str;
			str = new char[len];
			for (int i = 0; i < len; i++)
				str[i] = obj.str[i];
		}
		else
		{
			if (str != 0)
				delete[] str;
			str = NULL;
		}
	}
	return *this;
}
// ---------------------------------------------------------------------------
char& TMyString::operator[](int _index)
{
	if (_index < 0 || _index >= len)
		throw TMyException("Error! Index is out of range!\n");
	return str[_index];
}
// ---------------------------------------------------------------------------
std::istream& operator>>(std::istream &istr, TMyString &obj)
{
	char buf[256];
	for (int i = 0; i < 256; i++)
		buf[i] = 0;
	istr >> buf;
	char tmp = 1;
	int size = 0;
	while (tmp != '\0')
	{
		size++;
		tmp = buf[size];
	}
	obj.len = size + 1;
	obj.str = new char[obj.len];
	for (int i = 0; i < obj.len - 1; i++)
		obj.str[i] = buf[i];
	obj.str[obj.len - 1] = '\0';
	return istr;
}
// ---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &ostr, const TMyString &obj)
{
	ostr << obj.str;
	return ostr;
}
