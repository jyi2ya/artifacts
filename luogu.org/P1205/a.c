#define true (1)
#define false (0)
typedef int bool;
#define inline static

/*
ID:lindong6
PROG:transform
LANG:C++
*/

#include <stdio.h>

char after[12][12],buf1[12][12],buf2[12][12],before[12][12];
int N;

void out(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) putchar(buf1[i][j]);
		putchar('\n');
	}
}

void read(){
	scanf("%d",&N);
	while(getchar()!='\n');
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) before[i][j]=getchar();
		while(getchar()!='\n');
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) after[i][j]=getchar();
		if(i!=N-1)while(getchar()!='\n');
	}
}

bool cmp(){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) {
			if(buf1[i][j]!=after[i][j])return false;
		}
	return true;
}

void turn90(char buf1[12][12],char before[12][12]){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			buf1[j][N-i-1]=before[i][j];
}
void turn180(char buf1[12][12],char before[12][12]){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			buf1[N-i-1][N-j-1]=before[i][j];
}
void turn270(char buf1[12][12],char before[12][12]){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			buf1[N-j-1][i]=before[i][j];
}
void nochg(char buf1[12][12],char before[12][12]){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			buf1[i][j]=before[i][j];
}
void mirror(char buf1[12][12],char before[12][12]){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			buf1[i][N-j-1]=before[i][j];
}
void combina(char buf1[12][12],char before[12][12],int type){
	mirror(buf2,before);
	switch(type){
		case 1:{turn90(buf1,buf2);break;}
		case 2:{turn180(buf1,buf2);break;}
		case 3:{turn270(buf1,buf2);break;}
		default:break;
	}
}

int solve(){
	turn90(buf1,before);
	if(cmp())return 1;
	turn180(buf1,before);
	if(cmp())return 2;
	turn270(buf1,before);
	if(cmp())return 3;
	mirror(buf1,before);
	if(cmp())return 4;
	combina(buf1,before,1);
	if(cmp())return 5;
	combina(buf1,before,2);
	if(cmp())return 5;
	combina(buf1,before,3);
	if(cmp())return 5;
	nochg(buf1,before);
	if(cmp())return 6;
	return 7;
}

int main(){
	read();
	printf("%d\n",solve());
	return 0;
}
