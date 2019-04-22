#include "Node.h"
#include "Stack.h"

class TNodeIter
{
protected:
	TNode* root;
	TNode* cur;
	TStack<TNode*> St;
public:
	TNodeIter(TNode* r); // ����������� �� ���������
	TNodeIter GoNext(); // ������� �� ��������� �������
	void Reset(); // �������� ������� ������� � ���������� ��������� �� ������
	bool IsEnd(); // ���� �� ���������, �� ���������� ������
	TNode* operator() ();
	TNodeIter& operator++ ();
};//TNodeIter