#include <stdio.h>

int n,m,c[500009];

int main(void)
{
	int i;
	do{ int i;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			do{ 
				int MACRO_UPDATE_x=i,MACRO_UPDATE_deltax=x;
				while((MACRO_UPDATE_x)<=n){
					c[(MACRO_UPDATE_x)]+=(MACRO_UPDATE_deltax);
					(MACRO_UPDATE_x)+=(((MACRO_UPDATE_x))&(~((MACRO_UPDATE_x))+1));
				}
			}while(0);
		}
	}while(0);
	for(i=0;i<m;++i){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			do{
				int MACRO_UPDATE_x=x,MACRO_UPDATE_deltax=y;
				while((MACRO_UPDATE_x)<=n){
					c[(MACRO_UPDATE_x)]+=(MACRO_UPDATE_deltax);
					(MACRO_UPDATE_x)+=(((MACRO_UPDATE_x))&(~((MACRO_UPDATE_x))+1));
				}
			}while(0);
		}else {
			printf("%d\n",
					({ 
					 int MACRO_QUERY_l=x,MACRO_QUERY_r=y;
					 (({ 
					   int MACRO_PREFIX_ans=0,MACRO_PREFIX_r=(MACRO_QUERY_r);
					   while((MACRO_PREFIX_r)){
					   MACRO_PREFIX_ans+=c[(MACRO_PREFIX_r)];
					   (MACRO_PREFIX_r)-=(((MACRO_PREFIX_r))&(~((MACRO_PREFIX_r))+1));
					   } 
					   MACRO_PREFIX_ans;
					   }) - ({
						   int MACRO_PREFIX_ans=0,MACRO_PREFIX_r=(MACRO_QUERY_l)-1;
						   while((MACRO_PREFIX_r)){
						   MACRO_PREFIX_ans+=c[(MACRO_PREFIX_r)];
						   (MACRO_PREFIX_r)-=(((MACRO_PREFIX_r))&(~((MACRO_PREFIX_r))+1));
						   } 
						   MACRO_PREFIX_ans;
						   }));
					 })
			      );
		}
	}
	return 0;
}
