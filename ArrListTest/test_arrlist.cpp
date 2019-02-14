#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_arraylist)
{
	ASSERT_NO_THROW(TArrayList<int> arrlist);
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_create_arraylist_with_negative_size)
{
	ASSERT_ANY_THROW(TArrayList<int> arrlist(-1));
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_create_copied_arraylist)
{
	TArrayList<int> arrlist1(5);
	ASSERT_NO_THROW(TArrayList<int> arrlist2(arrlist1));
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_use_copy_arraylist_correctly)
{
	TArrayList<int> arrlist1(5);
	arrlist1.PutStart(1);
	TArrayList<int> arrlist2(arrlist1);
	EXPECT_EQ(arrlist1.GetStart(), arrlist2.GetStart());
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_put_and_get_start)
{
	TArrayList<int> arrlist(3);
	arrlist.PutStart(1);
	arrlist.PutStart(2);
	arrlist.PutStart(3);
	EXPECT_EQ(3, arrlist.GetStart());
	EXPECT_EQ(2, arrlist.GetStart());
	EXPECT_EQ(1, arrlist.GetStart());
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_put_and_get_end)
{
	TArrayList<int> arrlist(3);
	arrlist.PutEnd(1);
	arrlist.PutEnd(2);
	arrlist.PutEnd(3);
	EXPECT_EQ(3, arrlist.GetEnd());
	EXPECT_EQ(2, arrlist.GetEnd());
	EXPECT_EQ(1, arrlist.GetEnd());
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_put_elem)
{
	TArrayList<int> arrlist(5);
	arrlist.PutEnd(1);
	arrlist.PutEnd(2);
	arrlist.PutEnd(3);
	arrlist.PutEnd(4);
	arrlist.Put(3, 5);
	EXPECT_EQ(3, arrlist.Get(2));
	EXPECT_EQ(5, arrlist.Get(2));
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_get_elem)
{
	TArrayList<int> arrlist(3);
	arrlist.PutEnd(1);
	arrlist.PutEnd(2);
	arrlist.PutEnd(3);
	EXPECT_EQ(2, arrlist.Get(1));
	EXPECT_EQ(3, arrlist.Get(1));
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_use_isfull_correctly)
{
	TArrayList<int> arrlist(3);
	arrlist.PutEnd(1);
	arrlist.PutEnd(2);
	arrlist.PutEnd(3);
	ASSERT_TRUE(arrlist.IsFull());
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_use_isfull_incorrectly)
{
	TArrayList<int> arrlist(3);
	arrlist.PutEnd(1);
	arrlist.PutEnd(2);
	ASSERT_FALSE(arrlist.IsFull());
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_use_isempty_correctly)
{
	TArrayList<int> arrlist(3);
	ASSERT_TRUE(arrlist.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(ArrList, can_use_isempty_incorrectly)
{
	TArrayList<int> arrlist(3);
	arrlist.PutEnd(1);
	arrlist.PutEnd(2);
	arrlist.PutEnd(3);
	ASSERT_FALSE(arrlist.IsEmpty());
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_put_elem_to_start_but_arraylist_is_full)
{
	TArrayList<int> arrlist(3);
	arrlist.PutStart(1);
	arrlist.PutStart(2);
	arrlist.PutStart(3);
	ASSERT_ANY_THROW(arrlist.PutStart(4));
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_put_elem_to_end_but_arraylist_is_full)
{
	TArrayList<int> arrlist(3);
	arrlist.PutEnd(1);
	arrlist.PutEnd(2);
	arrlist.PutEnd(3);
	ASSERT_ANY_THROW(arrlist.PutEnd(4));
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_get_elem_from_start_but_arraylist_is_empty)
{
	TArrayList<int> arrlist(3);
	ASSERT_ANY_THROW(arrlist.GetStart());
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_get_elem_from_end_but_arraylist_is_empty)
{
	TArrayList<int> arrlist(3);
	ASSERT_ANY_THROW(arrlist.GetEnd());
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_put_elem_but_arraylist_is_full)
{
	TArrayList<int> arrlist(3);
	arrlist.PutStart(1);
	arrlist.PutStart(2);
	arrlist.PutStart(3);
	ASSERT_ANY_THROW(arrlist.Put(1,4));
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_get_elem_but_arraylist_is_empty)
{
	TArrayList<int> arrlist(3);
	ASSERT_ANY_THROW(arrlist.Get(1));
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_put_elem_with_incorrect_index)
{
	TArrayList<int> arrlist(3);
	arrlist.PutStart(1);
	arrlist.PutStart(2);
	arrlist.PutStart(3);
	ASSERT_ANY_THROW(arrlist.Put(3, 4));
}
// ---------------------------------------------------------------------------
TEST(ArrList, throw_when_try_to_get_elem_with_incorrect_index)
{
	TArrayList<int> arrlist(3);
	ASSERT_ANY_THROW(arrlist.Get(4));
}