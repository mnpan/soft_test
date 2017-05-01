#include <gtest/gtest.h>
#include "Triangle.cpp"

TEST( TriPath, C0){
	ASSERT_EQ( OUT_RANGE, Triangle( 0, 100, 100));
	ASSERT_EQ( EQUILATERAL, Triangle( 100, 100, 100));
	ASSERT_EQ( SCALENE, Triangle( 60, 80, 100));
	ASSERT_EQ( ISOSCELES, Triangle( 100, 100, 80));
	ASSERT_EQ( NON_TRIANGLE, Triangle( 60, 60, 130));
}