#include <iostream>

#define NOT_TRIANGLE 0
#define IS_TRIANGLE 1

using namespace std;

int Triangle( int a, int b, int c){
	if( (a < b+c) && (b < a+c) && (c < a+b) ){
		cout << "Is Triangle" << endl;
		return IS_TRIANGLE;
	}
	else{
		cout << "Not Triangle" << endl;		
		return NOT_TRIANGLE;
	}
}
