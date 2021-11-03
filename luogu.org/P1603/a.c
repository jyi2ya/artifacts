#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
int di[30]={0,1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};

char z[1000][3],buf1[6],buf2[6];
int top=0;

int cmp(const void* p,const void* q){
	char* a=(char*)p,*b=(char*)q;
	
	strcpy(buf1,a);strcat(buf1,b);
	strcpy(buf2,b);strcat(buf2,a);
#ifdef DEBUG
	printf("compare bur1=%s,buf2=%s\n",buf1,buf2);
#endif

	return strcmp(buf1,buf2);
}

void read(void){
	char buf[100];
	while(scanf("%s",buf)==1){
		for(int i=0;i<30;i++) if(!strcmp(buf,a[i])){
			sprintf(z[top],"%02d",di[i]);
			top++;
			break;
		}
	}
}

int main(){
	read();
	qsort(z,top,sizeof(z[0]),cmp);
	int i;
	for(i=0;i<top;i++){
		if(z[i][0]!='0'){
			printf("%s",z[i]);
			break;
		}
		if(z[i][1]!='0'){
			putchar(z[i][1]);
			break;
		}
	}
	if(i==top) printf("0\n");
	for(i++;i<top;i++) printf("%s",z[i]);
	putchar('\n');
	return 0;
}

