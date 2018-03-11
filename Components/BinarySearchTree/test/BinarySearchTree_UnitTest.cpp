#include "BinarySearchTree.hpp"
#include "gtest/gtest.h"
#include <stdexcept>
#include <vector>
#include <functional>

TEST(BinarySearchTree_UnitTest, testInsertAndFindMinimum) {
  BinarySearchTree m_testObj;

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
  BinarySearchTree m_testObj;
  std::vector<double> v;
  m_testObj.Insert(10);
  m_testObj.Insert(8);
  m_testObj.Insert(7);
  m_testObj.Insert(5);
  m_testObj.Insert(6);
  m_testObj.Insert(9);

  auto funk = [&v](double _item) { 
                  v.push_back(_item); 
                };

  m_testObj.TraverseTree(funk);
}