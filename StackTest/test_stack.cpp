#include <gtest.h>
#include <Stack.h>

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> stack(1));
}
// ---------------------------------------------------------------------------
TEST(Stack, throw_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack<int> stack(-5));
}
// ---------------------------------------------------------------------------
TEST(Stack, can_create_copied_stack)
{
  TStack<int> stack1(5);
  ASSERT_NO_THROW(TStack<int> stack2(stack1));
}
// ---------------------------------------------------------------------------
TEST(Stack, can_put_an_element)
{
  TStack<int> stack(5);
  int element = 10;
  ASSERT_NO_THROW(stack.Put(10));
}
// ---------------------------------------------------------------------------
TEST(Stack, can_get_an_element)
{
  TStack<int> stack(5);
  stack.Put(10);
  EXPECT_EQ(10,stack.Get());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isempty_correctly)
{
  TStack<int> stack(5);
  ASSERT_TRUE(stack.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isempty_incorrectly)
{
  TStack<int> stack(2);
  stack.Put(10);
  ASSERT_FALSE(stack.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isfull_correctly)
{
  TStack<int> stack(1);
  stack.Put(10);
  ASSERT_TRUE(stack.IsFull());
}
// ---------------------------------------------------------------------------
TEST(Stack, can_use_isfull_incorrectly)
{
  TStack<int> stack(5);
  ASSERT_FALSE(stack.IsFull());
}
// ---------------------------------------------------------------------------
TEST(Stack, throw_when_get_an_element_but_stack_is_empty)
{
  TStack<int> stack(1);
  ASSERT_ANY_THROW(stack.Get());
}
// ---------------------------------------------------------------------------
TEST(Stack, throw_when_put_an_element_but_stack_is_full)
{
  TStack<int> stack(1);
  stack.Put(10);
  ASSERT_ANY_THROW(stack.Put(5));
}