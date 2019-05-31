#pragma once
#include "Point.h"
#include "Line.h"

class TPlex : public TPoint
{
protected:
  TPoint* left;
  TPoint* right;
public:
  TPlex();
  TPlex(TPoint* _left, TPoint* _right);
  TPlex(TPlex& P);
  TPoint* GetRight();
  TPoint* GetLeft();
  void SetRight(TPoint* _right);
  void SetLeft(TPoint* _left);
  void Add(TPoint* A, TPoint* B);
  virtual void Show();
  virtual TPoint* Show(TPlex* _plex);
};//TPlex