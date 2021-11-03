#include <stdio.h>

int a[105],b[105],atop=0,btop=0;

void read(void){
	int ch;
	atop=0;btop=0;
	while((ch=getchar())!='\n' && ch!=EOF) a[atop++]=ch-'0';
	while((ch=getchar())!='\n' && ch!=EOF) b[btop++]=ch-'0';
}
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int min(int a,int b){
	if(a<b) return a;
	return b;
}

int main(void){
	int ch;
	while((ch=getchar())!=EOF){
		ungetc(ch,stdin);
		read();
		int ans=atop+btop;
		for(int i=-btop;i<atop;i++){
			int left=min(0,i),right=max(i+btop,atop);
			int ok=1;
			for(int j=left;j<right;j++){
				if(j<i) continue;
				if(j>atop) continue;
				if(b[j-i]+a[j] > 3){
					ok=0;
					break;
				}
			}
			if(ok && right-left<ans) ans=right-left;
		}
		printf("%d\n",ans);
	}
	return 0;
}
