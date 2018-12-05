#include <gtest.h>
#include <Stack.h>

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> S(1));
}
// ---------------------------------------------------------------------------
TEST(Stack, throw_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack<int> S(-5));
}
// ---------------------------------------------------------------------------
TEST(Stack, can_create_copied_stack)
{
  TStack<int> S1(5);
  ASSERT_NO_THROW(TStack<int> S2(S1));
}
// ---------------------------------------------------------------------------
TEST(Stack, can_put_an_element)
{
  TStack<int> S(5);
  int element = 10;
  ASSERT_NO_THROW(S.Put(10));
}
// ---------------------------------------------------------------------------
TEST(Stack, can_get_an_element)
{
  TStack<int> S(5);
  int element = 10;
  S.Put(element);
  EXPECT_EQ(element,S.Get());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isempty_correctly)
{
  TStack<int> S(5);
  ASSERT_TRUE(S.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isempty_incorrectly)
{
  TStack<int> S(2);
  S.Put(10);
  ASSERT_FALSE(S.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isfull_correctly)
{
  TStack<int> S(1);
  S.Put(10);
  ASSERT_TRUE(S.IsFull());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isfull_incorrectly)
{
  TStack<int> S(5);
  ASSERT_FALSE(S.IsFull());
}
// ---------------------------------------------------------------------------
TEST(Stack, throw_when_get_an_element_but_stack_is_empty)
{
  TStack<int> S(1);
  ASSERT_ANY_THROW(S.Get());
}
// ---------------------------------------------------------------------------
TEST(Stack, throw_when_put_an_element_but_stack_is_full)
{
  TStack<int> S(1);
  S.Put(10);
  ASSERT_ANY_THROW(S.Put(5));
}