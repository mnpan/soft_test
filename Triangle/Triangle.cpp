#include <iostream>

#define NON_TRIANGLE 0
#define SCALENE 1	//normal triangle
#define ISOSCELES 2
#define EQUILATERAL 3

using namespace std;

int Triangle( int a, int b, int c){
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
