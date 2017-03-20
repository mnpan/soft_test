#include <gtest/gtest.h>

TEST( ComEquivalence, WeakNormal){
	int NVl[3] = { -1, 15, 60};
	int NVs[2] = { 20, 60};
	int NVb[2] = { 25, 70};
	
	ASSERT_EQ( TERMINAL, Commission( NVl[0], NVs[0], NVb[1]));
	ASSERT_EQ( 480, Commission( NVl[1], NVs[1], NVb[0]));	//sales = 3100
	ASSERT_EQ( 870, Commission( NVl[2], NVs[0], NVb[1]));	//sales = 5050
	
}