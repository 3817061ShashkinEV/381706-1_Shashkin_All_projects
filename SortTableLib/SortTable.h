#pragma once
#include "SortTableElem.h"

template<class T>
class TSortTable
{
protected:
  TSortElem<T> notFound;
  TSortElem<T>* mas;
  int size;
  int count;
public:
  TSortTable(string* _keys, T* _data, int _size, char _sort);
  TSortTable(int _size = 10);
  TSortTable(TSortTable<T> &obj);
  int Put(string _key, T _data);
  void Del(string _key);
  TSortElem<T>& Search(string _key);
  void Resize(int _size);
  T& operator[](string _key);
  void SetSize(int _size);
  int GetSize();
  void SetCount(int _count);
  int GetCount();
  void QuickSort(int l, int r);
};//TSortTable
// ---------------------------------------------------------------------------
template<class T>
TSortTable<T>::TSortTable(string* _keys, T* _data, int _size, char _sort)
{
  if (_size <= 0)
    throw TMyException("Error! Size must be positive!\n");
  else
  {
    size = _size;
    count = 0;
    mas = new TSortElem<T>[size];
    for (int i = 0; i < size; i++)
      Put(_keys[i], _data[i]);
    switch (_sort)
    {
    case 'b':
    {
      TSortElem<T> tmp;
      for (int i = 0; i < size; i++)
      {
        if (i != size - 1)
          if (mas[i] > mas[i + 1])
          {
            tmp = mas[i];
            mas[i] = mas[i + 1];
            mas[i + 1] = tmp;
          }
      }
      break;
    }
    case 'q':
    {
      QuickSort(0, size - 1);
      break;
    }
    case 'i':
    {
      TSortElem<T> tmp;
      int j;
      for (int i = 0; i < size; i++)
      {
        tmp = mas[i];
        for (j = i - 1; j >= 0 && mas[j] > tmp; j--)
          mas[j + 1] = mas[j];
        mas[j + 1] = tmp;
      }
      break;
    }
    }
  }
}
// ---------------------------------------------------------------------------
template<class T>
TSortTable<T>::TSortTable(int _size)
{
  if (_size <= 0)
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
    mas = new TSortElem<T>[size];
  }
}
// ---------------------------------------------------------------------------
template<class T>
TSortTable<T>::TSortTable(TSortTable<T> &obj)
{
  size = obj.size;
  count = obj.count;
  mas = new TSortElem<T>[size];
  for (int i = 0; i < size; i++)
    mas[i] = obj.mas[i];
}
// ---------------------------------------------------------------------------
template<class T>
int TSortTable<T>::Put(string _key, T _data)
{
  if (size <= count)
    Resize(count * 2);
  if (count == 0)
  {
    TSortElem<T> tmp(_key, _data);
    mas[0] = tmp;
    count++;
    return 0;
  }
  int right = count;
  int left = 0;
  int cur = count / 2;
  while (left < right)
  {
    if (mas[cur].GetKey() > _key)
    {
      right = cur-1;
      cur = ((left + right) / 2);
    }
    else if (mas[cur].GetKey() < _key)
    {
      left = cur+1;
      cur = ((left + right) / 2);
    }
    else
    {
      throw TMyException("Error! Such key already exists!\n");
    }
  }
  for (int i = cur; i < count; i++)
    mas[i + 1] = mas[i];
  TSortElem<T> tmp(_key, _data);
  mas[cur] = tmp;
  count++;
  return cur;
}
// ---------------------------------------------------------------------------
template<class T>
void TSortTable<T>::Del(string _key)
{
  int right = count;
  int left = 0;
  int cur = count / 2;
  while (left < right)
  {
    if (mas[cur].GetKey() > _key)
    {
      right = cur-1;
      cur = ((left + right) / 2);
    }
    else if (mas[cur].GetKey() < _key)
    {
      left = cur+1;
      cur = ((left + right) / 2);
    }
    else
    {
      for (int i = cur; i < count-1; i++)
        mas[i] = mas[i + 1];
      count--;
    }
  }
}
// ---------------------------------------------------------------------------
template<class T>
TSortElem<T>& TSortTable<T>::Search(string _key)
{
  int right = count;
  int left = 0;
  int cur = count / 2;
  while (left<right)
  {
    if (mas[cur].GetKey() > _key)
    {
      right = cur-1;
      cur = ((left + right) / 2);
    }
    else if (mas[cur].GetKey() < _key)
    {
      left = cur+1;
      cur = ((left + right) / 2);
    }
    else
      return mas[cur];
  }
  return notFound;
}
// ---------------------------------------------------------------------------
template<class T>
void TSortTable<T>::Resize(int _size)
{
  if (_size < size)
    throw TMyException("Error! Wrong size!\n");
  TSortElem<T>* newMas = new TSortElem<T>[_size];
  for (int i = 0; i < size; i++)
    newMas[i] = mas[i];
  delete[] mas;
  mas = newMas;
  size = _size;
}
// ---------------------------------------------------------------------------
template<class T>
T& TSortTable<T>::operator[](string _key)
{
  TSortElem<T>& tmp = Search(_key);
  if (tmp == notFound)
  {
    Put(_key, 0);
    return mas[count - 1].GetDataAddress();
  }
  return tmp.GetDataAddress();
}
// ---------------------------------------------------------------------------
template <class T>
void TSortTable<T>::SetSize(int _size)
{
  size = _size;
}
// ---------------------------------------------------------------------------
template <class T>
int TSortTable<T>::GetSize()
{
  return size;
}
// ---------------------------------------------------------------------------
template <class T>
void TSortTable<T>::SetCount(int _count)
{
  count = _count;
}
// ---------------------------------------------------------------------------
template <class T>
int TSortTable<T>::GetCount()
{
  return count;
}
// ---------------------------------------------------------------------------
template <class T>
void TSortTable<T>::QuickSort(int l, int r)
{
  int left=l, right=r;
  TSortElem<T> mid = mas[(left + right) / 2];
  TSortElem<T> tmp;
  do
  {
    while ((mas[left] < mid) && (left < r))
      left++;
    while ((mid < mas[right]) && (right > l))
      right--;
    if (left <= right)
    {
      tmp = mas[left];
      mas[left] = mas[right];
      mas[right] = tmp;
      left++;
      right--;
    }
  } while (left <= right);
  if (l < right) 
    QuickSort(l, right);
  if (left < r) 
    QuickSort(left, r);
}
