#include <stdio.h>

int n,k;

int stack[1023],top=0;

int dfs(int num,int grp,int last);

int main(void)
{
	scanf("%d%d",&n,&k);
	printf("%d\n",dfs(n,k,1));
	return 0;
}

int dfs(int num,int grp,int last)
{
	if(grp==1){
		if(num<last) return 0;
		return 1;
	}
	else{
		int ans=0,i;
		for(i=last;i<num;++i) ans+=dfs(num-i,grp-1,i);
		return ans;
	}
}
