/*
ID:lindong6
PROG:gift1
LANG:C++
*/
#include <stdio.h>
#include <string.h>

int money[15],add[15];
int friends[15];
char name[15][20];

int find(char* nam){
	int id;
#ifdef DEBUG
	printf("     -----Finding...name=%s\n",nam);
#endif
	for(id=0;strcmp(nam,name[id]);id++);
	return id;
}

void solve(void){
	char nam[20];
	scanf("%s",nam);
	int id=find(nam);
	scanf("%d%d",&(money[id]),&(friends[id]));
#ifdef DEBUG
	printf("     -----name:%s,money:%d,friends:%d\n",name[id],money[id],friends[id]);
#endif
	int i;
	for(i=0;i<friends[id];i++){
		char buf[20];
		int id4friend;
		scanf("%s",buf);
		id4friend=find(buf);
		add[id4friend]+=(money[id]/friends[id]);
	}
#ifdef DEBUG
	printf("     #####id:%d,money:%d,friends:%d\n",id,money[id],friends[id]);
#endif
	if(friends[id]!=0)add[id]+=(money[id]%friends[id]);
}

int main(){
	int stu,i;
	scanf("%d",&stu);
	memset(add,0,sizeof(add));
	for(i=0;i<stu;i++)scanf("%s",name[i]);
	for(i=0;i<stu;i++)solve();
	for(i=0;i<stu;i++)printf("%s %d\n",name[i],add[i]-money[i]);
	return 0;
}
