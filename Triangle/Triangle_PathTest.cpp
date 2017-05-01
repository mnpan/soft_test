#include <gtest/gtest.h>
#include "Triangle.cpp"

TEST( TriPath, C0){
	ASSERT_EQ( OUT_RANGE, Triangle( 0, 100, 100));
	ASSERT_EQ( EQUILATERAL, Triangle( 100, 100, 100));
	ASSERT_EQ( SCALENE, Triangle( 60, 80, 100));
	ASSERT_EQ( ISOSCELES, Triangle( 100, 100, 80));
	ASSERT_EQ( NON_TRIANGLE, Triangle( 60, 60, 130));
}

TEST( TriPath, MCDC){
	ASSERT_EQ( EQUILATERAL, Triangle( 100, 100, 100));
	ASSERT_EQ( OUT_RANGE, Triangle( 100, 100, 0));
	ASSERT_EQ( OUT_RANGE, Triangle( 100, 0, 100));
	ASSERT_EQ( OUT_RANGE, Triangle( 0, 100, 100));
	ASSERT_EQ( SCALENE, Triangle( 90, 120, 150));
	ASSERT_EQ( NON_TRIANGLE, Triangle( 90, 90, 190));
	ASSERT_EQ( NON_TRIANGLE, Triangle( 90, 190, 90));
	ASSERT_EQ( NON_TRIANGLE, Triangle( 190, 90, 90));
}