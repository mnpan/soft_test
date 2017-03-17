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

TEST( TriBoundary, WorsrCase){
	int min = 1;
	int min_p = min + 1;
	int nor = 100;
	int max = 200;
	int max_s = max - 1;
	int value[5] = { min, min_p, nor, max_s, max};


	ASSERT_EQ( EQUILATERAL, Triangle( min, min, min));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min, min_p));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min, nor));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min, max_s));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min, max));

	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min_p, min));
	ASSERT_EQ( ISOSCELES, Triangle( min, min_p, min_p));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min_p, nor));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min_p, max_s));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, min_p, max));
	
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, nor, min));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, nor, min_p));
	ASSERT_EQ( ISOSCELES, Triangle( min, nor, nor));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, nor, max_s));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, nor, max));
	
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max_s, min));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max_s, min_p));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max_s, nor));
	ASSERT_EQ( ISOSCELES, Triangle( min, max_s, max_s));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max_s, max));
	
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max, min));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max, min_p));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max, nor));
	ASSERT_EQ( NON_TRIANGLE, Triangle( min, max, max_s));
	ASSERT_EQ( ISOSCELES, Triangle( min, max, max));

}

TEST( TriBoundary, Robust){
	int min = 1;
	int min_p = min + 1;
	int nor = 100;
	int max = 200;
	int max_s = max - 1;
	
	int min_s = min - 1;
	int max_p = max + 1;
	
	int value[7] = { min_s, min, min_p, nor, max_s, max, max_p};

	for( int i = 0; i < 7; i++){
		for( int j = 0; j < 7; j++){
			ASSERT_EQ( OUT_RANGE, Triangle( value[i], value[j], value[0]));
			ASSERT_EQ( OUT_RANGE, Triangle( value[i], value[j], value[6]));
		}
	}

}
