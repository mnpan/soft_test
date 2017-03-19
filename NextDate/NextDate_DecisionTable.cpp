#include <gtest/gtest.h>

TEST( NextDecisionTable, Normal){
	int y[2] = { 1995, 2004};
	int m[4] = { 6, 8, 12, 2};
	int d[5] = { 15, 28, 29, 30, 31};
	
	for( int i = 0; i < 2; i++){
		//case1-5
		ASSERT_EQ( (y[i]*10000 + m[0]*100 + d[0] + 1), NextDate( y[i], m[0], d[0]));
		ASSERT_EQ( (y[i]*10000 + m[0]*100 + d[1] + 1), NextDate( y[i], m[0], d[1]));
		ASSERT_EQ( (y[i]*10000 + m[0]*100 + d[2] + 1), NextDate( y[i], m[0], d[2]));
		ASSERT_EQ( y[i]*10000+(m[0]+1)*100+1, NextDate( y[i], m[0], d[3]));
		ASSERT_EQ( -1, NextDate( y[i], m[0], d[4]));
		
		//case 6-9, 11-14
		for( int j = 1; j <= 2; j++){
			for( int k = 0; k <= 3; k++){
				ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
		
			}
		}
		//case 10, 15
		ASSERT_EQ( y[i]*10000+(m[1]+1)*100+1, NextDate( y[i], m[1], d[4]));
		ASSERT_EQ( (y[i]+1)*10000+100+1, NextDate( y[i], m[2], d[4]));
		
		//case 16
		ASSERT_EQ( (y[i]*10000 + m[3]*100 + d[0] + 1), NextDate( y[i], m[3], d[0]));
		//case 21, 22
		ASSERT_EQ( -1, NextDate( y[i], m[3], d[3]));
		ASSERT_EQ( -1, NextDate( y[i], m[3], d[4]));
	}
	
	//case 17-20
	ASSERT_EQ( y[0]*10000+(m[3]+1)*100+1, NextDate( y[0], m[3], d[1]));
	ASSERT_EQ( (y[1]*10000 + m[3]*100 + d[1] + 1), NextDate( y[1], m[3], d[1]));
	ASSERT_EQ( -1, NextDate( y[0], m[3], d[2]));
	ASSERT_EQ( y[1]*10000+(m[3]+1)*100+1, NextDate( y[1], m[3], d[2]));
	
}