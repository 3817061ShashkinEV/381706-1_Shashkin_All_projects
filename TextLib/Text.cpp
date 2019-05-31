#include "Text.h"

TText::TText()
{
  root = new TNode(0);
}
// ---------------------------------------------------------------------------
TText::TText(TNode* r)
{
  root = r;
}
// ---------------------------------------------------------------------------
TText::TText(TText &obj)
{
  root = obj.root->Clone();
}
// ---------------------------------------------------------------------------
TNode* TText::GetRoot()
{
  return root;
}
// ---------------------------------------------------------------------------
char* TText::Copy(int _start, int _n)
{
  char* res = new char[_n];
  bool f = false;
  int pos = 0;
  TNodeIter t(root);
  while (pos != _start)
  {
    if (t.IsEnd())
      throw TMyException("Incorrect values!\n");
    if (t()->GetLevel() == 3)
      pos++;
    t++;
  }
  pos = 0;
  while (pos < _n)
  {
    if (t.IsEnd())
      throw TMyException("Incorrect values!\n");
    if (t()->GetLevel() == 3)
    {
      res[pos] = t()->GetData();
      pos++;
    }
    t++;
  }
  return res;
}
// ---------------------------------------------------------------------------
void TText::Del(TNode* _start, int _n)
{

  TNodeIter iter(root);
  int i = _n;
  int count = 0;
  bool flag = false;
  bool nextflag = false;
  bool sameflag = false;
  TNode* temp1;
  TNode* temp2;
  TNode* temp3;
  while (iter.IsEnd() != true)
  {
    iter++;
    TNode* tmp = iter();
    if (tmp->GetNeighbour() == _start)
    {
      temp1 = tmp;
      sameflag = true;
    }
    if (tmp->GetNextLevel() == _start)
    {
      temp3 = tmp;
      nextflag = true;
    }
    if (tmp == _start)
    {
      delete tmp;
      i--;
      flag = true;
    }
    else if (flag == true && tmp->GetLevel() == 3)
    {
      if (i == 1)
        temp2 = tmp->GetNeighbour();
      delete tmp;
      i--;
    }
    if (i == 0)
      break;
  }
  if (nextflag == true)
    temp3->SetNextLevel(temp2);
  if (sameflag == true)
    temp1->SetNextLevel(temp2);
}
// ---------------------------------------------------------------------------
int TText::GetCount()
{
  TNodeIter i(root);
  int count = 0;
  for (; !(i.IsEnd()); i++)
    if (i()->GetLevel() == 3)
      count++;
  return count;
}
// ---------------------------------------------------------------------------
void TText::Ins(TNode* _start, TNode* _d)
{
  if (_start->GetLevel() != _d->GetLevel())
    throw TMyException("Different level!\n");
  _d->SetNeighbour(_start->GetNeighbour());
  _start->SetNeighbour(_d);
}
// ---------------------------------------------------------------------------
void TText::Ins(TNode* _start, std::string _str)
{
  if (_start->GetLevel() == 3)
    throw TMyException("Different level!\n");
  TNode* N = new TNode(_str);
  if (_start->GetLevel() == 0)
  {
    if (_start->GetNextLevel() == 0)
      _start->SetNextLevel(new TNode(1));
    _start = _start->GetNextLevel();
  }
  if (_start->GetLevel() == 1)
  {
    if (_start->GetNextLevel() == 0)
    {
      _start->SetNextLevel(N);
      return;
    }
    _start = _start->GetNextLevel();
  }
  N->SetNeighbour(_start->GetNeighbour());
  _start->SetNeighbour(N);
}
// ---------------------------------------------------------------------------
void TText::Ins(TNode* _start, char _c)
{
  if (_start->GetLevel() != 3)
    throw TMyException("Different level!\n");
  TNode* N = new TNode(_c);
  if (_start->GetLevel() == 0)
  {
    if (_start->GetNextLevel() == 0)
      _start->SetNextLevel(new TNode(1));
    _start = _start->GetNextLevel();
  }
  if (_start->GetLevel() == 1)
  {
    if (_start->GetNextLevel() == 0)
      _start->SetNextLevel(new TNode(1));
    _start = _start->GetNextLevel();
  }
  if (_start->GetLevel() == 2)
  {
    if (_start->GetNextLevel() == 0)
    {
      _start->SetNextLevel(N);
      return;
    }
    _start = _start->GetNextLevel();

  }
  N->SetNeighbour(_start->GetNeighbour());
  _start->SetNeighbour(N);
}
// ---------------------------------------------------------------------------
TNode* TText::Find(char* _a)
{
  TNodeIter i(root);
  for (; !(i.IsEnd()); i++)
  {
    if (i()->GetData() == _a[0])
    {
      bool f = true;
      TNodeIter j = i;
      int t = 1;
      while ((!(j.IsEnd())) && (_a[t] != '\0'))
      {
        if (j()->GetData() != _a[t])
        {
          f = false;
          break;
        }
        t++;
      }
      if (f = true)
        return i();
    }
  }
  return NULL;
}
// ---------------------------------------------------------------------------
int TText::FindIndex(char* _a)
{
  int k = -1;
  TNodeIter i(root);
  for (; !(i.IsEnd()); i++)
  {
    if (i()->GetLevel() == 3)
      k++;
    if (i()->GetData() == _a[0])
    {
      bool f = true;
      TNodeIter j = i;
      int t = 1;
      while ((!(j.IsEnd())) && (_a[t] != '\0'))
      {
        if (j()->GetData() != _a[t])
        {
          f = false;
          break;
        }
        t++;
      }
      if (f = true)
        return k;
    }
  }
  return -1;
}
// ---------------------------------------------------------------------------
ostream& operator<<(ostream& ostr, const TText &obj)
{
  TNodeIter i(obj.root);
  for (int k = 0; k < 3; k++)
  {
    if (i()->GetNextLevel() == 0)
      return ostr;
    i++;
  }
  for (; !(i.IsEnd()); i++)
  {
    if ((i()->GetLevel() == 3) && (i()->GetData() != -1))
      ostr << i()->GetData();
    else if ((i()->GetLevel() == 2) && (i()->GetNeighbour() != 0) && (i()->GetLevel() != 0))
      ostr << " ";
    else if (i()->GetLevel() == 1)
      ostr << endl;
  }
  return ostr;
}