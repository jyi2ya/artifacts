#include <stdio.h>
#include <string.h>

char in[1000],post[1000];
int left[1000],right[1000],treesize=0;

int build(int l1,int r1,int l2,int r2){
	if(l1>r1)return -1;

	int root=post[r2]-'A';

	int p=l1;
	while(in[p]!=root+'A')p++;
	int cnt=p-l1;

	left[root]=build(l1,p-1,l2,l2+cnt-1);
	right[root]=build(p+1,r1,l2+cnt,r2-1);

	return root;
}

void dfs(int root){
	if(root==-1)return;
	printf("%c",root+'A');
	dfs(left[root]);
	dfs(right[root]);
}

int main(){
	scanf("%s%s",in,post);
	int root=build(0,strlen(in)-1,0,strlen(post)-1);
	dfs(root);
	putchar('\n');
	return 0;
}
