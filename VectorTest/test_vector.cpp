#include <gtest.h>
#include <Vector.h>

TEST(Vector, can_create_vector_with_positive_size)
{
  ASSERT_NO_THROW(TVector<int> V);
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_create_vector_with_negative_size)
{
  ASSERT_ANY_THROW(TVector<int> V(-10));
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> V(10,-5));
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_create_vector_with_startindex_large_than_size)
{
  ASSERT_ANY_THROW(TVector<int> V(10, 11));
}
// ---------------------------------------------------------------------------
TEST(Vector, can_create_copied_vector)
{
  TVector<int> V(10);
  ASSERT_NO_THROW(TVector<int> B(V));
}
// ---------------------------------------------------------------------------
TEST(Vector, can_get_size)
{
  TVector<int> V(10);
  EXPECT_EQ(10, V.GetSize());
}
// ---------------------------------------------------------------------------
TEST(Vector, can_get_startindex)
{
  TVector<int> V(10,5);
  EXPECT_EQ(5, V.GetStartIndex());
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_return_element_of_vector_with_negative_index)
{
  TVector<int> V(10);
  ASSERT_ANY_THROW(V[-1]);
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_return_element_of_vector_with_index_equal_size)
{
  TVector<int> V(10);
  ASSERT_ANY_THROW(V[10]);
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_return_element_of_vector_with_index_large_than_size)
{
  TVector<int> V(10);
  ASSERT_ANY_THROW(V[11]);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_write_and_return_element_via_index_operator)
{
  TVector<int> V(3);
  V[0] = 0;
  int tmp = V[0] + 2;
  EXPECT_EQ(2, tmp);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_compare_vectors)
{
  TVector<int> V1(10),V2(10);
  for (int i = 0; i < V1.GetSize(); i++)
  {
    V1[i] = i;
    V2[i] = i;
  }
  ASSERT_TRUE(V1 == V2);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_compare_vectors_with_one_size_false)
{
  TVector<int> V1(10), V2(10);
  for (int i = 0; i < V1.GetSize(); i++)
  {
    V1[i] = i;
    V2[i] = i+2;
  }
  ASSERT_FALSE(V1 == V2);
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_compare_vectors_with_different_size)
{
  TVector<int> V1(10), V2(11);
  ASSERT_ANY_THROW(V1 == V2);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_assign_vector)
{
  TVector<int> V1(10), V2(11);
  V1 = V2;
  ASSERT_TRUE(V1 == V2);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_add_scalar_to_vector)
{
  TVector<int> V(10);
  V=V+5;
  EXPECT_EQ(5, V[6]);
  EXPECT_EQ(5, V[8]);
  EXPECT_NE(9, V[0]);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_subtract_scalar_from_vector)
{
  TVector<int> V(10);
  V = V - 5;
  EXPECT_EQ(-5, V[6]);
  EXPECT_EQ(-5, V[8]);
  EXPECT_NE(0, V[0]);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_multiply_vector_on_scalar)
{
  TVector<int> V(10);
  for (int i = 0; i < V.GetSize(); i++)
    V[i] = i;
  V = V * 2;
  EXPECT_EQ(12, V[6]);
  EXPECT_EQ(16, V[8]);
  EXPECT_NE(1, V[0]);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_add_two_vector_with_equal_size)
{
  TVector<int> V1(3), V2(3), tmp(3);
  for (int i = 0; i < V1.GetSize(); i++)
  {
    V1[i] = i;
    V2[i] = V2.GetSize() - i;
  }
  tmp = V1 + V2;
  ASSERT_TRUE(tmp == (V1+V2));
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_add_two_vectors_with_defferent_size)
{
  TVector<int> V1(3), V2(4);
  ASSERT_ANY_THROW(V1 + V2);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_substract_two_vector_with_equal_size)
{
  TVector<int> V1(3), V2(3), tmp(3);
  for (int i = 0; i < V1.GetSize(); i++)
  {
    V1[i] = i;
    V2[i] = V2.GetSize() - i;
  }
  tmp = V2 - V1;
  ASSERT_TRUE(tmp == (V2-V1));
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_substract_two_vectors_with_defferent_size)
{
  TVector<int> V1(3), V2(4);
  ASSERT_ANY_THROW(V1 - V2);
}
// ---------------------------------------------------------------------------
TEST(Vector, can_multiply_two_vector_with_equal_size)
{
  TVector<int> V1(3), V2(3);
  int tmp;
  for (int i = 0; i < V1.GetSize(); i++)
  {
    V1[i] = i;
    V2[i] = V2.GetSize() - i;
  }
  tmp = V2 * V1;
  EXPECT_EQ(4, tmp);
}
// ---------------------------------------------------------------------------
TEST(Vector, throw_when_multiply_two_vectors_with_defferent_size)
{
  TVector<int> V1(3), V2(4);
  ASSERT_ANY_THROW(V1 * V2);
}
