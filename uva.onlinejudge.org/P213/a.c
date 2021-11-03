#include <stdio.h>
#include <string.h>

#define BIT 63
#define NUM 4095
#undef DEBUG

int msg[BIT][NUM];

void init(void);
void solve(void);

int main(void){
	int ch;
	while((ch=getchar())!=EOF){
		ungetc(ch,stdin);
		init();
#ifdef DEBUG
		printf("msg:\n");
		for(int i=1;i<5;++i){
			for(int j=0;j<(1<<i)-1;++j) putchar(msg[i][j]);
			putchar('\n');
		}
#endif
		solve();
		putchar('\n');
		while((ch=getchar())!='\n' && ch!=EOF);
	}
	return 0;
}

void init(void){
	memset(msg,0,sizeof(msg));
	for(int i=1;i<BIT;++i)
		for(int j=0;j<(1<<i)-1;++j){
			msg[i][j]=getchar();
			if(msg[i][j]=='\n') return;
		}
}
void solve(void){
	while('v'){
		int width=0;
		for(int i=2;i>=0;--i){
			int ch=getchar();
			if(ch!='1' && ch!='0') ++i;
			else width+=(ch-'0')<<i;
		}

		if(width==0) return;
		while('v'){
			int num=0;
			for(int i=width-1;i>=0;--i){
				int ch=getchar();
				if(ch!='1' && ch!='0') ++i;
				else num+=(ch-'0')<<i;
			}
			if(num==((1<<width)-1)) break;
#ifdef DEBUG
		printf("\nwidth=%x,num=%x\n",width,num);
#endif

			putchar(msg[width][num]);
		}
	}
}
