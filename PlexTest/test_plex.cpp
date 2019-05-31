#include <gtest.h>
#include "Plex.h"

TEST(Point, can_create_point)
{
  ASSERT_NO_THROW(TPoint point);
}
// ---------------------------------------------------------------------------
TEST(Point, can_create_point_with_coordinates)
{
  ASSERT_NO_THROW(TPoint point(1,2));
}
// ---------------------------------------------------------------------------
TEST(Point, can_create_copied_point)
{
  TPoint point1(1, 2);
  ASSERT_NO_THROW(TPoint point2(point1));
}
// ---------------------------------------------------------------------------
TEST(Point, can_get_x_and_y)
{
  TPoint point(1, 2);
  EXPECT_EQ(1, point.GetX());
  EXPECT_EQ(2, point.GetY());
}
// ---------------------------------------------------------------------------
TEST(Point, can_set_x_and_y)
{
  TPoint point;
  ASSERT_NO_THROW(point.SetX(5));
  ASSERT_NO_THROW(point.SetY(10));
  EXPECT_EQ(5, point.GetX());
  EXPECT_EQ(10, point.GetY());
}
// ---------------------------------------------------------------------------
TEST(Point, can_compare_correctly)
{
  TPoint point1(1,2);
  TPoint point2(1, 2);
  TPoint point3(1, 3);
  TPoint point4(5, 6);
  ASSERT_TRUE(point1 == point2);
  ASSERT_FALSE(point1 == point3);
  ASSERT_FALSE(point3 == point4);
}
// ---------------------------------------------------------------------------
TEST(Line, can_create_line)
{
  ASSERT_NO_THROW(TLine line);
}
// ---------------------------------------------------------------------------
TEST(Line, can_create_line_with_points)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  ASSERT_NO_THROW(TLine line(A,B));
}
// ---------------------------------------------------------------------------
TEST(Line, can_create_line_with_coordinates)
{
  ASSERT_NO_THROW(TLine line(1,2,3,4));
}
// ---------------------------------------------------------------------------
TEST(Line, can_create_copied_line)
{
  TLine line1(1,2,3,4);
  ASSERT_NO_THROW(TLine line2(line1));
}
// ---------------------------------------------------------------------------
TEST(Line, can_get_A_and_B_points)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  TLine line(A,B);
  ASSERT_TRUE(A == line.GetA());
  ASSERT_TRUE(B == line.GetB());
}
// ---------------------------------------------------------------------------
TEST(Line, can_set_A_and_B_points)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  TLine line;
  line.SetA(A);
  line.SetB(B);
  ASSERT_TRUE(A == line.GetA());
  ASSERT_TRUE(B == line.GetB());
}
// ---------------------------------------------------------------------------
TEST(Plex, can_create_plex)
{
  ASSERT_NO_THROW(TPlex plex);
}
// ---------------------------------------------------------------------------
TEST(Plex, can_create_plex_with_points)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  ASSERT_NO_THROW(TPlex plex(&A,&B));
}
// ---------------------------------------------------------------------------
TEST(Plex, can_get_right_and_left)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  TPlex plex(&A, &B);
  ASSERT_TRUE(&A == plex.GetLeft());
  ASSERT_TRUE(&B == plex.GetRight());
}
// ---------------------------------------------------------------------------
TEST(Plex, can_set_right_and_left)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  TPlex plex;
  plex.SetLeft(&A);
  plex.SetRight(&B);
  ASSERT_TRUE(&A == plex.GetLeft());
  ASSERT_TRUE(&B == plex.GetRight());
}
// ---------------------------------------------------------------------------
TEST(Plex, can_add_line)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  TPoint C(5, 6);
  TPoint D(3, 4);
  TPlex plex(&C,&D);
  ASSERT_NO_THROW(plex.Add(&A, &B));
}
// ---------------------------------------------------------------------------
TEST(Plex, throw_when_try_to_add_incorrect_line)
{
  TPoint A(1, 2);
  TPoint B(3, 4);
  TPoint C(5, 6);
  TPoint D(7, 8);
  TPlex plex(&C, &D);
  ASSERT_ANY_THROW(plex.Add(&A, &B));
}
// ---------------------------------------------------------------------------


