#include "gtest.h"
#include "Polynom.h"

TEST(Monom, can_create_monom)
{
	int degrees[] = { 1,2,3,4,5 };
	ASSERT_NO_THROW(TMonom monom(5, degrees, 1));
}
// ---------------------------------------------------------------------------
TEST(Monom, throw_when_create_monom_with_negative_size)
{
	int degrees[] = { 1,2,3,4,5 };
	ASSERT_ANY_THROW(TMonom monom(-5, degrees, 1));
}
// ---------------------------------------------------------------------------
TEST(Monom, throw_when_create_monom_with_negative_degrees)
{
	int degrees[] = { 1,2,-3,-4,5 };
	ASSERT_ANY_THROW(TMonom monom(5, degrees, 1));
}
// ---------------------------------------------------------------------------
TEST(Monom, can_create_copied_monom)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom1(5, degrees, 1);
	ASSERT_NO_THROW(TMonom monom2(monom1));
}
// ---------------------------------------------------------------------------
TEST(Monom, can_set_next)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 1);
	ASSERT_NO_THROW(monom1.SetNext(&monom2));
}
// ---------------------------------------------------------------------------
TEST(Monom, can_get_next)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 1);
	monom1.SetNext(&monom2);
	EXPECT_EQ(&monom2, monom1.GetNext());
}
// ---------------------------------------------------------------------------
TEST(Monom, can_set_degree)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom(5, degrees1, 1);
	ASSERT_NO_THROW(monom.SetDegree(degrees2));
}
// ---------------------------------------------------------------------------
TEST(Monom, can_get_degree)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom(5, degrees1, 1);
	monom.SetDegree(degrees2);
	EXPECT_EQ(degrees2[0], monom.GetDegree()[0]);
	EXPECT_EQ(degrees2[1], monom.GetDegree()[1]);
	EXPECT_EQ(degrees2[2], monom.GetDegree()[2]);
	EXPECT_EQ(degrees2[3], monom.GetDegree()[3]);
	EXPECT_EQ(degrees2[4], monom.GetDegree()[4]);
}
// ---------------------------------------------------------------------------
TEST(Monom, can_set_count)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom(5, degrees, 1);
	ASSERT_NO_THROW(monom.SetCount(4));
}
// ---------------------------------------------------------------------------
TEST(Monom, can_get_count)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom(5, degrees, 1);
	monom.SetCount(4);
	EXPECT_EQ(4, monom.GetCount());
}
// ---------------------------------------------------------------------------
TEST(Monom, assign_operator_works_correctly)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 2);
	ASSERT_NO_THROW(monom1=monom2);
	EXPECT_EQ(degrees2[0], monom1.GetDegree()[0]);
	EXPECT_EQ(degrees2[1], monom1.GetDegree()[1]);
	EXPECT_EQ(degrees2[2], monom1.GetDegree()[2]);
	EXPECT_EQ(degrees2[3], monom1.GetDegree()[3]);
	EXPECT_EQ(degrees2[4], monom1.GetDegree()[4]);
	EXPECT_EQ(2, monom1.GetCoefficient());
}
// ---------------------------------------------------------------------------
TEST(Monom, throw_when_assign_monoms_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(6, degrees2, 2);
	ASSERT_ANY_THROW(monom1 = monom2);
}
// ---------------------------------------------------------------------------
TEST(Monom, can_add_monoms)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom1(5, degrees, 1);
	TMonom monom2(5, degrees, 2);
	TMonom monom3(5, degrees, 1);
	ASSERT_NO_THROW(monom1 + monom2);
	monom3 = monom1 + monom2;
	EXPECT_EQ(3, monom3.GetCoefficient());
}
// ---------------------------------------------------------------------------
TEST(Monom, throw_when_add_different_monoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 2);
	ASSERT_ANY_THROW(monom1 + monom2);
}
// ---------------------------------------------------------------------------
TEST(Monom, can_subtract_monoms)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom1(5, degrees, 3.4);
	TMonom monom2(5, degrees, 2.0);
	TMonom monom3(5, degrees, 1);
	ASSERT_NO_THROW(monom1 - monom2);
	monom3 = monom1 - monom2;
	EXPECT_EQ(1.4, monom3.GetCoefficient());
}
// ---------------------------------------------------------------------------
TEST(Monom, throw_when_subtract_different_monoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 2);
	ASSERT_ANY_THROW(monom2 - monom1);
}
// ---------------------------------------------------------------------------
TEST(Monom, can_multiply_monoms)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom1(5, degrees, 3.4);
	TMonom monom2(5, degrees, 2.0);
	TMonom monom3(5, degrees, 1);
	ASSERT_NO_THROW(monom1 * monom2);
	monom3 = monom1 * monom2;
	EXPECT_EQ(6.8, monom3.GetCoefficient());
}
// ---------------------------------------------------------------------------
TEST(Monom, throw_when_multiply_different_monoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(6, degrees2, 1);
	ASSERT_ANY_THROW(monom1 * monom2);
}
// ---------------------------------------------------------------------------
TEST(Monom, can_equal_monoms_correctly)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom1(5, degrees, 2.0);
	TMonom monom2(5, degrees, 2.0);
	ASSERT_TRUE(monom1 == monom2);
}
// ---------------------------------------------------------------------------
TEST(Monom, thorw_when_euqal_monoms_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 2.0);
	TMonom monom2(6, degrees2, 2.0);
	ASSERT_ANY_THROW(monom1 == monom2);
}
// ---------------------------------------------------------------------------
TEST(Monom, can_compare_monoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 3.1);
	TMonom monom2(5, degrees2, 2.2);
	ASSERT_TRUE(monom2 > monom1);
}
// ---------------------------------------------------------------------------
TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolynom polynom(5));
}
// ---------------------------------------------------------------------------
TEST(Polynom, throw_when_create_polynom_with_negative_size)
{
	ASSERT_ANY_THROW(TPolynom polynom(-5));
}
// ---------------------------------------------------------------------------
TEST(Polynom, can_create_copied_polynom)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom(5,degrees,1);
	TPolynom polynom1(5);
	polynom1 += monom;
	ASSERT_NO_THROW(TPolynom polynom2(polynom1));
}
// ---------------------------------------------------------------------------
TEST(Polynom, can_get_size)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom(5, degrees, 1);
	TPolynom polynom(5);
	polynom += monom;
	EXPECT_EQ(1,polynom.GetSize());
}
// ---------------------------------------------------------------------------
TEST(Polynom, can_add_polynoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 2);
	TPolynom polynom1(5);
	TPolynom polynom2(5);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_NO_THROW(polynom1+polynom2);
}
// ---------------------------------------------------------------------------
TEST(Polynom, throw_when_add_different_polynoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(6, degrees2, 2);
	TPolynom polynom1(5);
	TPolynom polynom2(6);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_ANY_THROW(polynom1 + polynom2);
}
// ---------------------------------------------------------------------------
TEST(Polynom, can_subtract_polynoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 2);
	TPolynom polynom1(5);
	TPolynom polynom2(5);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_NO_THROW(polynom1 - polynom2);
}
// ---------------------------------------------------------------------------
TEST(Polynom, throw_when_subtract_different_polynoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(6, degrees2, 2);
	TPolynom polynom1(5);
	TPolynom polynom2(6);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_ANY_THROW(polynom2 - polynom1);
}
// ---------------------------------------------------------------------------
TEST(Polynom, can_muliply_polynoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(5, degrees2, 2);
	TPolynom polynom1(5);
	TPolynom polynom2(5);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_NO_THROW(polynom1 * polynom2);
}
// ---------------------------------------------------------------------------
TEST(Polynom, throw_when_multiply_different_polynoms)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(6, degrees2, 2);
	TPolynom polynom1(5);
	TPolynom polynom2(6);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_ANY_THROW(polynom2 * polynom1);
}
// ---------------------------------------------------------------------------
TEST(Polynom, assign_operator_works_correctly)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom1(5, degrees, 1);
	TMonom monom2(5, degrees, 4);
	TPolynom polynom1(5);
	TPolynom polynom2(5);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_NO_THROW(polynom1 = polynom2);
	TMonom* tmp = polynom1.GetStart();
	ASSERT_TRUE(*tmp == monom1);
	ASSERT_EQ(4, tmp->GetCoefficient());
}
// ---------------------------------------------------------------------------
TEST(Polynom, throw_when_assign_polynoms_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(6, degrees2, 4);
	TPolynom polynom1(5);
	TPolynom polynom2(6);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_ANY_THROW(polynom1 = polynom2);
}
// ---------------------------------------------------------------------------
TEST(Polynom, can_equeal_polynoms)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonom monom(5, degrees, 1);
	TPolynom polynom1(5);
	TPolynom polynom2(5);
	polynom1 += monom;
	polynom2 += monom;
	ASSERT_TRUE(polynom1 == polynom2);
}
// ---------------------------------------------------------------------------
TEST(Polynom, throw_when_equal_polynoms_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonom monom1(5, degrees1, 1);
	TMonom monom2(6, degrees2, 4);
	TPolynom polynom1(5);
	TPolynom polynom2(6);
	polynom1 += monom1;
	polynom2 += monom2;
	ASSERT_ANY_THROW(polynom1 == polynom2);
}



