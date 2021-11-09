#include <stdio.h>

int que[2000],end=0,begin=0,size=0;
int next(int now){
	if(now==1999)return 0;
	else return now+1;
}
void push_back(int x){
#ifdef DEBUG
	printf("PUSHING..%d\n",x);
#endif
	que[end]=x;
	end=next(end);
	size++;
}
int pop_front(void){
	begin=next(begin);
	size--;
#ifdef DEBUG
	printf("POPING..%d\n",que[begin-1]);
#endif
	return que[begin-1];
}
int find(int x){
	int i;
#ifdef DEBUG
	printf("Finding... ");
	for(i=begin;i<end;i=next(i))printf("%d ",que[i]);
	putchar('\n');
#endif
	for(i=begin;i<end;i=next(i))if(que[i]==x)return 1;
#ifdef DEBUG
	printf("x=%d,not found..\n",x);
#endif
	return 0;
}
int main(){
	int m,n,num=0;
	scanf("%d%d",&m,&n);
	int i;
	while(scanf("%d",&i)==1){
		if(find(i))continue;
		else {
#ifdef DEBUG
			printf("size=%d,m=%d\n",size,m);
#endif
			if(size<m)push_back(i);
			else if(size==m){
				pop_front();
				push_back(i);
			}
			num++;
		}
	}
	printf("%d\n",num);
}
