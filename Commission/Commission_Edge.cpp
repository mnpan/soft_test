#include <gtest/gtest.h>

TEST( ComEdge, Normal){
	int l[11] = { 1, 2, 14, 15, 16, 59, 60, 61, 69, 70, -1 };
	int s[10] = { 1, 2, 19, 20, 21, 59, 60, 61, 79, 80};
	int b[10] = { 1, 2, 24, 25, 26, 69, 70, 71, 89, 90};
	
	/*** lock == -1 --> Terminal Program ***/
	for( int j = 0; j < 10; j++){
		for( int k = 0; k < 10; k++){
			ASSERT_EQ( TERMINAL, Commission( l[10], s[j], b[k]));
		}
	}
	
	/*** T1: (1)C1+C1+C1 (2)C2/C3+C1+C1 ***/
	for( int i = 0; i <= 2; i++){
		for( int j = 0; j <= 2; j++){
			for( int k = 0; k <= 2; k++){
				ASSERT_EQ( (l[i]*45 + s[j]*30 + b[k]*25)*0.1, Commission( l[i], s[j], b[k]));
			}
			ASSERT_EQ( (l[3]*45 + s[i]*30 + b[j]*25)*0.1, Commission( l[3], s[i], b[j]));
			ASSERT_EQ( (l[4]*45 + s[i]*30 + b[j]*25)*0.1, Commission( l[4], s[i], b[j]));
			ASSERT_EQ( (l[i]*45 + s[3]*30 + b[j]*25)*0.1, Commission( l[i], s[3], b[j]));
			ASSERT_EQ( (l[i]*45 + s[4]*30 + b[j]*25)*0.1, Commission( l[i], s[4], b[j]));
			ASSERT_EQ( (l[i]*45 + s[j]*30 + b[3]*25)*0.1, Commission( l[i], s[j], b[3]));
			ASSERT_EQ( (l[i]*45 + s[j]*30 + b[4]*25)*0.1, Commission( l[i], s[j], b[4]));
		}
	}
}