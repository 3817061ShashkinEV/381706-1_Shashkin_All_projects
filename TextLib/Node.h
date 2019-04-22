#pragma once
#include "MyException.h"

class TNode
{
protected:
	TNode* nextLevel;// ��������� �� ��������� �������
	TNode* neighbor;// ��������� �� ������
	int level; // ������� ��������
	char data; // ������ ��������
	static TNode* start; // ������
	static TNode* end; // �����
	static TNode* _free; // ������ �����
	static char* mas; // ����� ������
	static int sizeMas; // ������ �������, ��� ����� ��� ���� ������

public:
	TNode(char c);
	TNode(char* str);
	TNode(int _level);
	TNode(TNode &obj);
	void Init(int _size); // ������������� ����������� �����
	void* operator new (size_t n);
	void operator delete (void* a);
	TNode* GetNeighbor();
	TNode* GetNextLevel();
	static void GarbageCollector(); // ������� ������
}; //TNode