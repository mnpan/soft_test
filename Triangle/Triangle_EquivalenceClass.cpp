#include "Triangle.cpp"
#include <gtest/gtest.h>

TEST( TriEquivalence, WeekNormal){
	int NVa[3] = {33, 88, 178};
	int NVb[3] = {50, 88, 166};
	int NVc[2] = {63, 150};
	

	ASSERT_EQ( SCALENE, Triangle( NVa[0], NVb[1], NVc[0]));
	ASSERT_EQ( SCALENE, Triangle( NVa[1], NVb[2], NVc[1]));
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[2], NVb[0], NVc[0]));
}

TEST( TriEquivalence, StrongNormal){
	int NVa[3] = {33, 88, 178};
	int NVb[3] = {50, 88, 166};
	int NVc[2] = {63, 150};
	

	ASSERT_EQ( SCALENE, Triangle( NVa[0], NVb[0], NVc[0]));
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[0], NVb[0], NVc[1]));
	ASSERT_EQ( SCALENE, Triangle( NVa[0], NVb[1], NVc[0]));
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[0], NVb[1], NVc[1]));
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[0], NVb[2], NVc[0]));
	ASSERT_EQ( SCALENE, Triangle( NVa[0], NVb[2], NVc[1]));
	
	ASSERT_EQ( SCALENE, Triangle( NVa[1], NVb[0], NVc[0]));
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[1], NVb[0], NVc[1]));
	ASSERT_EQ( ISOSCELES, Triangle( NVa[1], NVb[1], NVc[0]));
	ASSERT_EQ( ISOSCELES, Triangle( NVa[1], NVb[1], NVc[1]));
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[1], NVb[2], NVc[0]));
	ASSERT_EQ( SCALENE, Triangle( NVa[1], NVb[2], NVc[1]));
	
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[2], NVb[0], NVc[0]));
	ASSERT_EQ( SCALENE, Triangle( NVa[2], NVb[0], NVc[1]));
	ASSERT_EQ( NON_TRIANGLE, Triangle( NVa[2], NVb[1], NVc[0]));
	ASSERT_EQ( SCALENE, Triangle( NVa[2], NVb[1], NVc[1]));
	ASSERT_EQ( SCALENE, Triangle( NVa[2], NVb[2], NVc[0]));
	ASSERT_EQ( SCALENE, Triangle( NVa[2], NVb[2], NVc[1]));
}

TEST( TriEquivalence, WeekRobust){
	int NVa[3] = {33, 88, 178};
	int NVb[3] = {50, 88, 166};
	int NVc[2] = {63, 150};
	
	int RVa[2] = { -2, 250};
	int RVb[2] = { 0, 222};
	int RVc[2] = { -125, 350};

	ASSERT_EQ( OUT_RANGE, Triangle( RVa[0], NVb[1], NVc[1]));
	ASSERT_EQ( OUT_RANGE, Triangle( RVa[1], NVb[2], NVc[0]));
	
	ASSERT_EQ( OUT_RANGE, Triangle( NVa[2], RVb[0], NVc[0]));
	ASSERT_EQ( OUT_RANGE, Triangle( NVa[1], RVb[1], NVc[1]));
	
	ASSERT_EQ( OUT_RANGE, Triangle( NVa[0], NVb[0], RVc[0]));
	ASSERT_EQ( OUT_RANGE, Triangle( NVa[1], NVb[1], RVc[1]));
}

TEST( TriEquivalence, StrongRobust){
	int NVa[3] = {33, 88, 178};
	int NVb[3] = {50, 88, 166};
	int NVc[2] = {63, 150};
	
	int RVa[2] = { -2, 250};
	int RVb[2] = { 0, 222};
	int RVc[2] = { -125, 350};
	
	for( int i = 0; i < 2; i++){
		for( int j = 0; j< 3; j++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], NVb[j], NVc[k]));
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], NVb[j], RVc[k]));
			}
		}
		for( int j = 0; j< 2; j++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], RVb[j], NVc[k]));
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], RVb[j], RVc[k]));
			}
		}
	}
	
	for( int j = 0; j< 2; j++){
		for( int i = 0; i < 3; i++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( OUT_RANGE, Triangle( NVa[i], RVb[j], NVc[k]));
				ASSERT_EQ( OUT_RANGE, Triangle( NVa[i], RVb[j], RVc[k]));
			}
		}
		for( int i = 0; i< 2; i++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], RVb[j], NVc[k]));
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], RVb[j], RVc[k]));
			}
		}
	}
		
	for( int k = 0; k< 2; k++){
		for( int i = 0; i < 3; i++){
			for( int j = 0; j< 3; j++){
				ASSERT_EQ( OUT_RANGE, Triangle( NVa[i], NVb[j], RVc[k]));
			}
			for( int j = 0; j< 2; j++){
				ASSERT_EQ( OUT_RANGE, Triangle( NVa[i], RVb[j], RVc[k]));
			}
		}
		for( int i = 0; i< 2; i++){
			for( int j = 0; j< 3; j++){
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], NVb[j], RVc[k]));
			}
			for( int j = 0; j< 2; j++){
				ASSERT_EQ( OUT_RANGE, Triangle( RVa[i], RVb[j], RVc[k]));
			}
		}
	}
	
	
}
