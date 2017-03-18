#include "Triangle.cpp"
#include <gtest/gtest.h>

TEST( TriEdge, Normal){
	int data[10] = { 1, 2, 66, 67, 68, 133, 134, 135, 199, 200};
	
	for( int i = 0; i < 10; i++){
		for( int j = i; j < 10; j++){
			for ( int k = j; k < 10; k++){
				if( i==j && j==k){
					ASSERT_EQ( EQUILATERAL, Triangle( data[i], data[j], data[k]));
				}
				else if( (data[i] + data[j]) <= data[k]){
					ASSERT_EQ( NON_TRIANGLE, Triangle( data[i], data[j], data[k]));
				}
				else if( i==j || j==k){
					ASSERT_EQ( ISOSCELES, Triangle( data[i], data[j], data[k]));
				}
				else{
					ASSERT_EQ( SCALENE, Triangle( data[i], data[j], data[k]));
				}
			}
		}
	}
}

TEST( TriEdge, Robust){
	int data[12] = { 0, 1, 2, 66, 67, 68, 133, 134, 135, 199, 200, 201};
	
	for( int j = 0; j < 12 ; j++){
		for( int k = 0; k<12; k++){
			ASSERT_EQ( OUT_RANGE, Triangle( data[0], data[j], data[k]));
			ASSERT_EQ( OUT_RANGE, Triangle( data[11], data[j], data[k]));
		}
	}

	for( int i = 0; i < 12 ; i++){
		for( int k = 0; k<12; k++){
			ASSERT_EQ( OUT_RANGE, Triangle( data[i], data[0], data[k]));
			ASSERT_EQ( OUT_RANGE, Triangle( data[i], data[11], data[k]));
		}
	}	

	for( int i = 0; i < 12 ; i++){
		for( int j = 0; j<12; j++){
			ASSERT_EQ( OUT_RANGE, Triangle( data[i], data[j], data[0]));
			ASSERT_EQ( OUT_RANGE, Triangle( data[i], data[j], data[11]));
		}
	}		
}