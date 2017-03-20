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