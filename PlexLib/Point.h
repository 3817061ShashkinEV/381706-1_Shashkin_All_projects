#pragma once

class TPoint
{
protected:
  double x;
  double y;
public:
  TPoint();
  TPoint(double _x, double _y);
  TPoint(TPoint &obj);
  double GetX();
  double GetY();
  void SetX(double _x);
  void SetY(double _y);
  bool operator==(TPoint &obj);
  virtual void Show();
};//TPoint