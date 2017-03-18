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