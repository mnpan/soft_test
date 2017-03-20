

double Commission( int lock, int stock, int barrel){
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