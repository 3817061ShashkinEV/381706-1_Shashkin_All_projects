#include "gtest.h"
#include "Polish.h"

TEST(Polish, can_check_isoperation)
{
	EXPECT_EQ(true, IsOperation('('));
	EXPECT_EQ(true, IsOperation(')'));
	EXPECT_EQ(true, IsOperation('+'));
	EXPECT_EQ(true, IsOperation('-'));
	EXPECT_EQ(true, IsOperation('*'));
	EXPECT_EQ(true, IsOperation('/'));
	EXPECT_EQ(false, IsOperation('5'));
	EXPECT_EQ(false, IsOperation('.'));
}
// ---------------------------------------------------------------------------
TEST(Polish, can_get_priority)
{
	EXPECT_EQ(1, GetPriority('('));
	EXPECT_EQ(1, GetPriority(')'));
	EXPECT_EQ(2, GetPriority('+'));
	EXPECT_EQ(2, GetPriority('-'));
	EXPECT_EQ(3, GetPriority('*'));
	EXPECT_EQ(3, GetPriority('/'));
}
// ---------------------------------------------------------------------------
TEST(Polish, can_convert_to_polish_notation)
{
	char str1[] = "5+4";
	TMyString str2(str1);
	TQueue<char> queue;
	queue = ConvertToPolishNotation(str2);
	EXPECT_EQ('[', queue.Get());
	EXPECT_EQ('5', queue.Get());
	EXPECT_EQ(']', queue.Get());
	EXPECT_EQ('[', queue.Get());
	EXPECT_EQ('4', queue.Get());
	EXPECT_EQ(']', queue.Get());
	EXPECT_EQ('+', queue.Get());
}
// ---------------------------------------------------------------------------
TEST(Polish, can_add_correctly)
{
	char str1[] = "5+5";
	TMyString str2(str1);
	TQueue<char> queue;
	queue = ConvertToPolishNotation(str2);
	EXPECT_EQ(10, Result(queue));
}
// ---------------------------------------------------------------------------
TEST(Polish, can_subtract_correctly)
{
  char str1[] = "6-5";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertToPolishNotation(str2);
  EXPECT_EQ(1, Result(queue));
}
// ---------------------------------------------------------------------------
TEST(Polish, can_multiply_correctly)
{
  char str1[] = "5*5";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertToPolishNotation(str2);
  EXPECT_EQ(25, Result(queue));
}
// ---------------------------------------------------------------------------
TEST(Polish, can_divide_correctly)
{
  char str1[] = "10/5";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertToPolishNotation(str2);
  EXPECT_EQ(2, Result(queue));
}
// ---------------------------------------------------------------------------
TEST(Polish, can_solve_math_expresion_correctly)
{
  char str1[] = "(2+2*2)/3-1";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertToPolishNotation(str2);
  EXPECT_EQ(1, Result(queue));
}
// ---------------------------------------------------------------------------
TEST(Polish, trow_when_math_expression_has_incorrect_symbol)
{
  char str1[] = "5?5";
  TMyString str2(str1);
  ASSERT_ANY_THROW(ConvertToPolishNotation(str2));
}
// ---------------------------------------------------------------------------
TEST(Polish, trow_when_math_expression_has_incorrect_number_of_brackets)
{
  char str1[] = "(5+5";
  TMyString str2(str1);
  ASSERT_ANY_THROW(ConvertToPolishNotation(str2));
}
// ---------------------------------------------------------------------------
TEST(Polish, trow_when_math_expression_has_incorrect_sign_in_start)
{
  char str1[] = "*5+5";
  TMyString str2(str1);
  ASSERT_ANY_THROW(ConvertToPolishNotation(str2));
}
// ---------------------------------------------------------------------------

