#include <gtest/gtest.h>

TEST( NextEdge, Normal){
	int y[16] = { 1812, 1813, 1899, 1900, 1901, 1994, 1995, 1996, 1999, 2000, 2001, 2003, 2004, 2005, 2011, 2012};
	int m[10] = { 1, 2, 3, 4, 5, 7, 8, 9, 11, 12};
	int d[9] = { 1, 2, 14, 15, 16, 28, 29, 30, 31};
	
	for( int i = 0; i < 16; i++){
		for( int j = 0; j < 10; j++){
			for( int k = 0; k < 9; k++){
				switch( m[j]){
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
						switch( d[k]){
							case 31:
								ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
								break;
							default:
								ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
						}
						break;
					case 12:
						switch( d[k]){
							case 31:
								ASSERT_EQ( (y[i]+1)*10000+100+1, NextDate( y[i], m[j], d[k]));
								break;
							default:
								ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
						}
						break;
					case 4:
					case 9:
					case 11:
						switch( d[k]){
							case 30:
								ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
								break;
							case 31:
								ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
								break;
							default:
								ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
						}
						break;
					case 2:
						switch( y[i]){
							case 1812:
							case 1996:
							case 2000:
							case 2004:
							case 2012:
								switch( d[k]){
									case 29:
										ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
										break;
									case 30:
									case 31:
										ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
										break;
									default:
										ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
								}
								break;
							default:
								switch( d[k]){
									case 28:
										ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
										break;
									case 29:
									case 30:
									case 31:
										ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
										break;
									default:
										ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
								}
						}
						break;
					default:
						ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
				}
			}
		}
	}
}

TEST( NextEdge, Robust){
	int y[18] = { 1811, 1812, 1813, 1899, 1900, 1901, 1994, 1995, 1996, 1999, 2000, 2001, 2003, 2004, 2005, 2011, 2012, 2013};
	int m[12] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 11, 12, 13};
	int d[11] = { 0, 1, 2, 14, 15, 16, 28, 29, 30, 31, 32};
	
	for( int i = 0; i < 16; i++){
		for( int j = 0; j < 10; j++){
			for( int k = 0; k < 9; k++){
				if( y[i] == 1811 || y[i] == 2013){
					ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
				}
				else{
					switch( m[j]){
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
							switch( d[k]){
								case 0:
								case 32:
									ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
									break;
								case 31:
									ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
									break;
								default:
									ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
							}
							break;
						case 12:
							switch( d[k]){
								case 0:
								case 32:
									ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
									break;
								case 31:
									ASSERT_EQ( (y[i]+1)*10000+100+1, NextDate( y[i], m[j], d[k]));
									break;
								default:
									ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
							}
							break;
						case 4:
						case 9:
						case 11:
							switch( d[k]){
								case 30:
									ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
									break;
								case 0:
								case 32:
								case 31:
									ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
									break;
								default:
									ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
							}
							break;
						case 2:
							switch( y[i]){
								case 1811:
								case 2013:
									ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
									break;
								case 1812:
								case 1996:
								case 2000:
								case 2004:
								case 2012:
									switch( d[k]){
										case 29:
											ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
											break;
										case 0:
										case 32:
										case 30:
										case 31:
											ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
											break;
										default:
											ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
									}
									break;
								default:
									switch( d[k]){
										case 28:
											ASSERT_EQ( y[i]*10000+(m[j]+1)*100+1, NextDate( y[i], m[j], d[k]));
											break;
										case 0:
										case 32:
										case 29:
										case 30:
										case 31:
											ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
											break;
										default:
											ASSERT_EQ( (y[i]*10000 + m[j]*100 + d[k] + 1), NextDate( y[i], m[j], d[k]));
									}
							}
							break;
						default:
							ASSERT_EQ( -1, NextDate( y[i], m[j], d[k]));
					}
				}
			}
		}
	}
}