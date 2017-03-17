#include <iostream>

#define NON_TRIANGLE 0
#define SCALENE 1	//normal triangle
#define ISOSCELES 2
#define EQUILATERAL 3
#define OUT_RANGE 4

using namespace std;

int Triangle( int a, int b, int c){
	if( (a<1) || (a>200) || (b<1) || (b>200) || (c<0) || (c>200) ){
		return OUT_RANGE;
	}
 
	if( (a < b+c) && (b < a+c) && (c < a+b) ){
		if( (a==b) && (b==c) ){
			//cout << "Equilateral" << endl;
			return EQUILATERAL;
		}
		else if( (a!=b) && (b!=c) && (a!=c) ){
			//cout << "Scalene" << endl;
			return SCALENE;
		}
		else{
			//cout << "Isosceles" << endl;
			return ISOSCELES;
		}
	}
	else{
		//cout << "Not Triangle" << endl;		
		return NON_TRIANGLE;
	}
}
