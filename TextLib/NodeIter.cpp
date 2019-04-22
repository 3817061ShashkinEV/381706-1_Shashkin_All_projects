#include "NodeIter.h"

TNodeIter::TNodeIter(TNode* r)
{
	root = cur = r;
	St.Put(root);
}
// ---------------------------------------------------------------------------
TNodeIter TNodeIter::GoNext()
{
	cur = St.Get();

	if (cur->GetNeighbor() != NULL)
		St.Put(cur->GetNeighbor());

	if (cur->GetNextLevel() != NULL)
		St.Put(cur->GetNextLevel());
	return *this;
}
// ---------------------------------------------------------------------------
void TNodeIter::Reset()
{
	cur = root;
	St.Clear();
	St.Put(cur);
}
// ---------------------------------------------------------------------------
bool TNodeIter::IsEnd()
{
	return St.IsEmpty();
}
// ---------------------------------------------------------------------------
TNode* TNodeIter::operator()()
{
	return cur;
}
// ---------------------------------------------------------------------------
TNodeIter& TNodeIter::operator++()
{
	return GoNext();
}