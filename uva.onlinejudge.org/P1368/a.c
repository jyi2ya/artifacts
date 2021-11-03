#include <stdio.h>
#include <string.h>

char a[51][1005];
int num[26];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,n,tot=0;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;++i) scanf("%s",a[i]);
		for(int i=0;i<n;++i){
			memset(num,0,sizeof(num));
			for(int j=0;j<m;++j) ++num[a[j][i]-'A'];
			int max=0,maxnum;
			for(int j=0;j<26;++j) 
				if(num[j]>max){
					maxnum=j;max=num[j];
				}
			putchar(maxnum+'A');tot+=(m-max);
		}
		putchar('\n');
		printf("%d\n",tot);
	}
	return 0;
}
