#pragma once
#include <iostream>

class TNode 
{
protected:
  TNode* nextLevel;
  TNode* neighbour;
  int level;
  char data;
  static TNode* start;
  static TNode* end;
  static TNode* _free;
  static char* mas;
  static int sizeMas;
public:
  TNode(char _c);
  TNode(std::string _str);
  TNode(int _level);
  TNode(TNode &obj);
  TNode& operator=(const TNode &obj);
  TNode& operator+=(TNode &obj);
  TNode& operator+=(char _c);
  TNode& operator+=(char* _c);
  char* ToStr();
  TNode* Clone();
  int GetLevel();
  void SetLevel(int _level);
  TNode* GetNextLevel();
  void SetNextLevel(TNode* _nextLevel);
  TNode* GetNeighbour();
  void SetNeighbour(TNode* _neighbour);
  char GetData();
  void SetData(char _c);
  void Init(int _size);
  void* operator new (size_t n);
  void operator delete (void* a);
  static void GC();
};//TNode