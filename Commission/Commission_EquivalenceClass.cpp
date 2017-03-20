#include <gtest/gtest.h>

TEST( ComEquivalence, WeakNormal){
	int NVl[3] = { -1, 15, 60};
	int NVs[2] = { 20, 60};
	int NVb[2] = { 25, 70};
	
	ASSERT_EQ( TERMINAL, Commission( NVl[0], NVs[0], NVb[1]));
	ASSERT_EQ( 480, Commission( NVl[1], NVs[1], NVb[0]));	//sales = 3100
	ASSERT_EQ( 870, Commission( NVl[2], NVs[0], NVb[1]));	//sales = 5050
	
}

TEST( ComEquivalence, StrongNormal){
	int NVl[3] = { 15, 60, -1};
	int NVs[2] = { 20, 60};
	int NVb[2] = { 25, 70};
	
	for( int i = 0; i<2; i++){
		for( int j = 0; j < 2; j++){
			ASSERT_EQ( TERMINAL, Commission( NVl[2], NVs[i], NVb[j]));
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( 220 + ((NVl[i]*45 + NVs[j]*30 + NVb[k]*25)-1800)*0.2, Commission( NVl[i], NVs[j], NVb[k]));
			}
		}
	}
	
}

TEST( ComEquivalence, WeakRobust){
	int NVl[3] = { 15, 60, -1};
	int NVs[2] = { 20, 60};
	int NVb[2] = { 25, 70};
	
	int RVl[3] = { -2, 0, 71};
	int RVs[2] = { 0, 81};
	int RVb[2] = { 0, 91};
	
	ASSERT_EQ( OUT_RANGE, Commission( RVl[0], NVs[0], NVb[1]));
	ASSERT_EQ( TERMINAL, Commission( NVl[2], RVs[0], RVb[1]));
	ASSERT_EQ( OUT_RANGE, Commission( RVl[1], NVs[1], NVb[0]));
	ASSERT_EQ( OUT_RANGE, Commission( NVl[0], RVs[1], RVb[0]));
	ASSERT_EQ( 870, Commission( NVl[1], NVs[0], NVb[1]));	//sales = 5550
	ASSERT_EQ( OUT_RANGE, Commission( RVl[2], NVs[1], NVb[0]));
	
}

TEST( ComEquivalence, StrongRobust){
	int NVl[3] = { 15, 60, -1};
	int NVs[2] = { 20, 60};
	int NVb[2] = { 25, 70};
	
	int RVl[3] = { -2, 0, 71};
	int RVs[2] = { 0, 81};
	int RVb[2] = { 0, 91};
	
	/*** -1 terminal program ***/
	for( int j = 0; j < 2; j++){
		for( int k = 0; k < 2; k++){
			ASSERT_EQ( TERMINAL, Commission( NVl[2], NVs[j], NVb[k]));
			ASSERT_EQ( TERMINAL, Commission( NVl[2], RVs[j], NVb[k]));
			ASSERT_EQ( TERMINAL, Commission( NVl[2], NVs[j], RVb[k]));
			ASSERT_EQ( TERMINAL, Commission( NVl[2], RVs[j], RVb[k]));
		}
	}
	
	/*** one robust value ***/
	for( int j = 0; j < 2; j++){
		for( int k = 0; k < 2; k++){
			ASSERT_EQ( OUT_RANGE, Commission( RVl[0], NVs[j], NVb[k]));
			ASSERT_EQ( OUT_RANGE, Commission( RVl[1], NVs[j], NVb[k]));
			ASSERT_EQ( OUT_RANGE, Commission( RVl[2], NVs[j], NVb[k]));
			
			for( int i = 0; i < 2; i++){
				ASSERT_EQ( OUT_RANGE, Commission( NVl[j], RVs[i], NVb[k]));
				ASSERT_EQ( OUT_RANGE, Commission( NVl[j], NVs[i], RVb[0]));
			}
		}
	}
	
	/*** two robust value ***/
	for( int j = 0; j < 2; j++){
		for( int k = 0; k < 2; k++){
			for( int i = 0; i < 3; i++){
				ASSERT_EQ( OUT_RANGE, Commission( RVl[i], RVs[j], NVb[k]));
				ASSERT_EQ( OUT_RANGE, Commission( RVl[i], NVs[j], RVb[k]));
			}
			for( int i = 0; i < 2; i++){
				ASSERT_EQ( OUT_RANGE, Commission( NVl[i], RVs[j], RVb[k]));
				ASSERT_EQ( OUT_RANGE, Commission( NVl[i], RVs[k], RVb[k]));
			}
		}
	}
	
	/*** three robust value ***/
	for( int j = 0; j < 2; j++){
		for( int k = 0; k < 2; k++){
			for( int i = 0; i < 3; i++){
				ASSERT_EQ( OUT_RANGE, Commission( RVl[i], RVs[j], RVb[k]));
			}
		}
	}
}