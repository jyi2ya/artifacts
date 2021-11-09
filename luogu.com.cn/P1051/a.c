#include <stdio.h>
#include <string.h>

char max_name[25];
int max=0,total=0;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char name[25],isWestern,isCadre;
		int ScoreInExam,ScoreInClass,articles;
		scanf("%s%d%d %c %c%d",name,&ScoreInExam,&ScoreInClass,&isCadre,&isWestern,&articles);
		int tot=0;

		if(ScoreInExam>80 && articles>0)tot+=8000;
		if(ScoreInExam>85 && ScoreInClass>80)tot+=4000;
		if(ScoreInExam>90)tot+=2000;
		if(ScoreInExam>85 && isWestern=='Y')tot+=1000;
		if(ScoreInClass>80 && isCadre=='Y')tot+=850;

		total+=tot;
		if(tot>max){
			strcpy(max_name,name);
			max=tot;
		}
	}
	printf("%s\n%d\n%d\n",max_name,max,total);
	return 0;
}
