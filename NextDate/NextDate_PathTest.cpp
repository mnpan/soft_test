#include <gtest/gtest.h>
#include "NextDate.cpp"

TEST( NextPath, C0){
	ASSERT_EQ( 19951201, NextDate( 1995, 11, 30));
	ASSERT_EQ( 19961201, NextDate( 1996, 11, 30));
	ASSERT_EQ( INVALID_DATE, NextDate( 1800, 11, 31));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 12, 32));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 2, 29));
	ASSERT_EQ( INVALID_DATE, NextDate( 1995, 14, 31));
}