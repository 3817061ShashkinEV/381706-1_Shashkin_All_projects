#include <gtest.h>
#include <Queue.h>

TEST(Queue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int> queue(10));
}
// ---------------------------------------------------------------------------
TEST(Queue, throw_when_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> queue(-10));
}
// ---------------------------------------------------------------------------
TEST(Queue, can_create_copied_queue)
{
  TQueue<int> queue1(10);
  ASSERT_NO_THROW(TQueue<int> queue2(queue1));
}
// ---------------------------------------------------------------------------
TEST(Queue, can_put_an_element)
{
  TQueue<int> queue(10);
  ASSERT_NO_THROW(queue.Put(10));
}
// ---------------------------------------------------------------------------
TEST(Queue, can_get_an_element)
{
  TQueue<int> queue(10);
  queue.Put(10);
  EXPECT_EQ(10, queue.Get());
}
// ---------------------------------------------------------------------------
TEST(Queue, can_use_isempty_correctly)
{
  TQueue<int> queue(10);
  ASSERT_TRUE(queue.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(Queue, can_use_isempty_incorrectly)
{
  TQueue<int> queue(10);
  queue.Put(10);
  ASSERT_FALSE(queue.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(Queue, can_use_isfull_correctly)
{
  TQueue<int> queue(1);
  queue.Put(10);
  ASSERT_TRUE(queue.IsFull());
}
// ---------------------------------------------------------------------------
TEST(Queue, can_use_isfull_incorrectly)
{
  TQueue<int> queue(10);
  ASSERT_FALSE(queue.IsFull());
}
// ---------------------------------------------------------------------------
TEST(Queue, throw_when_put_an_element_but_queue_is_full)
{
  TQueue<int> queue(1);
  queue.Put(10);
  ASSERT_ANY_THROW(queue.Put(5));
}
// ---------------------------------------------------------------------------
TEST(Queue, throw_when_get_an_element_but_queue_is_empty)
{
  TQueue<int> queue(10);
  ASSERT_ANY_THROW(queue.Get());
}
// ---------------------------------------------------------------------------
TEST(Queue, can_get_elements_in_the_right_order)
{
  TQueue<int> queue(3);
  queue.Put(10);
  queue.Put(9);
  queue.Put(8);
  EXPECT_EQ(10, queue.Get());
  EXPECT_EQ(9, queue.Get());
  EXPECT_EQ(8, queue.Get());
}


