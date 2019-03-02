#include "Polish.h"
#include <cstdlib>

bool IsOperation(char _op)
{
	return (_op == '+' || _op == '-' || _op == '*' || _op == '/' || _op == '(' || _op == ')');
}
// ---------------------------------------------------------------------------
int GetPriority(const char _op)
{
	switch (_op)
	{
	case '(':
		return 1;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		throw TMyException("Error! Incorrect symbol!\n");
	}
}
// ---------------------------------------------------------------------------
TQueue<char> ConvertToPolishNotation(TMyString _str)
{
	int op = 0;
	int cl = 0;
	TQueue<char> Queue(_str.GetLen() * 3);
	TStack<char> Stack(_str.GetLen() * 3);
	for (int i = 0; i < _str.GetLen(); i++)
	{
		if (i == 0)
		{
			if (_str[0] == '-')
			{
				Queue.Put('[');
				Queue.Put('0');
				Queue.Put(']');
			}
			else if (IsOperation(_str[0]))
				if (GetPriority(_str[0]) != 1)
					throw TMyException("Error! Incorrect math expression!\n");
		}
		if (isdigit(_str[i]))
		{
			Queue.Put('[');
			while ((i < _str.GetLen()) && isdigit(_str[i + 1]))
			{
				Queue.Put(_str[i]);
				i++;
			}
			Queue.Put(_str[i]);
			Queue.Put(']');
		}
		else if (Stack.IsEmpty() && IsOperation(_str[i]))
		{
			Stack.Put(_str[i]);
			if (_str[i] == '(')
				op++;
			if (_str[i] == ')')
				throw TMyException("Error! Incorrect math expression!\n");
		}
		else if (IsOperation(_str[i]))
		{
			if (_str[i] == '(')
			{
				Stack.Put(_str[i]);
				op++;
			}
			else if (_str[i] == ')')
			{
				cl++;
				while (Stack.ShowTop() != '(')
					Queue.Put(Stack.Get());
				Stack.Get();
			}
			else
			{
				int p = GetPriority(_str[i]);
				if (p > GetPriority(Stack.ShowTop()))
					Stack.Put(_str[i]);
				else if (p <= GetPriority(Stack.ShowTop()))
				{
					while (!Stack.IsEmpty() && p <= GetPriority(Stack.ShowTop()))
						Queue.Put(Stack.Get());
					Stack.Put(_str[i]);
				}
			}
		}
		else if (_str[i] != '\0')
			throw TMyException("Error! Incorrect math expression!\n");
	}
	while (!Stack.IsEmpty())
		Queue.Put(Stack.Get());
	if (op != cl)
		throw TMyException("Error! Incorrect math expression!\n");
	return Queue;
}
// ---------------------------------------------------------------------------
double Result(TQueue<char> _queue)
{
	double rez = 0;
	TStack<double> Stack(_queue.GetSize());
	if (IsOperation(_queue.ShowTop()))
		throw TMyException("Error! Incorrect queue!\n");
	int i = 0;
	int dit = 0;
	int t = 0;
	while (!_queue.IsEmpty())
	{
		i++;
		char A = _queue.Get();
		if (A == '[')
		{
			dit++;
			A = _queue.Get();
			double tmp = std::atof(&A);
			while (_queue.ShowTop() != ']' && !_queue.IsEmpty())
			{
				A = _queue.Get();
				tmp = tmp * 10 + std::atof(&A);
			}
			_queue.Get();
			Stack.Put(tmp);
		}
		else if (IsOperation(A))
		{
			double B = Stack.Get();
			double C = Stack.Get();
			double D = 0;
			if (A == '+')
				D = C + B;
			if (A == '-')
				D = C - B;
			if (A == '*')
				D = C * B;
			if (A == '/')
				D = C / B;
			Stack.Put(D);
		}
		else
			throw TMyException("Error! Incorrect symbol in queue!\n");
		if (i == 2 && dit != 2)
			throw TMyException("Error! Incorrect queue!\n");
	}
	rez = Stack.Get();
	if (!Stack.IsEmpty())
		throw TMyException("Error! Incorrect queue!\n");
	return rez;
}