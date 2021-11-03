#define true (1)
#define false (0)
typedef int bool;
#define inline static

#include <stdio.h>

#define QUE_MAX 1000
#define MAX 105

typedef struct {
	int id,x,y;
}node;

char a[MAX][MAX],buf[MAX];

node cross[QUE_MAX],down[QUE_MAX];
int crstop=1,crsbot=0,dontop=1,donbot=0,buftop=0,r,c;

bool read(){
	scanf("%d",&r);if(r==0) return false; 
	scanf("%d",&c);
	while(getchar()!='\n');
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++) a[i][j]=getchar();
		while(getchar()!='\n');
	}
	for(int i=0;i<=r;i++) a[i][c]='*';
	for(int i=0;i<c;i++) a[r][i]='*';
	return true;
}

void init(){
	crstop=1;crsbot=0;dontop=1;donbot=0;
}

void scan(){
	int id=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j]=='*')continue;
			bool added=false;
			if(i==0 || a[i-1][j]=='*'){
				down[dontop].y=i;
				down[dontop].x=j;
				down[dontop].id=id;
				dontop++;added=true;
			}
			if(j==0 ||  a[i][j-1]=='*'){
				cross[crstop].y=i;
				cross[crstop].x=j;
				cross[crstop].id=id;
				crstop++;added=true;
			}
			if(added)id++;
		}
	}
}

int main(){
	int puz=1;bool first=true;
	while(read()){
		if(first)first=false;else putchar('\n');
		init();
		scan();

		printf("puzzle #%d:\n",puz++);

		printf("Across\n");
#ifdef DEBUG
		printf("crstop=%d,crsbot=%d\n",crstop,crsbot);
#endif
		while(crstop-crsbot-1){
			crsbot++;buftop=0;
			int j=cross[crsbot].x,i=cross[crsbot].y,id=cross[crsbot].id;
			while(a[i][j]!='*'){
				buf[buftop]=a[i][j];
				j++;buftop++;
			}
			buf[buftop]='\0';
			printf("%3d.%s\n",id,buf);
		}
		printf("Down\n");
		while(dontop-donbot-1){
			donbot++;buftop=0;
			int j=down[donbot].x,i=down[donbot].y,id=down[donbot].id;
			while(a[i][j]!='*'){
				buf[buftop]=a[i][j];
				i++;buftop++;
			}
			buf[buftop]='\0';
			printf("%3d.%s\n",id,buf);
		}

	}
	return 0;
}
