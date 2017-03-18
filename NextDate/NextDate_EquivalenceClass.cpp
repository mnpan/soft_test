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