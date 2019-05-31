#pragma once
#include "StackList.h"
#include "Node.h"

class TNodeIter
{
protected:
  TNode* root;
  TNode* cur;
  TStackList <TNode*> stack;
public:
  TNodeIter(TNode* r);
  TNodeIter& GoNext();
  void Reset();
  bool IsEnd();
  TNode* operator() ();
  TNodeIter& operator++ (int);
};//TNodeIter