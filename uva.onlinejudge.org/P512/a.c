#include <stdio.h>
#include <string.h>

/* type */
enum operate {DR=0,DC=1,IC=2,IR=3,EX=4};
typedef enum operate operate;
typedef struct{
	operate type;
	int x[20],num;
}command;
/* end */

/* global */
int r,c,cmdnum;
command cmd[100007];
/* end */

/* function */
void read(void);

int main(void){
	int cases=0;
	while(scanf("%d%d",&r,&c)==2 && r && c){
		int n,i;
		if(cases>0) putchar('\n');
		printf("Spreadsheet #%d\n",++cases);
		read();
		scanf("%d",&n);
		for(i=0;i<n;++i) {
			int _x,_y,x,y,j,isgone=0;
			scanf("%d%d",&_x,&_y);
			x=_x;y=_y;
			for(j=0;j<cmdnum && !isgone;++j){
				switch(cmd[j].type){
					case DR:{
							int cnt=0,i;
							for(i=0;i<cmd[j].num;++i) {
								if(cmd[j].x[i]<x)
									++cnt;
								else if(x == cmd[j].x[i])
									isgone=1;
							}
							x-=cnt;
							break;
						}
					case DC:{
							int cnt=0,i;
							for(i=0;i<cmd[j].num;++i) {
								if(cmd[j].x[i]<y)
									++cnt;
								else if(cmd[j].x[i]==y)
									isgone=1;
							}
							y-=cnt;
							break;
						}
					case IC:{
							int cnt=0,i;
							for(i=0;i<cmd[j].num;++i)
								if(cmd[j].x[i]<=y)
									++cnt;
							y+=cnt;
							break;
						}
					case IR:{
							int cnt=0,i;
							for(i=0;i<cmd[j].num;++i)
								if(cmd[j].x[i]<=x)
									++cnt;
							x+=cnt;
							break;
						}
					case EX:{
							if(cmd[j].x[0]==x && cmd[j].x[1]==y){
								x=cmd[j].x[2];
								y=cmd[j].x[3];
							}else if(cmd[j].x[2]==x && cmd[j].x[3]==y){
								x=cmd[j].x[0];
								y=cmd[j].x[1];
							}
							break;
						}
					default:break;
				}
			}
			printf("Cell data in (%d,%d) ",_x,_y);
			if(isgone) puts("GONE");
			else printf("moved to (%d,%d)\n",x,y);
		}
	}
	return 0;
}

void read(void){
	int i;
	scanf("%d",&cmdnum);
	for(i=0;i<cmdnum;++i){
		char buf[3];
		scanf("%s",buf);
		if(strcmp(buf,"EX")==0) {
			scanf("%d%d%d%d",cmd[i].x,cmd[i].x+1,cmd[i].x+2,cmd[i].x+3);
			cmd[i].num=4;
			cmd[i].type=EX;
		}else{
			int j;

			if(     strcmp(buf,"IR")==0) cmd[i].type=IR;
			else if(strcmp(buf,"DR")==0) cmd[i].type=DR;
			else if(strcmp(buf,"IC")==0) cmd[i].type=IC;
			else if(strcmp(buf,"DC")==0) cmd[i].type=DC;

			scanf("%d",&cmd[i].num);
			for(j=0;j<cmd[i].num;++j) scanf("%d",cmd[i].x+j);
		}
	}
#ifdef DEBUG
	puts("DEBUG:read");
	for(i=0;i<cmdnum;++i){
		int j;
		printf("%d  ",cmd[i].num);
		for(j=0;j<cmd[i].num;++j) printf("%d ",cmd[i].x[j]);
		putchar('\n');
	}
#endif
}
/*
























                                                                          Hello, this is SysCon.

									  I come from earth, to make you happy o->.

									  I think you will be so happy when you see this text.

									  This is a tiny gift to you.

									  The big is in the darkness, and will make you more happy.

									  You will find them later.






























                                                                                  Your code is under here.







*/
