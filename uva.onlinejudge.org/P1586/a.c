#include <stdio.h>
#include <ctype.h>

int readint(void){
	int tot=0,ch;
	while((ch=getchar())<='9' && ch>='0')tot=tot*10+ch-'0';
	ungetc(ch,stdin);
	return tot;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int ele,num;
		double tot=0.0,mass;

		while((ele=getchar())>'Z' || ele <'A');
		ungetc(ele,stdin);

		while((ele=getchar())!='\n'){
			switch(ele){
				case 'C':{mass=12.01;break;}
				case 'H':{mass=1.008;break;}
				case 'O':{mass=16.00;break;}
				case 'N':{mass=14.01;break;}
			}

			num=readint();
			if(num==0)num=1;

			tot+=(mass*num);
#ifdef DEBUG
			printf("num=%d,mass=%f,mass*num=%.3f\n",num,mass,mass*num);
#endif
		}
		printf("%.3f\n",tot);
	}
	return 0;
}
