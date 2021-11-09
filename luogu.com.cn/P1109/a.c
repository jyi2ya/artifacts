#include <stdio.h>

int grp[55];

int main(void){
	int N,L,R;
	scanf("%d",&N);
	int tot=0;
	for(int i=0;i<N;i++){
		scanf("%d",grp+i);
		tot+=grp[i];
	}
	scanf("%d%d",&L,&R);
	if((float)tot/N > R || (float)tot/N < L) puts("-1");
	else{
		int lt=0,gt=0;
		for(int i=0;i<N;i++){
			if(grp[i] > R) gt+=grp[i]-R;
			if(grp[i] < L) lt+=L-grp[i];
		}
		printf("%d\n",gt>lt?gt:lt);
	}
	return 0;
}
