#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>
#include <string.h>

int secret[1005],guess[1005],timeinguess[10],timeinsecret[10];
bool readguess(int N){
	int i,flag=1;
	for(i=0;i<N;i++){
		scanf("%d",guess+i);
		if(guess[i]!=0)flag=0;
	}
	if(flag)return false;
	else return true;
}

bool search(int* a,int b,int N){
	for(int i=0;i<N;i++) if(a[i]==b)return true;
	return false;
}

int min(int a,int b){
	return a>b?b:a;
}

int main(){
	int Games=1,N;
	while(scanf("%d",&N)==1){
		if(N==0)break;
		printf("Game %d:\n",Games);

		for(int i=0;i<N;i++)scanf("%d",secret+i);

		while(readguess(N)){
			memset(timeinguess,0,sizeof(timeinguess));
			memset(timeinsecret,0,sizeof(timeinsecret));
			int A=0,B=0;

			for(int i=0;i<N;i++) if(secret[i]==guess[i])A++;

			for(int i=0;i<N;i++) timeinguess[guess[i]]++;
			for(int i=0;i<N;i++) timeinsecret[secret[i]]++;
			for(int i=0;i<10;i++) B+=min(timeinguess[i],timeinsecret[i]);

			printf("    (%d,%d)\n",A,B-A);
		}
		Games++;
	}
	return 0;
}
