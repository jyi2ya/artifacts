#include <stdio.h>

int c[26][26],b[26];

int main(){
	freopen("tttt.in","r",stdin);
	freopen("tttt.out","w",stdout);

	char a[3][4];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++) a[i][j]=getchar();
		while(getchar()!='\n');
	}
	int ans=0,only=0;

	for(int i=0;i<3;i++){
		if(a[0][i]==a[1][i] && a[1][i]==a[2][i]) {
			if(!b[a[1][i]-'A']){
				b[a[1][i]-'A']=1;
				only++;
			}
		} else {
			if(a[0][i]==a[1][i]){
				int p=a[0][i]-'A',q=a[2][i]-'A';
				if(p>q){int x=p;p=q;q=x;}
				if(!c[p][q])ans++;
				c[p][q]=1;
			}
			if(a[1][i]==a[2][i]){
				int p=a[1][i]-'A',q=a[0][i]-'A';
				if(p>q){int x=p;p=q;q=x;}
				if(!c[p][q])ans++;
				c[p][q]=1;
			}
			if(a[0][i]==a[2][i]){
				int p=a[0][i]-'A',q=a[1][i]-'A';
				if(p>q){int x=p;p=q;q=x;}
				if(!c[p][q])ans++;
				c[p][q]=1;
			}
		}
	}
	for(int i=0;i<3;i++){
		if(a[i][0]==a[i][1] && a[i][1]==a[i][2]) {
			if(!b[a[i][1]-'A']){
				b[a[i][1]-'A']=1;
				only++;
			}
		} else {
			if(a[i][0]==a[i][1]){
				int p=a[i][0]-'A',q=a[i][2]-'A';
				if(p>q){int x=p;p=q;q=x;}
				if(!c[p][q])ans++;
				c[p][q]=1;
			}
			if(a[i][1]==a[i][2]){
				int p=a[i][1]-'A',q=a[i][0]-'A';
				if(p>q){int x=p;p=q;q=x;}
				if(!c[p][q])ans++;
				c[p][q]=1;
			}
			if(a[i][2]==a[i][0]){
				int p=a[i][0]-'A',q=a[i][1]-'A';
				if(p>q){int x=p;p=q;q=x;}
				if(!c[p][q])ans++;
				c[p][q]=1;
			}
		}
	}
	if(a[0][0]==a[1][1] && a[1][1]==a[2][2]) {
		if(!b[a[1][1]-'A']){
			b[a[1][1]-'A']=1;
			only++;
		}
	} else {
		if(a[0][0]==a[1][1]){
			int p=a[0][0]-'A',q=a[2][2]-'A';
			if(p>q){int x=p;p=q;q=x;}
			if(!c[p][q])ans++;
			c[p][q]=1;
		}
		if(a[1][1]==a[2][2]){
			int p=a[1][1]-'A',q=a[0][0]-'A';
			if(p>q){int x=p;p=q;q=x;}
			if(!c[p][q])ans++;
			c[p][q]=1;
		}
		if(a[2][2]==a[0][0]){
			int p=a[0][0]-'A',q=a[1][1]-'A';
			if(p>q){int x=p;p=q;q=x;}
			if(!c[p][q])ans++;
			c[p][q]=1;
		}
	}
	if(a[2][0]==a[1][1] && a[1][1]==a[2][0]) {
		if(!b[a[1][1]-'A']){
			b[a[1][1]-'A']=1;
			only++;
		}
	} else {
		if(a[2][0]==a[1][1]){
			int p=a[2][0]-'A',q=a[0][2]-'A';
			if(p>q){int x=p;p=q;q=x;}
			if(!c[p][q])ans++;
			c[p][q]=1;
		}
		if(a[1][1]==a[0][2]){
			int p=a[1][1]-'A',q=a[2][0]-'A';
			if(p>q){int x=p;p=q;q=x;}
			if(!c[p][q])ans++;
			c[p][q]=1;
		}
		if(a[0][2]==a[2][0]){
			int p=a[2][0]-'A',q=a[1][1]-'A';
			if(p>q){int x=p;p=q;q=x;}
			if(!c[p][q])ans++;
			c[p][q]=1;
		}
	}

	printf("%d\n%d\n",only,ans);
	return 0;
}
