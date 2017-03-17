#include "Triangle.cpp"
#include <gtest/gtest.h>

TEST( TriBoundary, Normal){
	int min = 1;
	int min_p = min + 1;
	int nor = 100;
	int max = 200;
	int max_s = max - 1;

	ASSERT_EQ( ISOSCELES, Triangle( nor, nor, min));
	ASSERT_EQ( ISOSCELES, Triangle( nor, nor, min_p));
	ASSERT_EQ( EQUILATERAL, Triangle( nor, nor, nor));
	ASSERT_EQ( ISOSCELES, Triangle( nor, nor, max_s));
	ASSERT_EQ( NON_TRIANGLE, Triangle( nor, nor, max));

	ASSERT_EQ( ISOSCELES, Triangle( nor, min, nor));
	ASSERT_EQ( ISOSCELES, Triangle( nor, min_p, nor));
	ASSERT_EQ( EQUILATERAL, Triangle( nor, nor, nor));
	ASSERT_EQ( ISOSCELES, Triangle( nor, max_s, nor));
	ASSERT_EQ( NON_TRIANGLE, Triangle( nor, max, nor));

	ASSERT_EQ( ISOSCELES, Triangle( min, nor, nor));
	ASSERT_EQ( ISOSCELES, Triangle( min_p, nor, nor));
	ASSERT_EQ( EQUILATERAL, Triangle( nor, nor, nor));
	ASSERT_EQ( ISOSCELES, Triangle( max_s, nor, nor));
	ASSERT_EQ( NON_TRIANGLE, Triangle( max, nor, nor));
}
