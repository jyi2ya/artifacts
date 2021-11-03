#include<iostream>
using namespace std;

int gcd(int a,int b){
	if(b==0)return 0;
	while(a%b!=0){int x=b;b=a%b;a=x;}
	return b;
}

int abs(int a){return a>0?a:-a;}

int main(){
	int ax,ay,bx,by,n;
	cin>>n;
	while(n--){
		cin>>ax>>ay>>bx>>by;
		if(gcd(abs(ax-bx),abs(ay-by))==1) cout<<"no\n";
		else cout<<"yes\n";
	}
	return 0;
}
