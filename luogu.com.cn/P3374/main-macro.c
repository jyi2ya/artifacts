#include <stdio.h>

#define MAX 500009

int c[MAX],n,m;

void update(int x,int deltax);
int prefix(int r);

#define query(EXP_QUERY_l,EXP_QUERY_r) ({\
	int MACRO_QUERY_l=EXP_QUERY_l,MACRO_QUERY_r=EXP_QUERY_r;\
	(prefix((MACRO_QUERY_r))-prefix((MACRO_QUERY_l)-1));\
})
#define lowbit(x) ((x)&(~(x)+1))
#define prefix(EXP_PREFIX_r) ({\
	int MACRO_PREFIX_ans=0,MACRO_PREFIX_r=EXP_PREFIX_r;\
	while((MACRO_PREFIX_r)){\
		MACRO_PREFIX_ans+=c[(MACRO_PREFIX_r)];\
		(MACRO_PREFIX_r)-=lowbit((MACRO_PREFIX_r));\
	}\
	MACRO_PREFIX_ans;\
})
#define update(EXP_UPDATE_x,EXP_UPDATE_deltax) do{\
	int MACRO_UPDATE_x=EXP_UPDATE_x,MACRO_UPDATE_deltax=EXP_UPDATE_deltax;\
	while((MACRO_UPDATE_x)<=n){\
		c[(MACRO_UPDATE_x)]+=(MACRO_UPDATE_deltax);\
		(MACRO_UPDATE_x)+=lowbit((MACRO_UPDATE_x));\
	}\
}while(0)
#define read() do{\
	int i;\
	scanf("%d%d",&n,&m);\
	for(i=1;i<=n;++i){\
		int x;\
		scanf("%d",&x);\
		update(i,x);\
	}\
}while(0)


int main(void)
{
	int i;
	read();
	for(i=0;i<m;++i){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			update(x,y);
		}else {
			printf("%d\n",query(x,y));
		}
	}
	return 0;
}
