//#include "Triangle/Triangle_UnitTest.cpp"
//#include "NextDate/NextDate_UnitTest.cpp"
//#include "Commission/Commission_UnitTest.cpp"
#include "Triangle/Triangle_PathTest.cpp"
//#include "NextDate/NextDate_UnitTest.cpp"
//#include "Commission/Commission_UnitTest.cpp"
#include <gtest/gtest.h>

int main( int argc, char** argv){
	testing::InitGoogleTest( &argc, argv);
	return RUN_ALL_TESTS();
}
