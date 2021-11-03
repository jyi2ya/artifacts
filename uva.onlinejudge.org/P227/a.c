#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

#define LEFT  0
#define RIGHT 1
#define UP    2
#define DOWN  3

char a[5][5];
int sx,sy;

void out(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			putchar(a[i][j]);
			if(j<4)putchar(' ');
		}
		putchar('\n');
	}
}

bool move(int direct){
	switch(direct){
		case LEFT:{
				  if(sx-1<0) return false;
				  a[sy][sx]=a[sy][sx-1];
				  a[sy][--sx]=' ';
				  break;
			  }
		case RIGHT:{
				   if(sx+1>4) return false;
				   a[sy][sx]=a[sy][sx+1];
				   a[sy][++sx]=' ';
				   break;
			   }
		case UP:{
				if(sy-1<0) return false;
				a[sy][sx]=a[sy-1][sx];
				a[--sy][sx]=' ';
				break;
			}
		case DOWN:{
				  if(sy+1>4) return false;
				  a[sy][sx]=a[sy+1][sx];
				  a[++sy][sx]=' ';
				  break;
			  }
		default:{break;}
	}
	return true;
}

bool read(){
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++){
			a[i][j]=getchar();
			if(a[i][j]==' ') { sx=j;sy=i;}
			if(a[i][j]==EOF)return false;
		}
		getchar();
	}
	return true;
}

int main(){
	int puzzles=1;
	bool first=true;
	while(read()){
		int command,ch;
		bool NoCfg=false;
		while((ch=getchar())!='0'){
			switch(ch){
				case 'A':{command=UP   ;break;}
				case 'B':{command=DOWN ;break;}
				case 'L':{command=LEFT ;break;}
				case 'R':{command=RIGHT;break;}
				default :{command=-1    ;break;}
			}
			if(!move(command)) NoCfg=true; 
		}
		if(first) first=false;else putchar('\n');
		printf("Puzzle #%d:\n",puzzles);
		if(NoCfg) printf("This puzzle has no final configuration.\n");
		else out();
		while(getchar()!='\n');
		puzzles++;
	}
	return 0;
}

