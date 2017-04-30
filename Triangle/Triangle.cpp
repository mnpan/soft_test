#include <iostream>

#define NON_TRIANGLE 0
#define SCALENE 1	//normal triangle
#define ISOSCELES 2
#define EQUILATERAL 3
#define OUT_RANGE 4

using namespace std;

int Triangle( int a, int b, int c){
	int result = 0;
	if( (a<1) || (a>200) || (b<1) || (b>200) || (c<1) || (c>200) ){
		result = OUT_RANGE;
	}
 	else if( (a < b+c) && (b < a+c) && (c < a+b) ){
		if( (a==b) && (b==c) ){
			result = EQUILATERAL;
		}
		else if( (a!=b) && (b!=c) && (a!=c) ){
			result = SCALENE;
		}
		else{
			result = ISOSCELES;
		}
	}
	else{
		result = NON_TRIANGLE;
	}
	return result;
}
