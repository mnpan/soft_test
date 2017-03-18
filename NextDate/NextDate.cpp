#include <iostream>
#define SMALL 0
#define LARGE 1
#define FEB 2

#define INVALID_DATE -1
using namespace std;

int NextDate( int year, int month, int day){
	bool is_leap = false;
	int m_type;
	
	if( (year < 1812) || (year > 2012)){
		return INVALID_DATE;
	}
	else if( (year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0)){
		is_leap = true; 
	}
	else{
		is_leap = false;
	}
	
	if( month < 1 ){
		return INVALID_DATE;
	}
	else if( month == 2){
		if( ( is_leap && (day > 29)) || ( !is_leap && (day > 28))){
			return INVALID_DATE;
		}
		m_type = FEB;
	}
	else if( (month <= 7 && month%2 == 0) || (month >= 8 && month%2 == 1)){
		if( day > 30)	return INVALID_DATE;
		m_type = SMALL;
	}
	else{
		if( day > 31)	return INVALID_DATE;
		m_type = LARGE;
	}
	
	day += 1;
	switch( m_type){
		case SMALL:
			if(day == 31){
				day = 1;
				month += 1;
			}
			break;
		case LARGE:
			if(day == 32){
				day = 1;
				month += 1;
			}
			break;
		case FEB:
			if( (is_leap && (day == 30)) || (!is_leap && (day == 29))){
				day = 1;
				month += 1;
			}
			break;
	}
	
	if( month == 13 ){
		month = 1;
		year += 1;
	}
	
	return year*10000 + month*100 + day;
}

/*int main(void){
	int y, m, d;
	while(1){
		cin >> y >> m >> d;
		cout << NextDate(y, m, d) << endl;
	}
}*/