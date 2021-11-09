#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprim(int a){
	if(a<=1)return 0;
	if(a==2)return 1;
	int i,max=(int)sqrt((double)a)+1;
	for(i=2;i<=max && i<a;i++)if(a%i==0)return 0;
	return 1;
}

int main(void){
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=2;i<n;i++){
		if(isprim(i)){
			for(j=2;j<n;j++){
				if(isprim(j)){
					k=n-i-j;
					if(isprim(k)){
						printf("%d %d %d\n",i,j,k);
						exit(0);
					}
				}
			}
		}
	}
	return 0;
}

