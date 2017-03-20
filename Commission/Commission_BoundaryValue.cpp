#include <gtest/gtest.h>

TEST( ComBoundary, Normal){
	/*** min, min+, nor, max-, max ***/
	int l[5] = { 1, 2, 35, 69, 70};
	int s[5] = { 1, 2, 40, 79, 80};
	int b[5] = { 1, 2, 45, 89, 90};
	
	ASSERT_EQ( 420, Commission( l[2], s[2], b[0]));	//sales = 2800
	ASSERT_EQ( 425, Commission( l[2], s[2], b[1]));	//sales = 2825
	ASSERT_EQ( 640, Commission( l[2], s[2], b[2]));	//sales = 3900
	ASSERT_EQ( 860, Commission( l[2], s[2], b[3]));	//sales = 5000
	ASSERT_EQ( 865, Commission( l[2], s[2], b[4]));	//sales = 5025
	
	ASSERT_EQ( 406, Commission( l[2], s[0], b[2]));	//sales = 2730
	ASSERT_EQ( 412, Commission( l[2], s[1], b[2]));	//sales = 2760
	ASSERT_EQ( 640, Commission( l[2], s[2], b[2]));	//sales = 3900
	ASSERT_EQ( 874, Commission( l[2], s[3], b[2]));	//sales = 5070
	ASSERT_EQ( 880, Commission( l[2], s[4], b[2]));	//sales = 5100
	
	ASSERT_EQ( 334, Commission( l[0], s[2], b[2]));	//sales = 2370
	ASSERT_EQ( 343, Commission( l[1], s[2], b[2]));	//sales = 2415
	ASSERT_EQ( 640, Commission( l[2], s[2], b[2]));	//sales = 3900
	ASSERT_EQ( 946, Commission( l[3], s[2], b[2]));	//sales = 5430
	ASSERT_EQ( 955, Commission( l[4], s[2], b[2]));	//sales = 5475
}

TEST( ComBoundary, WorseCase){
	/*** min, min+, nor, max-, max ***/
	int l[5] = { 1, 2, 35, 69, 70};
	int s[5] = { 1, 2, 40, 79, 80};
	int b[5] = { 1, 2, 45, 89, 90};
	
	/*** T1: 1 <= sales <= 1000 : min/min+ + min/min+ + min/min+ ***/
	for( int i = 0; i < 2; i++){
		for( int j = 0; j < 2; j++){
			for( int k = 0; k < 2; k++){
				ASSERT_EQ( (l[i]*45 + s[j]*30 + b[k]*25)*0.1, Commission( l[i], s[j], b[k]));
			}
		}
	}
	
	/*** T2: 1000 < sales <= 1800 :nor+ + min/min+ + min/min+ ***/
	for( int j = 0; j < 2; j++){
		for( int k = 0; k < 2; k++){
			ASSERT_EQ( 100 + ((l[2]*45 + s[j]*30 + b[k]*25)-1000)*0.15, Commission( l[2], s[j], b[k]));
			ASSERT_EQ( 100 + ((l[j]*45 + s[2]*30 + b[k]*25)-1000)*0.15, Commission( l[j], s[2], b[k]));
			ASSERT_EQ( 100 + ((l[j]*45 + s[k]*30 + b[2]*25)-1000)*0.15, Commission( l[j], s[k], b[2]));
		}
	}
	
	/*** T3: sales > 1800: (1)max/max- + any (2)nor + nor + any ***/
	for( int j = 0; j < 3; j++){
		for( int k = 0; k < 3; k++){
			ASSERT_EQ( 220 + ((l[3]*45 + s[j]*30 + b[k]*25)-1800)*0.2, Commission( l[3], s[j], b[k]));
			ASSERT_EQ( 220 + ((l[4]*45 + s[j]*30 + b[k]*25)-1800)*0.2, Commission( l[4], s[j], b[k]));
			ASSERT_EQ( 220 + ((l[j]*45 + s[3]*30 + b[k]*25)-1800)*0.2, Commission( l[j], s[3], b[k]));
			ASSERT_EQ( 220 + ((l[j]*45 + s[4]*30 + b[k]*25)-1800)*0.2, Commission( l[j], s[4], b[k]));
			ASSERT_EQ( 220 + ((l[j]*45 + s[k]*30 + b[3]*25)-1800)*0.2, Commission( l[j], s[k], b[3]));
			ASSERT_EQ( 220 + ((l[j]*45 + s[k]*30 + b[4]*25)-1800)*0.2, Commission( l[j], s[k], b[4]));
		}
		ASSERT_EQ( 220 + ((l[3]*45 + s[3]*30 + b[j]*25)-1800)*0.2, Commission( l[3], s[3], b[j]));
		ASSERT_EQ( 220 + ((l[3]*45 + s[4]*30 + b[j]*25)-1800)*0.2, Commission( l[3], s[4], b[j]));
		ASSERT_EQ( 220 + ((l[4]*45 + s[3]*30 + b[j]*25)-1800)*0.2, Commission( l[4], s[3], b[j]));
		ASSERT_EQ( 220 + ((l[4]*45 + s[4]*30 + b[j]*25)-1800)*0.2, Commission( l[4], s[4], b[j]));
		ASSERT_EQ( 220 + ((l[3]*45 + s[j]*30 + b[3]*25)-1800)*0.2, Commission( l[3], s[j], b[3]));
		ASSERT_EQ( 220 + ((l[3]*45 + s[j]*30 + b[4]*25)-1800)*0.2, Commission( l[3], s[j], b[4]));
		ASSERT_EQ( 220 + ((l[4]*45 + s[j]*30 + b[3]*25)-1800)*0.2, Commission( l[4], s[j], b[3]));
		ASSERT_EQ( 220 + ((l[4]*45 + s[j]*30 + b[4]*25)-1800)*0.2, Commission( l[4], s[j], b[4]));
		ASSERT_EQ( 220 + ((l[j]*45 + s[3]*30 + b[3]*25)-1800)*0.2, Commission( l[j], s[3], b[3]));
		ASSERT_EQ( 220 + ((l[j]*45 + s[3]*30 + b[4]*25)-1800)*0.2, Commission( l[j], s[3], b[4]));
		ASSERT_EQ( 220 + ((l[j]*45 + s[4]*30 + b[3]*25)-1800)*0.2, Commission( l[j], s[4], b[3]));
		ASSERT_EQ( 220 + ((l[j]*45 + s[4]*30 + b[4]*25)-1800)*0.2, Commission( l[j], s[4], b[4]));
	}
	ASSERT_EQ( 220 + ((l[3]*45 + s[3]*30 + b[3]*25)-1800)*0.2, Commission( l[3], s[3], b[3]));
	ASSERT_EQ( 220 + ((l[3]*45 + s[3]*30 + b[4]*25)-1800)*0.2, Commission( l[3], s[3], b[4]));
	ASSERT_EQ( 220 + ((l[3]*45 + s[4]*30 + b[3]*25)-1800)*0.2, Commission( l[3], s[4], b[3]));
	ASSERT_EQ( 220 + ((l[3]*45 + s[4]*30 + b[4]*25)-1800)*0.2, Commission( l[3], s[4], b[4]));
	ASSERT_EQ( 220 + ((l[4]*45 + s[3]*30 + b[3]*25)-1800)*0.2, Commission( l[4], s[3], b[3]));
	ASSERT_EQ( 220 + ((l[4]*45 + s[3]*30 + b[4]*25)-1800)*0.2, Commission( l[4], s[3], b[4]));
	ASSERT_EQ( 220 + ((l[4]*45 + s[4]*30 + b[3]*25)-1800)*0.2, Commission( l[4], s[4], b[3]));
	ASSERT_EQ( 220 + ((l[4]*45 + s[4]*30 + b[4]*25)-1800)*0.2, Commission( l[4], s[4], b[4]));
	
	for( int j = 0; j < 2; j++){
		ASSERT_EQ( 220 + ((l[2]*45 + s[2]*30 + b[j]*25)-1800)*0.2, Commission( l[2], s[2], b[j]));
		ASSERT_EQ( 220 + ((l[2]*45 + s[j]*30 + b[2]*25)-1800)*0.2, Commission( l[2], s[j], b[2]));
		ASSERT_EQ( 220 + ((l[j]*45 + s[2]*30 + b[2]*25)-1800)*0.2, Commission( l[j], s[2], b[2]));
	}
	ASSERT_EQ( 220 + ((l[2]*45 + s[2]*30 + b[2]*25)-1800)*0.2, Commission( l[2], s[2], b[2]));
	
}