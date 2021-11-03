#include <stdio.h>
#include <string.h>

#define MAX 23

int line[MAX][MAX],col[MAX][MAX];

int issquare(int i,int j,int len);

int main(void)
{
	int n,m,problem=0;
	while(scanf("%d%d",&n,&m)==2){
		int edgelen,tot=0,num[13];
		if(problem) puts("\n**********************************\n");
		printf("Problem #%d\n\n",++problem);
		memset(line,0,sizeof(line));
		memset(col,0,sizeof(col));
		memset(num,0,sizeof(num));

		while(m--){
			int i,j;
			char buf[3];
			scanf("%s%d%d",buf,&i,&j);
			if(buf[0]=='H') line[i][j]=1;
			if(buf[0]=='V')	col[j][i]=1;
		}
		/*
		{
			int i,j;
			for(i=1;i<=n;++i){
				for(j=1;j<=n;++j) printf("%d ",col[i][j]);
				putchar('\n');
			}
		}
		*/

		for(edgelen=1;edgelen<=n;++edgelen){
			int i,j;
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					if(issquare(i,j,edgelen)){
						++tot;
						++num[edgelen];
					}
		}
		if(!tot) puts("No completed squares can be found.");
		else {
			int i;
			for(i=0;i<n;++i){
				if(num[i]) printf("%d square (s) of size %d\n",num[i],i);
			}
		}
	}
	return 0;
}

int issquare(int i,int j,int len)
{
	int p,q;
	for(p=i;p<i+len;++p) if(!col[p][j]) return 0;
	for(p=i;p<i+len;++p) if(!col[p][j+len]) return 0;
	for(q=j;q<j+len;++q) if(!line[i][q]) return 0;
	for(q=j;q<j+len;++q) if(!line[i+len][q]) return 0;
	return 1;
}
