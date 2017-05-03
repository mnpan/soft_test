#define OUT_RANGED -1
#define TERMINAL 0

double Commission( int lock, int stock, int barrel){
	if( lock == -1){
		return TERMINAL;
	}
	else if( (lock < 1) || (lock > 70)){
		return OUT_RANGED;
	}
	
	if( (stock < 1) || (stock > 80)){
		return OUT_RANGED;
	}
	
	if( (barrel < 1) || (barrel > 90)){
		return OUT_RANGED;
	}
	
	double sales = double(lock*45 + stock*30 + barrel*25);
	if( sales <= 1000){
		return (sales*0.1);
	}
	else if( sales <= 1800){
		return (1000*0.1 + (sales-1000)*0.15);
	}
	else{
		return (1000*0.1 + 800*0.15 + (sales-1800)*0.2);
	}
}
