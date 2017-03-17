#include "Triangle.cpp"
#include <gtest/gtest.h>

TEST( TriBoundary, Normal){
	int min = 1;
	int min_p = min + 1;
	int nor = 100;
	int max = 200;
	int max_s = max - 1;

	ASSERT_EQ( IS_TRIANGLE, Triangle( nor, nor, min));
	ASSERT_EQ( IS_TRIANGLE, Triangle( nor, nor, min_p));
	ASSERT_EQ( IS_TRIANGLE, Triangle( nor, nor, nor));
	ASSERT_EQ( IS_TRIANGLE, Triangle( nor, nor, max_s));
	ASSERT_EQ( NON_TRIANGLE, Triangle( nor, nor, max));
}
