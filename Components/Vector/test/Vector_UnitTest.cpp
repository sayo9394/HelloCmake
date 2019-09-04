#include "Vector.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;

TEST(Vector_UnitTest, TestVectorConstructor)
{
    Vector<double> v;
	v.push_back(1.0);
	v.push_back(2.0);

	ASSERT_EQ(v.size(), 2);
	ASSERT_EQ(v.at(0), 1.0);
	ASSERT_EQ(v[0], 1.0);
}