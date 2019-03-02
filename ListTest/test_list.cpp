#include <gtest.h>
#include "List.h"

TEST(List, can_create_list)
{
  ASSERT_NO_THROW(TList<int> list);
}
// ---------------------------------------------------------------------------
TEST(List, can_create_copied_list)
{
  TList<int> list1;
  ASSERT_NO_THROW(TList<int> list2(list1));
}
// ---------------------------------------------------------------------------
TEST(List, can_put_an_element_in_begin)
{
  TList<int> list;
  ASSERT_NO_THROW(list.PutBegin(5));
}
// ---------------------------------------------------------------------------
TEST(List, can_put_an_element_in_end)
{
  TList<int> list;
  ASSERT_NO_THROW(list.PutEnd(5));
}
// ---------------------------------------------------------------------------
TEST(List, can_get_an_element_from_begin)
{
  TList<int> list;
  list.PutBegin(5);
  EXPECT_EQ(5, list.GetBegin());
}
// ---------------------------------------------------------------------------
TEST(List, can_get_an_element_from_end)
{
  TList<int> list;
  list.PutEnd(5);
  EXPECT_EQ(5, list.GetEnd());
}
// ---------------------------------------------------------------------------
TEST(List, can_use_isempty_correctly)
{
  TList<int> list;
  ASSERT_TRUE(list.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(List, can_use_isempty_incorrectly)
{
  TList<int> list;
  list.PutBegin(5);
  ASSERT_FALSE(list.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(List, throw_when_get_an_element_from_begin_but_list_is_empty)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetBegin());
}
// ---------------------------------------------------------------------------
TEST(List, throw_when_get_an_element_from_end_but_list_is_empty)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetEnd());
}
// ---------------------------------------------------------------------------
TEST(List, can_use_get_an_element_via_index)
{
  TList<int> list;
  list.PutEnd(9);
  list.PutEnd(8);
  list.PutEnd(7);
  list.PutEnd(6);
  list.PutEnd(5);
  EXPECT_EQ(5, list.GetElem(4));
}
// ---------------------------------------------------------------------------
TEST(List, can_use_get_an_element_via_index_correctly)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetElem(1));
}
// ---------------------------------------------------------------------------
TEST(List, can_use_put_an_element_via_index)
{
  TList<int> list;
  list.PutEnd(9);
  list.PutEnd(8);
  list.PutEnd(7);
  list.PutEnd(6);
  list.PutEnd(5);
  list.PutElem(1, 1);
  EXPECT_EQ(1, list.GetElem(1));
}
// ---------------------------------------------------------------------------
TEST(List, can_use_put_an_element_via_index_correctly)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetElem(0));
}