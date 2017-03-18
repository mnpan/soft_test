#include <gtest/gtest.h>

TEST( NextBoundary, Normal){
	/*** min, min+, nor, max-, max ***/
	int y[5] = { 1812, 1813, 1912, 2011, 2012};
	int m[5] = { 1, 2, 6, 11, 12};
	int d[5] = { 1, 2, 15, 30, 31};
	
	ASSERT_EQ( 19120602, NextDate( y[2], m[2], d[0]));
	ASSERT_EQ( 19120603, NextDate( y[2], m[2], d[1]));
	ASSERT_EQ( 19120616, NextDate( y[2], m[2], d[2]));
	ASSERT_EQ( 19120701, NextDate( y[2], m[2], d[3]));
	ASSERT_EQ( -1, NextDate( y[2], m[2], d[4]));

	ASSERT_EQ( 19120116, NextDate( y[2], m[0], d[2]));
	ASSERT_EQ( 19120216, NextDate( y[2], m[1], d[2]));
	ASSERT_EQ( 19120616, NextDate( y[2], m[2], d[2]));
	ASSERT_EQ( 19121116, NextDate( y[2], m[3], d[2]));
	ASSERT_EQ( 19121216, NextDate( y[2], m[4], d[2]));
	
	ASSERT_EQ( 18120616, NextDate( y[0], m[2], d[2]));
	ASSERT_EQ( 18130616, NextDate( y[1], m[2], d[2]));
	ASSERT_EQ( 19120616, NextDate( y[2], m[2], d[2]));
	ASSERT_EQ( 20110616, NextDate( y[3], m[2], d[2]));
	ASSERT_EQ( 20120616, NextDate( y[4], m[2], d[2]));
}