#include "Node.h"
#include "Stack.h"

class TNodeIter
{
protected:
	TNode* root;
	TNode* cur;
	TStack<TNode*> St;
public:
	TNodeIter(TNode* r); // конструктор по умолчанию
	TNodeIter GoNext(); // перейти на следующий элемент
	void Reset(); // сбросить текущую позицию и установить указатель на начало
	bool IsEnd(); // если мы закончили, то возвращает правду
	TNode* operator() ();
	TNodeIter& operator++ ();
};//TNodeIter