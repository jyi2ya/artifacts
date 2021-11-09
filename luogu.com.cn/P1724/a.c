#include <stdio.h>
#include <ctype.h>

char cmd[5005];
int len=0,T;

void read(void){
	int ch;
	while(isspace(ch=getchar()));
	cmd[len++]=ch;
	while(isgraph(ch=getchar())) cmd[len++]=ch;
	cmd[len]='\0';
	scanf("%d",&T);
#ifdef DEBUG
	puts(cmd);
	printf("%d\n",T);
#endif
}

int main(void){
	read();
	int N=0,E=0,S=0,W=0;
	for(int i=0;i<len;i++)
	       	switch(cmd[i]){
			case 'N':{N++;break;}
			case 'E':{E++;break;}
			case 'S':{S++;break;}
			case 'W':{W++;break;}
			default:break;
		}
	int dy=N-S,dx=E-W;
	int x=T/len*dx,y=T/len*dy;
#ifdef DEBUG
	printf("dx=%d,dy=%d\nx=%d,y=%d\nlen=%d\n",dx,dy,x,y,len);
#endif
	for(int i=0;i<T%len;i++) 
		switch(cmd[i]){
			case 'N':{y++;break;}
			case 'E':{x++;break;}
			case 'W':{x--;break;}
			case 'S':{y--;break;}
			default:break;
		}
	printf("%d %d\n",x,y);
	return 0;
}
