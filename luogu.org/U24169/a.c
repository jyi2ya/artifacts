#include <stdio.h>
#include <string.h>

int cmp(int a,int b){
	if(b+1%3==a) return 1;
	return 0;
}

int main(void){
	int n;
	scanf("%d",&n);
	int s_j=0,s_w=0,s_z=0;
	for(int i=0;i<n;i++){
		char jiang[10],wang[10],zhang[10];
		int j,w,z;
		scanf("%s%s%s",jiang,wang,zhang);
		
		if(jiang[0]=='p') j=0;
		if(jiang[1]=='c') j=1;
		if(jiang[1]=='t') j=2;
		
		if(wang[0]=='p')  w=0;
		if(wang[1]=='c')  w=1;
		if(wang[1]=='t')  w=2;
		
		if(zhang[0]=='p') z=0;
		if(zhang[1]=='c') z=1;
		if(zhang[1]=='t') z=2;
		
		if(cmp(j,w) && cmp(j,z)) s_j++;
		if(cmp(w,j) && cmp(w,z)) s_w++;
		if(cmp(z,j) && cmp(z,w)) s_z++;
	}
	if(s_j>=s_w && s_j>=s_z) printf("xiaojiang %d ",s_j);
	if(s_w>=s_j && s_w>=s_z) printf("xiaowang %d ",s_w);
	if(s_z>=s_w && s_z>=s_j) printf("xiaozhang %d ",s_z);
	return 0;
}
