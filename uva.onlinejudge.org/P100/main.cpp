#include<bits/stdc++.h>
using namespace std;
int cycle(int n){
	int times=0;
	while(n!=1){
		if(n&1) n=n*3+1;
		else n>>=1;
		times++;
	}
	return times+1;
}

int main(){
	int i,j;
	while(scanf("%d%d",&i,&j)==2){
		int swap=0;
		if(i>j){swap=1;int x=i;i=j;j=x;}
		int max=0,a;
		for(a=i;a<=j;a++)
			if(cycle(a)>max)max=cycle(a);
		if(swap){int x=i;i=j;j=x;}
		printf("%d %d %d\n",i,j,max);
	}
	return 0;
}
