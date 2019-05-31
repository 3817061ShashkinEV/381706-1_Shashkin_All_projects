#include <gtest.h>
#include "Node.h"
#include "Text.h"
#include <iostream>

TEST(Node, can_create_node_with_char)
{
  ASSERT_NO_THROW(TNode node('a'));
}
// ---------------------------------------------------------------------------
TEST(Node, can_create_node_with_string)
{
  std::string str;
  str = "Example string";
  ASSERT_NO_THROW(TNode node(str));
}
// ---------------------------------------------------------------------------
TEST(Node, can_create_node_with_level)
{
  ASSERT_NO_THROW(TNode node1(1));
  ASSERT_NO_THROW(TNode node2(2));
  ASSERT_NO_THROW(TNode node3(3));
  ASSERT_ANY_THROW(TNode node4(4));
}
// ---------------------------------------------------------------------------
TEST(Node, can_assign_node)
{
  TNode node1('a');
  TNode node2=node1;
  EXPECT_EQ(3, node2.GetLevel());
  EXPECT_EQ('a', node2.GetData());
}
// ---------------------------------------------------------------------------
TEST(Node, to_string_works_correctly)
{
  std::string str1;
  str1 = "Example string";
  TNode node(str1);
  char* tmp = node.ToStr();
  std::string str2(tmp);
  ASSERT_TRUE(str1 == str2);
}
// ---------------------------------------------------------------------------
TEST(Text, can_create_text)
{
  ASSERT_NO_THROW(TText text);
}
// ---------------------------------------------------------------------------
TEST(Text, can_create_copied_text)
{
  TText text1;
  std::string str = "Example string";
  text1.Ins(text1.GetRoot(), str);
  ASSERT_NO_THROW(TText text2(text1));
}
// ---------------------------------------------------------------------------
TEST(Text, can_cdelete)
{
  TText text;
  std::string str = "Example string";
  text.Ins(text.GetRoot(), str);
  TNode* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
  ASSERT_NO_THROW(text.Del(tmp, 2));
}
// ---------------------------------------------------------------------------
TEST(Text, can_add_nodes)
{
  TText text;
  std::string str1 = "string1";
  std::string str2 = "string2";
  std::string str3 = "string3";
  ASSERT_NO_THROW(text.Ins(text.GetRoot(), str1));
  ASSERT_NO_THROW(text.Ins(text.GetRoot(), str2));
  ASSERT_NO_THROW(text.Ins(text.GetRoot(), str3));
}
// ---------------------------------------------------------------------------
TEST(Text, can_add_string)
{
  TText text;
  std::string str = "string";
  ASSERT_NO_THROW(text.Ins(text.GetRoot(), str));
}
// ---------------------------------------------------------------------------
TEST(Text, can_add_char)
{
  TText text;
  ASSERT_NO_THROW(text.Ins(text.GetRoot(), "a"));
}
// ---------------------------------------------------------------------------
TEST(Text, can_find_index)
{
  TText text;
  std::string str = "Example string";
  text.Ins(text.GetRoot(), str);
  int tmp = text.FindIndex("Example");
  ASSERT_TRUE(tmp==0);
}
// ---------------------------------------------------------------------------
TEST(Text, can_find)
{
  TText text;
  std::string str = "Example string";
  text.Ins(text.GetRoot(), str);
  TNode* tmp = text.Find("Example");
  ASSERT_TRUE(tmp->GetData()=='E');
  tmp=tmp->GetNeighbour();
  ASSERT_TRUE(tmp->GetData() == 'x');
}
