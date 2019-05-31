#include "Node.h"
#include "StackList.h"
#include "MyException.h"
#include <iostream>

TNode* TNode::start = 0;
TNode* TNode::end = 0;
TNode* TNode::_free = 0;
char* TNode::mas = 0;
int TNode::sizeMas = 0;
// ---------------------------------------------------------------------------
TNode::TNode(char _c)
{
  Init(200000);
  nextLevel = NULL;
  neighbour = NULL;
  level = 3;
  data = _c;
}
// ---------------------------------------------------------------------------
TNode::TNode(std::string _str)
{
  Init(200000);
  if (_str.length() == 0)
    throw TMyException("Inccorrect string!\n");
  data = 0;
  nextLevel = new TNode(_str[0]);
  level = 2;
  neighbour = 0;
  TNode *a = nextLevel;
  for (int i = 1; i < _str.length(); i++)
  {
    a->SetNeighbour(new TNode(_str[i]));
    a = a->GetNeighbour();
  }
}
// ---------------------------------------------------------------------------
TNode::TNode(int _level)
{
  Init(200000);
  if ((_level < 0) || (_level > 3))
    throw TMyException("Incorrect level!\n");
  nextLevel = 0;
  neighbour = 0;
  level = _level;
  data = -1;
}
// ---------------------------------------------------------------------------
TNode::TNode(TNode &obj)
{
  data = obj.data;
  nextLevel = obj.nextLevel;
  neighbour = obj.neighbour;
  level = obj.level;
}
// ---------------------------------------------------------------------------
TNode& TNode::operator=(const TNode &obj)
{
  data = obj.data;
  level = obj.level;
  neighbour = obj.neighbour;
  nextLevel = obj.nextLevel;
  return *this;
}
// ---------------------------------------------------------------------------
TNode& TNode::operator+=(TNode &obj)
{
  if (level < obj.level)
    throw TMyException("Incorrect level\n");
  TStackList<TNode*> st;
  st.Put(this);
  bool f = true;
  TNode* t;
  while (f || st.IsEmpty())
  {
    t = st.Get();
    if (t->nextLevel != 0)
      st.Put(t->nextLevel);
    if (t->neighbour != 0)
      st.Put(t->neighbour);
    if ((t->level = obj.level) && (t->neighbour == 0))
    {
      f = false;
      t->neighbour = obj.Clone();
    }
  }
  return *this;
}
// ---------------------------------------------------------------------------
TNode& TNode::operator+=(char _c)
{
  TNode symbol(_c);
  return (*this += symbol);
}
// ---------------------------------------------------------------------------
TNode& TNode::operator+=(char* _c)
{
  TNode word(_c);
  return (*this += word);
}
// ---------------------------------------------------------------------------
char* TNode::ToStr()
{
  int l = 0;
  int j = 0;
  TStackList<TNode*> st;
  TNode* t;
  st.Put(this);
  while (!st.IsEmpty())
  {
    t = st.Get();
    if (t->nextLevel != 0)
      st.Put(t->nextLevel);
    if (t->neighbour != 0)
      st.Put(t->neighbour);
    if (t->level == 3)
      l++;
  }
  char* res = new char[l + 1];
  st.Put(this);
  while (!st.IsEmpty())
  {
    t = st.Get();
    if (t->level == 3)
    {
      res[j] = t->data;
      j++;
    }
    if (t->neighbour != 0)
      st.Put(t->neighbour);
    if (t->nextLevel != 0)
      st.Put(t->nextLevel);
  }
  res[l] = 0;
  return res;
}
// ---------------------------------------------------------------------------
TNode* TNode::Clone()
{
  TNode* res = new TNode(*this);
  TStackList<TNode*> st;
  TStackList<TNode*> copy;
  st.Put(this);
  copy.Put(res);
  while (!st.IsEmpty())
  {
    TNode* t = st.Get();
    TNode* c = copy.Get();
    if (t->neighbour != 0)
    {
      c->neighbour = new TNode(*(t->neighbour));
      st.Put(t->neighbour);
      copy.Put(c->neighbour);
    }
    if (t->nextLevel != 0)
    {
      c->nextLevel = new TNode(*(t->nextLevel));
      st.Put(t->nextLevel);
      copy.Put(c->nextLevel);
    }
  }
  return res;
}
// ---------------------------------------------------------------------------
int TNode::GetLevel()
{
  return level;
}
// ---------------------------------------------------------------------------
void TNode::SetLevel(int _level)
{
  if ((_level < 0) || (_level > 3))
    throw TMyException("Incorrect level!\n");
}
// ---------------------------------------------------------------------------
TNode* TNode::GetNextLevel()
{
  return nextLevel;
}
// ---------------------------------------------------------------------------
void TNode::SetNextLevel(TNode* _nextLevel)
{
  nextLevel = _nextLevel;
}
// ---------------------------------------------------------------------------
TNode* TNode::GetNeighbour()
{
  return neighbour;
}
// ---------------------------------------------------------------------------
void TNode::SetNeighbour(TNode* _neighbour)
{
  neighbour = _neighbour;
}
// ---------------------------------------------------------------------------
char TNode::GetData()
{
  return data;
}
// ---------------------------------------------------------------------------
void TNode::SetData(char _c)
{
  data = _c;
}
// ---------------------------------------------------------------------------
void TNode::Init(int _size)
{
  if (mas == 0)
  {
    sizeMas = _size;
    int l = _size * sizeof(TNode);
    mas = new char[l];
    start = (TNode*)(mas);
    end = _free = start;
    for (int i = 1; i < _size; i++)
    {
      int j = i * sizeof(TNode);
      end->neighbour = (TNode*)(&mas[j]);
      end = end->neighbour;
    }
    end->neighbour = 0;
  }
}
// ---------------------------------------------------------------------------
void* TNode::operator new(size_t _n)
{
  if (_free == 0)
    GC();
  if (_free != 0)
  {
    TNode* a = _free;
    _free = _free->neighbour;
    return a;
  }
  return NULL;
}
// ---------------------------------------------------------------------------
void TNode::operator delete(void* _a)
{
  TNode* t = (TNode*)(_a);
  t->neighbour = _free;
  _free = t;
  t->data = -1;
}
// ---------------------------------------------------------------------------
void TNode::GC()
{
  _free = 0;
  for (int i = 0; i < sizeMas; i++)
  {
    int j = i * sizeof(TNode);
    if (((TNode*)(&mas[j]))->data == '-1')
    {
      ((TNode*)(&mas[j]))->neighbour = _free;
      _free = (TNode*)(&mas[j]);
    }
  }
}