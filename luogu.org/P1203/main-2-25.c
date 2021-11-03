#include <stdio.h>

char a[360];
int best,best_num,lenth;

int right(int search){
	int num=1,first=search+1;
	if(search==lenth)search=0;
	char ch=a[search];
	if(ch=='w'){
		while(1){
			search++;
			if(search==lenth)search=0;
			if(a[search]=='w')num++;
			if(search==lenth)search=0;
			if(search==first)break;
			else break;
		}
		ch=a[search];
		num++;
	}
	while(1){
#ifdef DEBUG
		printf("%d %d\n",search,first);
#endif
		if(search==first)break;
		if(search==lenth)search=0;
		search++;
		if(a[search]==ch||a[search]=='w')num++;
		else break;
	}
#ifdef DEBUG
	printf("     -----right:%d\n",num);
#endif
	return num;
}
int left(int search){
	int num=1,first=--search;
	if(search==-1)search=lenth-1;
	char ch=a[search];
	if(ch=='w'){
		while(1){
			search--;
			if(search==first)break;
			if(search==-1)search=lenth-1;
			if(a[search]=='w')num++;
			else break;
		}
		ch=a[search];
		num++;
	}
	while(1){
		search--;
		if(search==first)break;
		if(search==-1)search=lenth-1;
		if(a[search]==ch||a[search]=='w')num++;
		else break;
	}
#ifdef DEBUG
	printf("     -----left:%d\n",num);
#endif
	return num;
}

int main(void){
	scanf("%d\n",&lenth);
	fgets(a,355,stdin);
	int search=0;
	best=-1;best_num=0;
	while(a[search]!='\0'){
		int num=left(search)+right(search);
#ifdef DEBUG
		printf("               -----search=%d,tot=%d\n",search,num);
#endif
		if(num>best_num){
			best_num=num;best=search;
		}
		search++;
	}
	if(best_num>lenth)best_num=lenth;
	printf("%d\n",best_num);
	return 0;
}
