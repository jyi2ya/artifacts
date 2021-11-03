#include <iostream>  
#include <cstdlib>  

using namespace std;  

char name[11][15],temp[11];  
int  cost[11];  

int ID( int n, char str[] )  
{  
	for ( int j,i = 0 ; i < n ; ++ i ) {  
		for ( j = 0 ; str[j] == name[i][j] ; ++ j )  
			if ( !str[j] ) break;  
		if ( !str[j] ) return i;  
	}  
	return -1;  
}  

int main()  
{  
	int n,m,money,out,in,tests = 0;  
	while ( cin >> n ) {  
		if ( tests ++ ) cout << endl;  

		for ( int i = 0 ; i < n ; ++ i ) {  
			cin >> name[i];  
			cost[i] = 0;  
		}  

		for ( int i = 0 ; i < n ; ++ i ) {  
			cin >> temp;  
			out = ID( n, temp );  
			cin >> money >> m;  
			for ( int j = 0 ; j < m ; ++ j ) {  
				cin >> temp;  
				in = ID( n, temp );  
				cost[out] -= money/m;  
				cost[in]  += money/m;  
			}  
		}  

		for ( int i = 0 ; i < n ; ++ i )  
			cout << name[i] << " " << cost[i] << endl;  
	}  
	return 0;  
}  
