#include "TableElem.h"

template <class T>
class TTable
{
protected:
	TElem<T> notFound;
	TElem<T> *mas;
	int size;
	int count;
public:
	TTable(int _size = 10);
	TTable(TTable &obj);
	void Put(string _key, T _data);
	void Del(string _key); 
	TElem<T>& Search(string _key);
	T& operator[](string _key);
	void SetSize(int _size);
	int GetSize();
	void SetCount(int _count);
	int GetCount();
};//TTable
// ---------------------------------------------------------------------------
template <class T>
TTable<T>::TTable(int _size)
{
	if (_size < 0)
		throw TMyException("Error! Size must be positive!\n");
	else if (_size == 0)
	{
		size = 0;
		count = 0;
		notFound.SetKey("NOT_FOUND");
		notFound.SetData(404);
		mas = NULL;
	}
	else
	{
		size = _size;
		count = 0;
		notFound.SetKey("NOT_FOUND");
		notFound.SetData(404);
		mas = new TElem<T>[size];
	}
}
// ---------------------------------------------------------------------------
template <class T>
TTable<T>::TTable(TTable &obj)
{
	size = obj.size;
	count = obj.count;
	mas = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = obj.mas[i];
}
// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::Put(string _key, T _data)
{
	if (size == count)
		throw TMyException("Error! Table is full!\n");
	else
	{
		mas[count].SetKey(_key);
		mas[count].SetData(_data);
		count++;
	}
}
// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::Del(string _key)
{
	if (count == 0)
		throw TMyException("Error! Table is empty!\n");
	else
	{
		TElem<T>& tmp = Search(_key);
		if (!(tmp == notFound))
			tmp = notFound;
	}
}
// ---------------------------------------------------------------------------
template <class T>
TElem<T>& TTable<T>::Search(string _key)
{
	for (int i = 0; i < count; i++)
		if (_key == mas[i].GetKey())
			return mas[i];
	return notFound;
}
// ---------------------------------------------------------------------------
template <class T>
T& TTable<T>::operator[](string _key)
{
	TElem<T>& tmp = Search(_key);
	if (tmp == notFound)
	{
		Put(_key, 0);
		return mas[count - 1].GetDataAddress();
	}
	return tmp.GetDataAddress();
}
// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::SetSize(int _size)
{
	size = _size;
}
// ---------------------------------------------------------------------------
template <class T>
int TTable<T>::GetSize()
{
	return size;
}
// ---------------------------------------------------------------------------
template <class T>
void TTable<T>::SetCount(int _count)
{
	count = _count;
}
// ---------------------------------------------------------------------------
template <class T>
int TTable<T>::GetCount()
{
	return count;
}