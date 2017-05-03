#include <gtest/gtest.h>
//#include <iostream>
#include "NextDate.cpp"

TEST( NextPath, C0){
	ASSERT_EQ( 19951201, NextDate( 1995, 11, 30));
	ASSERT_EQ( 19961201, NextDate( 1996, 11, 30));
	ASSERT_EQ( INVALID_DATE, NextDate( 1800, 11, 31));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 12, 32));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 2, 29));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 14, 31));
}

TEST( NextPath, C1){
	ASSERT_EQ( 19951201, NextDate( 1995, 11, 30));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 11, 31));
	ASSERT_EQ( 19951116, NextDate( 1995, 11, 15));
	ASSERT_EQ( 19961201, NextDate( 1996, 11, 30));
	ASSERT_EQ( INVALID_DATE, NextDate( 1800, 11, 31));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 12, 32));
	ASSERT_EQ( 19951216, NextDate( 1995, 12, 15));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 2, 29));
	ASSERT_EQ( 19950216, NextDate( 1995, 2, 15));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 14, 31));
}

TEST( NextPath, MCDC){
	ASSERT_EQ( 19950618, NextDate( 1995, 6, 17));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 13, 17));
	ASSERT_EQ( INVALID_DATE, NextDate( 2020, 6, 17)) << "Condition1 END";
	
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 6, 31));
	ASSERT_EQ( 19950616, NextDate( 1995, 6, 15));
	ASSERT_EQ( 19950801, NextDate( 1995, 7, 31)) << "Condition2 END";
}
