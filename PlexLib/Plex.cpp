#include "Plex.h"
#include <iostream>
#include "MyException.h"
#include "StackList.h"

TPlex::TPlex()
{
  right = NULL;
  left = NULL;
}
// ---------------------------------------------------------------------------
TPlex::TPlex(TPoint* _left, TPoint* _right)
{
  right = _right;
  left = _left;
}
// ---------------------------------------------------------------------------
TPlex::TPlex(TPlex &obj)
{
  TPlex *pleft, *pright;
  pleft = dynamic_cast<TPlex*>(obj.left);
  pright = dynamic_cast<TPlex*>(obj.right);

  if (pleft != 0)
    left = new TPlex(*pleft);
  else
    left = new TPoint(*pleft);

  if (pright != 0)
    right = new TPlex(*pright);
  else
    right = new TPoint(*pright);
}
// ---------------------------------------------------------------------------
TPoint* TPlex::GetRight()
{
  return right;
}
// ---------------------------------------------------------------------------
TPoint* TPlex::GetLeft()
{
  return left;
}
// ---------------------------------------------------------------------------
void TPlex::SetRight(TPoint* _right)
{
  right = _right;
}// ---------------------------------------------------------------------------
void TPlex::SetLeft(TPoint* _left)
{
  left = _left;
}
// ---------------------------------------------------------------------------
void TPlex::Add(TPoint* A, TPoint* B)
{
  if (right == 0 && left == 0)
  {
    right = A;
    left = B;
  }
  else
  {
    TStackList<TPoint*> point;
    TStackList<TPlex*> plex;
    point.Put(right);
    point.Put(left);
    plex.Put(this);
    plex.Put(this);
    bool flag = true;
    while (flag && (!point.IsEmpty() || !plex.IsEmpty()))
    {
      TPoint* t = point.Get();
      TPlex* p = dynamic_cast<TPlex*>(t);
      TPlex* par = plex.Get();
      if (t->GetX() == A->GetX() && t->GetY() == A->GetY())
      {
        if (par->left == t)
          par->left = new TPlex(B, A);
        else
          par->right = new TPlex(B, A);
        flag = false;
      }
      else if (t->GetX() == B->GetX() && t->GetY() == B->GetY())
      {
        if (par->left == t)
          par->left = new TPlex(A, B);
        else
          par->right = new TPlex(A, B);
        flag = false;
      }
      else if (p != 0)
      {
        point.Put(p->left);
        point.Put(p->right);
        plex.Put(p);
        plex.Put(p);
      }
    }
    if (flag)
      throw TMyException("Error! Line is not connected with plex!\n");
  }
}
// ---------------------------------------------------------------------------
void TPlex::Show()
{
  if (right == 0 && left == 0)
    throw TMyException("Error! Plex is empty!\n");
  TStackList<TPlex*> stack;
  TStackList<TPoint*> point;
  TPlex *pleft, *pright;
  TPlex *p = this;
  TPoint *tleft = NULL, *tright = NULL;
  stack.Put(p);
  while (!stack.IsEmpty())
  {
    p = stack.Get();
    while (tright == NULL)
    {
      pright = dynamic_cast<TPlex*>(p->right);
      pleft = dynamic_cast<TPlex*>(p->left);
      if (pright != 0 && pleft != 0)
      {
        if (point.GetSize() % 2 == 0)
          p = stack.Get();
        else if (point.GetSize() == 1)
        {
          tright = point.Get();
          tleft = point.Get();
        }
        else
        {
          stack.Put(p);
          stack.Put(pright);
          stack.Put(p);
          p = dynamic_cast<TPlex*>(pleft);
        }
      }
      else if (pright != NULL)
      {
        stack.Put(p);
        p = dynamic_cast<TPlex*>(pright);
      }
      else
      {
        tright = p->right;
      }
    }
    if (tleft == NULL)
    {
      pleft = dynamic_cast<TPlex*>(p->left);
      if (pleft != NULL)
      {
        stack.Put(p);
        p = dynamic_cast<TPlex*>(pleft);
        tright = NULL;
        stack.Put(p);
      }
      else
      {
        tleft = p->left;
      }
    }
    if (tright != NULL && tleft != NULL)
    {

      TLine A(*tleft, *tright);
      A.Show();
      cout << endl;
      if (!stack.IsEmpty())
      {
        p = stack.Get();
        pright = dynamic_cast<TPlex*>(p->right);
        pleft = dynamic_cast<TPlex*>(p->left);
        TPoint *pp = tleft;
        if (pright != 0 && pleft != 0)
        {
          point.Put(pp);
          tleft = NULL;
          tright = NULL;
        }
        else if (pright != 0)
        {
          tright = pp;
          tleft = NULL;
        }
        else
        {
          tleft = pp;
          tright = NULL;
        }
        stack.Put(p);
      }
    }
  }
}
// ---------------------------------------------------------------------------
TPoint* TPlex::Show(TPlex* P)
{
  TPlex *pleft, *pright;
  TPoint *tleft, *tright;

  pleft = dynamic_cast<TPlex*>(P->left);
  pright = dynamic_cast<TPlex*>(P->right);

  if (pleft != 0)
  {
    tleft = Show(pleft);
    cout << endl;
  }
  else
    tleft = P->left;

  if (pright != 0)
  {
    tright = Show(pright);
    cout << endl;
  }
  else
    tright = P->right;
  TLine L(*tright, *tleft);
  L.Show();
  cout << endl;
  return tright;
}