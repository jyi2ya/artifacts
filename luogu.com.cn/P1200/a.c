/*
ID:lindong6
PROG:ride
LANG:C++
 */
#include <stdio.h>

int sum(char* s){
	int i;
	long sum=s[0]-'A'+1;

#ifdef DEBUG
	printf("-----sum=%d\n",sum);
#endif

	for(i=1;s[i]!='\0';i++){
		sum*=(s[i]-'A'+1);

#ifdef DEBUG
		printf("-----sum=%d\n");
#endif

	}
	return sum%47;
}

int main(){
	char team[7],star[7],SumTeam,SumStar;
	scanf("%s%s",star,team);

	SumTeam=sum(team);
	SumStar=sum(star);

#ifdef DEBUG
	printf("-----team:%d,star:%d\n",SumTeam,SumStar);
#endif

	if(SumTeam==SumStar) printf("GO\n");
	else printf("STAY\n");

	return 0;
}
