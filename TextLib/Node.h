#pragma once
#include "MyException.h"

class TNode
{
protected:
	TNode* nextLevel;// указатель на следующий уровень
	TNode* neighbor;// указатель на соседа
	int level; // уровень листочка
	char data; // данное листочка
	static TNode* start; // начало
	static TNode* end; // конец
	static TNode* _free; // пустое место
	static char* mas; // набор байтов
	static int sizeMas; // размер массива, где будет вся наша память

public:
	TNode(char c);
	TNode(char* str);
	TNode(int _level);
	TNode(TNode &obj);
	void Init(int _size); // инициализация статических полей
	void* operator new (size_t n);
	void operator delete (void* a);
	TNode* GetNeighbor();
	TNode* GetNextLevel();
	static void GarbageCollector(); // сборщик мусора
}; //TNode