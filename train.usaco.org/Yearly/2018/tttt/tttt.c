#include <stdio.h>

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
		if(a[0][i]==a[1][i] && a[0][i]==a[2][i] && a[1][i]==a[2][i])only++;
		else if(a[0][i]==a[1][i] || a[0][i]==a[2][i] || a[1][i]==a[2][i])ans++;
	}

	for(int i=0;i<3;i++){
		if(a[i][0]==a[i][1] && a[i][0]==a[i][2] && a[i][1]==a[i][2])only++;
		else if(a[i][0]==a[i][1] || a[i][0]==a[i][2] || a[i][1]==a[i][2])ans++;
	}

	if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]==a[2][2])only++;
	else if(a[0][0]==a[1][1] || a[1][1]==a[2][2] || a[0][0]==a[2][2])ans++;

	if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]==a[2][0])only++;
	else if(a[0][2]==a[1][1] || a[1][1]==a[2][0] || a[0][2]==a[2][0])ans++;
	printf("%d\n%d\n",only,ans);
	return 0;
}
