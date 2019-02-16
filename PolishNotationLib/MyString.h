#pragma once
#include <iostream>
#include "MyException.h"

class TMyString
{
protected:
	char* str;
	int len;
public:
	TMyString();
	TMyString(char* _str);
	TMyString(TMyString &obj);
	~TMyString();
	int GetLen();
	void DeleteStr();
	TMyString operator+(TMyString &obj);
	TMyString& operator=(TMyString &obj);
	char& operator[](int _index);
	friend std::istream& operator>>(std::istream &istr, TMyString &obj);
	friend std::ostream& operator<<(std::ostream &ostr, const TMyString &obj);
};//TMyString


