#include "Node.h"

TNode* TNode::start = 0;
TNode* TNode::end = 0;
TNode* TNode::_free = 0;
char* TNode::mas = 0;
int TNode::sizeMas = 0;

// ---------------------------------------------------------------------------
TNode::TNode(char c)
{
	data = c;
	nextLevel = neighbor = NULL;
	level = 3;
}
// ---------------------------------------------------------------------------
TNode::TNode(char* str)
{
	data = 0;
	nextLevel = new TNode(str[0]);
	level = 2;
	neighbor = NULL;
	TNode* b = nextLevel;
	int l = strlen(str);
	for (int i = 1; i < l; i++)
	{
		b->neighbor = new TNode(str[i]);
		b = b->neighbor;
	}
}
// ---------------------------------------------------------------------------
TNode::TNode(int _level)
{
	if (_level >= 0 && _level < 4)
	{
		level = _level;
		data = 0;
		nextLevel = NULL;
		neighbor = NULL;
	}
	else
		throw TMyException("Error! Wrong level!\n");
}
// ---------------------------------------------------------------------------
TNode::TNode(TNode &obj)
{
	data = obj.data;
	nextLevel = obj.nextLevel;
	neighbor = obj.neighbor;
	level = obj.level;
}
// ---------------------------------------------------------------------------
void TNode::Init(int _size)
{
	if (mas == 0)
	{
		sizeMas = _size;
		int l = _size * sizeof(TNode);
		mas = new char(l);
		start = (TNode*)(mas);
		end = _free = start;
		for (int i = 1; i < _size; i++)
		{
			int j = i * sizeof(TNode);
			end->nextLevel = (TNode*)(&mas[j]);
		}
		end->nextLevel = 0;
	}
}
// ---------------------------------------------------------------------------
void * TNode::operator new(size_t n)
{
	if (_free != 0)
	{
		TNode* a = _free;
		_free = _free->nextLevel;
		return a;
	}
	return nullptr;
}
// ---------------------------------------------------------------------------
void TNode::operator delete(void* a)
{
	TNode* t = (TNode*)(a);
	t->nextLevel = _free;
	_free = t;
	t->data = -1;
}
// ---------------------------------------------------------------------------
void TNode::GarbageCollector()
{
	_free = 0;
	for (int i = 0; i < sizeMas; i++)
	{
		int j = i * sizeof(TNode);
		if (((TNode*)(&mas[j]))->data == '-1')
		{
			((TNode*)(&mas[j]))->nextLevel = _free;
			_free = (TNode*)(&mas[j]);
		}
	}
}
// ---------------------------------------------------------------------------
TNode* TNode::GetNeighbor()
{
	return neighbor;
}
// ---------------------------------------------------------------------------
TNode* TNode::GetNextLevel()
{
	return nextLevel;
}