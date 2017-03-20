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
	for( int i = 0; i < 2; i++){
		for( int j = 0; j < 2; j++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( (l[i]*45 + s[j]*30 + b[k]*25)*0.1, Commission( l[i], s[j], b[k]));
			}
			for( int k = 2; k <= 4; k++){
				ASSERT_EQ( (l[k]*45 + s[i]*30 + b[j]*25)*0.1, Commission( l[k], s[i], b[j]));
				ASSERT_EQ( (l[i]*45 + s[k]*30 + b[j]*25)*0.1, Commission( l[i], s[k], b[j]));
				ASSERT_EQ( (l[i]*45 + s[j]*30 + b[k]*25)*0.1, Commission( l[i], s[j], b[k]));
			}
		}
	}
	
	/*** T2: (1)C2/C3+C2/C3+C1 (2)C2+C2+C2 ***/
	for( int i = 2; i <= 4; i++){
		for( int j = 2; j <= 4; j++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( 100 + ((l[i]*45 + s[j]*30 + b[k]*25)-1000)*0.15, Commission( l[i], s[j], b[k]));
				ASSERT_EQ( 100 + ((l[i]*45 + s[k]*30 + b[j]*25)-1000)*0.15, Commission( l[i], s[k], b[j]));
				ASSERT_EQ( 100 + ((l[k]*45 + s[i]*30 + b[j]*25)-1000)*0.15, Commission( l[k], s[i], b[j]));
			}
		}
	}
	ASSERT_EQ( 100 + ((l[2]*45 + s[2]*30 + b[2]*25)-1000)*0.15, Commission( l[2], s[2], b[2]));
	
	/*** T3: (1)C2/C3+C2/C3+C2/C3 - C2+C2+C2 ***/
	for( int i = 2; i <= 4; i++){
		for( int j = 2; j <= 4; j++){
			for( int k = 2; k <= 4; k++){
				if( i==2 && j==2 && k==2)	continue;
				ASSERT_EQ( 220 + ((l[i]*45 + s[j]*30 + b[k]*25)-1800)*0.2, Commission( l[i], s[j], b[k]));
			}
		}
	}
	
	/*** T3: (2)with C4 ***/
	for( int i = 0; i < 5; i++){
		for( int j = 0; j < 5; j++){
			for( int k = 0; k < 5; k++){
				ASSERT_EQ( 220 + ((l[i+5]*45 + s[j]*30 + b[k]*25)-1800)*0.2, Commission( l[i+5], s[j], b[k]));
				ASSERT_EQ( 220 + ((l[i]*45 + s[j+5]*30 + b[k]*25)-1800)*0.2, Commission( l[i], s[j+5], b[k]));
				ASSERT_EQ( 220 + ((l[i]*45 + s[j]*30 + b[k+5]*25)-1800)*0.2, Commission( l[i], s[j], b[k+5]));
				
				ASSERT_EQ( 220 + ((l[i+5]*45 + s[j+5]*30 + b[k]*25)-1800)*0.2, Commission( l[i+5], s[j+5], b[k]));
				ASSERT_EQ( 220 + ((l[i]*45 + s[j+5]*30 + b[k+5]*25)-1800)*0.2, Commission( l[i], s[j+5], b[k+5]));
				ASSERT_EQ( 220 + ((l[i+5]*45 + s[j]*30 + b[k+5]*25)-1800)*0.2, Commission( l[i+5], s[j], b[k+5]));
				
				ASSERT_EQ( 220 + ((l[i+5]*45 + s[j+5]*30 + b[k+5]*25)-1800)*0.2, Commission( l[i+5], s[j+5], b[k+5]));
			}
		}
	}
}

TEST( ComEdge, Robust){
	int NVl[11] = { 1, 2, 14, 15, 16, 59, 60, 61, 69, 70, -1 };
	int NVs[10] = { 1, 2, 19, 20, 21, 59, 60, 61, 79, 80};
	int NVb[10] = { 1, 2, 24, 25, 26, 69, 70, 71, 89, 90};
	
	int RVl[3] = { -2, 0, 71};
	int RVs[2] = { 0, 81};
	int RVb[2] = { 0, 91};
	
	/*** one robust value ***/
	for( int k = 0; k < 10; k++){
		for( int j = 0; j < 10; j++){
			for( int i = 0; i < 2; i++){
				ASSERT_EQ( OUT_RANGE, Commission( RVl[i], NVs[j], NVb[k]));
				ASSERT_EQ( OUT_RANGE, Commission( NVl[j], RVs[i], NVb[k]));
				ASSERT_EQ( OUT_RANGE, Commission( NVl[j], NVs[k], RVb[i]));
			}
			ASSERT_EQ( OUT_RANGE, Commission( RVl[2], NVs[j], NVb[k]));
		}
	}
	
	/*** two robust value ***/
	for( int k = 0; k < 10; k++){
		for( int j = 0; j < 2; j++){
			for( int i = 0; i < 2; i++){
				ASSERT_EQ( OUT_RANGE, Commission( RVl[i], RVs[j], NVb[k]));
				ASSERT_EQ( OUT_RANGE, Commission( NVl[k], RVs[i], RVb[j]));
				ASSERT_EQ( OUT_RANGE, Commission( RVl[i], NVs[k], RVb[j]));
			}
			ASSERT_EQ( OUT_RANGE, Commission( RVl[2], RVs[j], NVb[k]));
			ASSERT_EQ( OUT_RANGE, Commission( RVl[2], NVs[k], RVb[j]));
		}
	}
	
	/*** three robust value ***/
	for( int i = 0; i < 3; i++){
		for( int j = 0; j < 2; j++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( OUT_RANGE, Commission( RVl[i], RVs[j], RVb[k]));
			}
		}
	}
}