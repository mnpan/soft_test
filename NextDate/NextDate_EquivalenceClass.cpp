#include <gtest/gtest.h>

TEST( NextEquivalence, WeekNormal){
	/*** Normal Values ***/
	int y[4] = { 1995, 1900, 2004, 2000};
	int m[3] = { 2, 4, 8};
	int d[4] = { 15, 29, 30, 31};
	
	ASSERT_EQ( 19950416, NextDate( y[0], m[1], d[0]));
	ASSERT_EQ( -1, NextDate( y[1], m[0], d[1]));
	ASSERT_EQ( 20040501, NextDate( y[2], m[1], d[2]));
	ASSERT_EQ( 20000901, NextDate( y[3], m[2], d[3]));
}

TEST( NextEquivalence, StrongNormal){
	/*** Normal Values ***/
	int y[4] = { 1995, 1900, 2004, 2000};
	int m[3] = { 2, 4, 8};
	int d[4] = { 15, 29, 30, 31};
	
	for( int i = 0; i < 2; i++){
		ASSERT_EQ( (y[i]*10000 + m[0]*100 + d[0] + 1), NextDate( y[i], m[0], d[0]));
		for( int k = 1; k < 4; k++){
			ASSERT_EQ( -1, NextDate( y[i], m[0], d[k]));
		}
		
		for( int k = 0; k < 2; k++){
			ASSERT_EQ( (y[i]*10000 + m[1]*100 + d[k] + 1), NextDate( y[i], m[1], d[k]));
		}
		ASSERT_EQ( y[i]*10000+(m[1]+1)*100+1, NextDate( y[i], m[1], d[2]));
		ASSERT_EQ( -1, NextDate( y[i], m[1], d[3]));
		
		for( int k = 0; k < 3; k++){
			ASSERT_EQ( (y[i]*10000 + m[2]*100 + d[k] + 1), NextDate( y[i], m[2], d[k]));
		}
		ASSERT_EQ( y[i]*10000+(m[2]+1)*100+1, NextDate( y[i], m[2], d[3]));
		
	}
	
	for( int i = 2; i < 4; i++){
		ASSERT_EQ( (y[i]*10000 + m[0]*100 + d[0] + 1), NextDate( y[i], m[0], d[0]));
		ASSERT_EQ( y[i]*10000+(m[0]+1)*100+1, NextDate( y[i], m[0], d[1]));
		ASSERT_EQ( -1, NextDate( y[i], m[0], d[2]));
		ASSERT_EQ( -1, NextDate( y[i], m[0], d[3]));
		
		for( int k = 0; k < 2; k++){
			ASSERT_EQ( (y[i]*10000 + m[1]*100 + d[k] + 1), NextDate( y[i], m[1], d[k]));
		}
		ASSERT_EQ( y[i]*10000+(m[1]+1)*100+1, NextDate( y[i], m[1], d[2]));
		ASSERT_EQ( -1, NextDate( y[i], m[1], d[3]));
		
		for( int k = 0; k < 3; k++){
			ASSERT_EQ( (y[i]*10000 + m[2]*100 + d[k] + 1), NextDate( y[i], m[2], d[k]));
		}
		ASSERT_EQ( y[i]*10000+(m[2]+1)*100+1, NextDate( y[i], m[2], d[3]));
		
	}
}