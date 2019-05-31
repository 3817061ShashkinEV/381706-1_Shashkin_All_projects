#include "NodeIter.h"

TNodeIter::TNodeIter(TNode *r)
{
  root = cur = r;
  stack.Put(root);
}
// ---------------------------------------------------------------------------
TNodeIter& TNodeIter::GoNext()
{
  cur = stack.Get();
  if (cur->GetNeighbour() != 0)
  {
    stack.Put(cur->GetNeighbour());
  }
  if (cur->GetNextLevel() != 0)
    stack.Put(cur->GetNextLevel());
  return *this;
}
// ---------------------------------------------------------------------------
void TNodeIter::Reset()
{
  cur = root;
  while (!(stack.IsEmpty()))
    stack.Get();
  stack.Put(cur);
}
// ---------------------------------------------------------------------------
bool TNodeIter::IsEnd()
{
  return stack.IsEmpty();
}
// ---------------------------------------------------------------------------
TNode* TNodeIter::operator()()
{
  return cur;
}
// ---------------------------------------------------------------------------
TNodeIter& TNodeIter::operator++(int)
{
  return (*this) = this->GoNext();
}