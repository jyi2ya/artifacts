#include <cstdio>
#include <algorithm>

int M[25005],B[25005];

int main(void){
	int N,X,Y;
	scanf("%d%d%d",&N,&X,&Y);
	for(int i=0;i<N;i++) scanf("%d%d",M+i,B+i);
	std::sort(M,M+N);
	std::sort(B,B+N);
	int ans=0;
	for(int i=0;i<N;i++) {
		if(M[i]<B[i]) ans+=(B[i]-M[i])*X;
		else ans+=(M[i]-B[i])*Y;
	}
	printf("%d\n",ans);
	return 0;
}
