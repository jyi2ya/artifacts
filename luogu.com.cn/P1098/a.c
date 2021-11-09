#include <stdio.h>
#include <ctype.h>
#include <string.h>

int p1,p2,p3,top=0;
char a[10000],buf[1000000],buf2[1000000];

int tostars(int x){
	return '*';
}

void unextra(int l,int r){
	top=0;
	memset(buf,0,sizeof(buf));
	memset(buf2,0,sizeof(buf));
	if(l==r-1){
		buf[top++]=l;
		buf[top++]=r;
		return;
	}
	if(l==r){
		buf[top++]=l;
		buf[top++]='-';
		buf[top++]=r;
		return;
	}
	buf[top++]=l;
	int (*to)(int x);
	{
		if(p1==1)to=tolower;
		if(p1==2)to=toupper;
		if(p1==3)to=tostars;
	}
	int times=p2;
	{
		if(p3==1)
			for(int j=l+1;j<r;j++)
				for(int i=0;i<times;i++)
					buf[top++]=to(j);
		if(p3==2)
			for(int j=r-1;j>l;j--)
				for(int i=0;i<times;i++)
					buf[top++]=to(j);
	}
	buf[top++]=r;
	buf[top]='\0';


}

int main(){
	scanf("%d%d%d",&p1,&p2,&p3);
	while(getchar()!='\n');
	fgets(a,104,stdin);
	int i;
	for(i=0;a[i+1]!='\0';i++){
		if(a[i]=='-')
			if(i>0)
				if((islower(a[i-1]) && islower(a[i+1])) || (isdigit(a[i-1]) && isdigit(a[i+1])))
					if(a[i-1]<=a[i+1]){
						unextra(a[i-1],a[i+1]);
#ifdef DEBUG
						printf("len of a=%d,buf1=%d,buf2=%d\na=%s,buf1=%s,buf2=%s\n",strlen(a),strlen(buf),strlen(buf2),a,buf,buf2);
#endif
						strcpy(buf2,a+i+2);
						a[i-1]='\0';
						strcat(a,buf);
						strcat(a,buf2);
#ifdef DEBUG
						printf("DONE\n");
#endif
					}
	}
	puts(a);
	return 0;
}
