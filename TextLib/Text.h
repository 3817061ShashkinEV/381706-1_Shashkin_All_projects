#include "Node.h"

class TText
{
protected:
	TNode* root;
public:
	TText();
	char* Copy(int start, int n);
	char* Del(int start, int n);
	void Ins(TNode* start, TNode* d); // �������
	TNode* Find(char* a); // ����� � �������� ����
	int FindIndex(char* a); // ����� � ��������� ������ �����

};//TText