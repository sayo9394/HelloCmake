#include "BinarySearchTree.hpp"
#include "gtest/gtest.h"

#include <stdexcept>
#include <vector>
#include <functional>

TEST(BinarySearchTree_UnitTest, testInsertAndFindMinimum) {
  BinarySearchTree<int> m_testObj;

  // test out_of_range exception is thrown
  ASSERT_THROW(m_testObj.FindMinimum(), std::out_of_range);

  m_testObj.Insert(10);
  EXPECT_EQ(m_testObj.FindMinimum(), 10);

  m_testObj.Insert(9);
  EXPECT_EQ(m_testObj.FindMinimum(), 9);

  m_testObj.Insert(8);
  EXPECT_EQ(m_testObj.FindMinimum(), 8);

  m_testObj.Insert(7);
  EXPECT_EQ(m_testObj.FindMinimum(), 7);

  m_testObj.Insert(6);
  EXPECT_EQ(m_testObj.FindMinimum(), 6);

  m_testObj.Insert(5);
  EXPECT_EQ(m_testObj.FindMinimum(), 5);
}

TEST(BinarySearchTree_UnitTest, testTraverseTree) {
  BinarySearchTree<double> m_testObj;
  m_testObj.Insert(10);
  m_testObj.Insert(8);
  m_testObj.Insert(7);
  m_testObj.Insert(5);
  m_testObj.Insert(6);
  m_testObj.Insert(9);

  std::vector<double> v;
  m_testObj.TraverseTree([&](double _item){v.push_back(_item);});

  ASSERT_EQ(v.size(), 6);
  
  ASSERT_EQ(v[0], 5);
  ASSERT_EQ(v[1], 6);
  ASSERT_EQ(v[2], 7);
  ASSERT_EQ(v[3], 8);
}