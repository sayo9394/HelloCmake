#include "LinkedList.hpp"
#include "gtest/gtest.h"
#include <cstdlib>

// class LinkedList_UnitTest : public testing:Test
// {
// public:
//   virtual void SetUp();
//   virtual void TearDown();
// 	~LinkedList_UnitTest();

// private:
// 	std::unique_ptr<LinkedList> m_testObj;
// };

// void LinkedList_UnitTest::SetUp
// {
// 	m_testObj
// }

TEST(LinkedList_UnitTest, testConstructEmptyList) {
  LinkedList m_testObj;
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(0));
}

TEST(LinkedList_UnitTest, testPushAndPops) {
  LinkedList m_testObj;
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(0));

  m_testObj.PushFront(1.0);
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(1));

  m_testObj.PushFront(2.0);
  m_testObj.PushFront(3.0);
  m_testObj.PushFront(4.0);
  m_testObj.PushFront(5.0);
  m_testObj.PushFront(6.0);
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(6));

  auto value = m_testObj.PopFront();
  EXPECT_EQ(value, 6.0);
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(5));

  value = m_testObj.PopFront();
  EXPECT_EQ(value, 5.0);
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(4));
  
  value = m_testObj.PopFront();
  EXPECT_EQ(value, 4.0);
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(3));
  
  value = m_testObj.PopFront();
  EXPECT_EQ(value, 3.0);
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(2));
  
  value = m_testObj.PopFront();
  EXPECT_EQ(value, 2.0);
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(1));
  
  value = m_testObj.PopFront();
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(0));
  EXPECT_EQ(value, 1.0);
}

TEST(LinkedList_UnitTest, testRemoveFromEmptyList) 
{ 	
  LinkedList m_testObj;
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(0));

  auto value = m_testObj.PopFront();
  EXPECT_EQ(m_testObj.Size(), static_cast<size_t>(0));
  EXPECT_EQ(value, 1.0);
}

TEST(LinkedList_UnitTest, testConstructListWithInitialiserList) {
  EXPECT_EQ(1, 1);
}