#include<iostream>
using namespace std;

int main(){
	long long n,m,a;
	cin>>n>>m>>a;
	n=(n%a==0)?n/a:n/a+1;
	m=(m%a==0)?m/a:m/a+1;
	cout<<m*n<<endl;
	return 0;
}
