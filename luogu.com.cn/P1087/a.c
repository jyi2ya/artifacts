#include <stdio.h>

#define MAX 100000

int left[MAX],right[MAX],top=1;
char buf[MAX],tree[MAX];

char treetype(int begin,int end){
	int i;
	for(i=begin;i<=end;i++) if(buf[i]!=buf[begin])return 'F';
	if(i>end){
		if(buf[begin]=='1')return 'I';
		if(buf[begin]=='0')return 'B';
	}
	return 0;
}

int build(int begin,int end){

	int root=top;
	tree[root]=treetype(begin,end);

	top++;
#ifdef DEBUG
	printf("begin:%d,end:%d,type:%c\n",begin,end,tree[root]);
#endif
	if(end<=begin){
		left[root]=0;
		right[root]=0;
		return root;
	}

	int half=begin+(end-begin+1)/2;
	left[root]=build(begin,half-1);
	right[root]=build(half,end);

	return root;
}

void dfs(int root){
#ifdef DEBUG
	printf("root=%d\n",root);
#endif
	if(root==0)return;
	dfs(left[root]);
	dfs(right[root]);
	putchar(tree[root]);
}

int main(){
	int n;
	scanf("%d",&n);
	int max=1<<n;
	scanf("%s",buf);
	int root=build(0,max-1);
	dfs(root);
	putchar('\n');
	return 0;
}
