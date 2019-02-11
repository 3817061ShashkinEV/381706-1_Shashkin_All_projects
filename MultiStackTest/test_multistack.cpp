#include <gtest.h>
#include "MultiStack.h"

TEST(NewStack, can_create_newstack)
{
  int* tmp = 0;
  ASSERT_NO_THROW(TNewStack<int>(5, tmp));
}
// ---------------------------------------------------------------------------
TEST(NewStack, throw_when_create_newstack_with_negative_size)
{
  int* tmp = 0;
  ASSERT_ANY_THROW(TNewStack<int>(-5, tmp));
}
// ---------------------------------------------------------------------------
TEST(NewStack, can_create_copied_newstack)
{
  int* tmp = 0;
  TNewStack<int> newstack1(5, tmp);
  ASSERT_NO_THROW(TNewStack<int> newstack2(newstack1));
}
// ---------------------------------------------------------------------------
TEST(NewStack, can_set_multistack)
{
  int* tmp1 = new int [5];
  int* tmp2 = new int[5];
  TNewStack<int> newstack(5, tmp1);
  newstack.SetM(6, tmp2);
  EXPECT_EQ(6,newstack.GetSize());
}
// ---------------------------------------------------------------------------
TEST(NewStack, can_get_freemem)
{
  int* tmp = new int[5];
  TNewStack<int> newstack(5, tmp);
  newstack.Put(1);
  newstack.Put(2);
  newstack.Put(3);
  EXPECT_EQ(2, newstack.GetFreeMem());
}
// ---------------------------------------------------------------------------
TEST(NewStack, can_get_size)
{
  int* tmp = 0;
  TNewStack<int> newstack(5, tmp);
  EXPECT_EQ(5, newstack.GetSize());
}
// ---------------------------------------------------------------------------
TEST(NewStack, can_get_top)
{
  int* tmp = new int[3];
  TNewStack<int> newstack(3, tmp);
  newstack.Put(1);
  newstack.Put(2);
  newstack.Put(3);
  EXPECT_EQ(3, newstack.GetTop());
}
// ---------------------------------------------------------------------------
TEST(NewStack, can_put_and_get_elem)
{
  int* tmp = new int[3];
  TNewStack<int> newstack(3, tmp);
  newstack.Put(1);
  newstack.Put(2);
  newstack.Put(3);
  EXPECT_EQ(3, newstack.Get());
  EXPECT_EQ(2, newstack.Get());
}
// ---------------------------------------------------------------------------
TEST(MultiStack, can_create_multistack)
{
  ASSERT_NO_THROW(TMStack<int>(5, 10));
}
// ---------------------------------------------------------------------------
TEST(MultiStack, throw_when_create_multistack_with_negarive_size)
{
  ASSERT_ANY_THROW(TMStack<int>(5, -10));
}
// ---------------------------------------------------------------------------
TEST(MultiStack, can_create_copied_multistack)
{
  TMStack<int> multistack1(5, 10);
  ASSERT_NO_THROW(TMStack<int>multistack2(multistack1));
}
// ---------------------------------------------------------------------------
/*TEST(MultiStack, can_put_elem)
{
  TMStack<int> multistack(5, 10);
  ASSERT_NO_THROW(multistack.PutElem(0,1));
}*/
// ---------------------------------------------------------------------------
TEST(MultiStack, can_get_size)
{
  TMStack<int> multistack(5, 10);
  EXPECT_EQ(10, multistack.GetSize());
}
// ---------------------------------------------------------------------------
TEST(MultiStack, can_get_elem)
{
  TMStack<int> multistack(5, 10);
  multistack.PutElem(1, 6);
  EXPECT_EQ(6, multistack.GetElem(1));
}
// ---------------------------------------------------------------------------

