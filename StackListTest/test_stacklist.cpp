#include "gtest.h"
#include "StackList.h"

TEST(StackList, can_create_stacklist)
{
	ASSERT_NO_THROW(TStackList<int> stacklist);
}
// ---------------------------------------------------------------------------
TEST(StackList, throw_when_create_stacklist_with_negative_size)
{
	ASSERT_ANY_THROW(TStackList<int> stacklist(-1));
}
// ---------------------------------------------------------------------------
TEST(StackList, can_create_copied_stacklist)
{
	TStackList<int> stacklist1;
	ASSERT_NO_THROW(TStackList<int> stacklist2(stacklist1));
}
// ---------------------------------------------------------------------------
TEST(StackList, can_put_and_get_elem)
{
	TStackList<int> stacklist(3);
	stacklist.Put(1);
	stacklist.Put(2);
	stacklist.Put(3);
	EXPECT_EQ(3, stacklist.Get());
	EXPECT_EQ(2, stacklist.Get());
	EXPECT_EQ(1, stacklist.Get());
}
// ---------------------------------------------------------------------------
TEST(StackList, can_get_size)
{
	TStackList<int> stacklist(10);
	stacklist.Put(1);
	stacklist.Put(2);
	stacklist.Put(3);
	EXPECT_EQ(3, stacklist.GetSize());
}
// ---------------------------------------------------------------------------
TEST(StackList, can_get_max_size)
{
	TStackList<int> stacklist(10);
	EXPECT_EQ(10, stacklist.GetMaxSize());
}
// ---------------------------------------------------------------------------
TEST(StackList, can_use_isempty_correctly)
{
	TStackList<int> stacklist(10);
	ASSERT_TRUE(stacklist.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(StackList, can_use_isempty_incorrectly)
{
	TStackList<int> stacklist(2);
	stacklist.Put(10);
	ASSERT_FALSE(stacklist.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(StackList, throw_when_get_an_element_but_stack_is_empty)
{
	TStackList<int> stacklist(1);
	ASSERT_ANY_THROW(stacklist.Get());
}
// ---------------------------------------------------------------------------
TEST(StackList, throw_when_put_an_element_but_stack_is_full)
{
	TStackList<int> stacklist(1);
	stacklist.Put(10);
	ASSERT_ANY_THROW(stacklist.Put(5));
}
// ---------------------------------------------------------------------------
TEST(StackList, can_get_elements_in_the_right_order)
{
	TStackList<int> stacklist(3);
	stacklist.Put(10);
	stacklist.Put(9);
	stacklist.Put(8);
	EXPECT_EQ(8, stacklist.Get());
	EXPECT_EQ(9, stacklist.Get());
	EXPECT_EQ(10, stacklist.Get());
}
// ---------------------------------------------------------------------------
