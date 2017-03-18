#include "Triangle.cpp"
#include <gtest/gtest.h>

TEST( TriDecisionTable, Normal){
	ASSERT_EQ( NON_TRIANGLE, Triangle( 100, 40, 40));
	ASSERT_EQ( NON_TRIANGLE, Triangle( 40, 100, 40));
	ASSERT_EQ( NON_TRIANGLE, Triangle( 40, 40, 100));
	
	ASSERT_EQ( EQUILATERAL, Triangle( 100, 100, 100));
	
	ASSERT_EQ( ISOSCELES, Triangle( 100, 100, 80));
	ASSERT_EQ( ISOSCELES, Triangle( 100, 80, 100));
	ASSERT_EQ( ISOSCELES, Triangle( 80, 100, 100));
	
	ASSERT_EQ( SCALENE, Triangle( 80, 100, 120));
}
