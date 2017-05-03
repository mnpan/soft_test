#include <gtest/gtest.h>
#include "Commission.cpp"

TEST( ComPath, C0){
	ASSERT_EQ( TERMINAL, Commission( -1, 40, 45));
	ASSERT_EQ( OUT_RANGED, Commission( 71, 40, 45));
	ASSERT_EQ( OUT_RANGED, Commission( 35, 81, 45));
	ASSERT_EQ( OUT_RANGED, Commission( 35, 40, 91));
	ASSERT_EQ( 10, Commission( 1,1,1));
	ASSERT_EQ( 160.75, Commission( 30,1,1));
	ASSERT_EQ( 460, Commission( 30,30,30));
}

TEST( ComPath, MCDC){
	ASSERT_EQ( 460, Commission( 30,30,30));
	ASSERT_EQ( OUT_RANGED, Commission( 30,30,91));
	ASSERT_EQ( OUT_RANGED, Commission( 30,81,30));
	ASSERT_EQ( OUT_RANGED, Commission( 71,30,30));
}