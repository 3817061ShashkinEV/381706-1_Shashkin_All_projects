#pragma once
#include <iostream>
#include "MyException.h"

template <class T>
class TSortElem
{
protected:
  string key;
  T data;
public:
  TSortElem(string _key = "", T _data = 0);
  TSortElem(TSortElem<T> &obj);
  TSortElem<T>& operator=(TSortElem<T> &obj);
  bool operator==(TSortElem<T> &obj);
  bool operator>(TSortElem<T> &obj);
  bool operator<(TSortElem<T> &obj);
  void SetKey(string _key);
  string GetKey();
  void SetData(T _data);
  T GetData();
  T& GetDataAddress();
};//TSortElem
// ---------------------------------------------------------------------------
template <class T>
TSortElem<T>::TSortElem(string _key, T _data)
{
  key = _key;
  data = _data;
}
// ---------------------------------------------------------------------------
template <class T>
TSortElem<T>::TSortElem(TSortElem<T> &obj)
{
  key = obj.key;
  data = obj.data;
}
// ---------------------------------------------------------------------------
template <class T>
TSortElem<T>& TSortElem<T>::operator=(TSortElem<T> &obj)
{
  if (this != &obj)
  {
    key = obj.key;
    data = obj.data;
  }
  return *this;
}
// ---------------------------------------------------------------------------
template <class T>
bool TSortElem<T>::operator==(TSortElem &obj)
{
  if (key != obj.key)
    return 0;
  if (data != obj.data)
    return 0;
  return 1;
}
// ---------------------------------------------------------------------------
template <class T>
bool TSortElem<T>::operator<(TSortElem &obj)
{
  if (key.compare(obj.key)<0)
    return 1;
  return 0;
}
// ---------------------------------------------------------------------------
template <class T>
bool TSortElem<T>::operator>(TSortElem &obj)
{
  if (key.compare(obj.key) > 0)
    return 1;
  return 0;
}
// ---------------------------------------------------------------------------
template <class T>
void TSortElem<T>::SetKey(string _key)
{
  key = _key;
}
// ---------------------------------------------------------------------------
template <class T>
string TSortElem<T>::GetKey()
{
  return key;
}
// ---------------------------------------------------------------------------
template <class T>
void TSortElem<T>::SetData(T _data)
{
  data = _data;
}
// ---------------------------------------------------------------------------
template <class T>
T TSortElem<T>::GetData()
{
  return data;
}
// ---------------------------------------------------------------------------
template <class T>
T& TSortElem<T>::GetDataAddress()
{
  return data;
}