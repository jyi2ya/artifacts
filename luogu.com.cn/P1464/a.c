#include <stdio.h>
#include <string.h>

int visited[30][30][30];

int w(int a,int b,int c){
	if(a<=0||b<=0||c<=0)return 1;
	if(visited[a][b][c])return visited[a][b][c];
	if(a>20||b>20||c>20)visited[20][20][20]=w(20,20,20);
	else if(a<b && b<c)visited[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else visited[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return visited[a][b][c];
}

int main(void){
	int A,B,C;
	int a,b,c;
	memset(visited,0,sizeof(visited));

	while(1){
		scanf("%d%d%d",&A,&B,&C);
#ifdef DEBUG
		printf("%d %d %d\n",A,B,C);
#endif
		a=A;b=B;c=C;
		if(A==-1&&B==-1&&C==-1)break;
		if(a<=0||b<=0||c<=0){
			printf("w(%d, %d, %d) = 1\n",A,B,C);
			continue;
		}
		if(A>20||B>20||C>20){
			a=20;b=20;c=20;
		}
#ifdef DEBUG
		printf("%d %d %d\n",a,b,c);
#endif
		
		printf("w(%d, %d, %d) = %d\n",A,B,C,w(a,b,c));
	}
	return 0;
}
