#pragma once
#include "Node.h"
#include "NodeIter.h"
#include <iostream>

class TText
{
protected:
  TNode *root;
public:
  TText();
  TText(TNode* r);
  TText(TText &obj);
  TNode* GetRoot();
  char* Copy(int _start, int _n);
  void Del(TNode* _start, int _n);
  void Ins(TNode* _start, TNode* _d);
  void Ins(TNode* _start, std::string _str);
  void Ins(TNode* _start, char _c);
  TNode* Find(char* _a);
  int FindIndex(char* _a);
  int GetCount();
  friend ostream& operator<<(ostream& ostr, const TText &obj);
};//TText