#include <stdio.h>
#include <string.h>

int money[15],add[15];
int friends[15];
char name[15][20];

int find(char* nam){
	int id;
	for(id=0;strcmp(nam,name[id]);id++);
	return id;
}

void solve(void){
	char nam[20];
	scanf("%s",nam);
	int id=find(nam);
	scanf("%d%d",money+id,friends+id);
	for(int i=0;i<friends[id];i++){
		char buf[20];
		int id4friend;
		scanf("%s",buf);
		id4friend=find(buf);
		add[id4friend]+=(money[id]/friends[id]);
	}
	if(friends[id]!=0)add[id]+=(money[id]%friends[id]);

}

void init(){
	memset(add,0,sizeof(add));
	memset(money,0,sizeof(money));
	memset(friends,0,sizeof(friends));
	memset(name,0,sizeof(name));
}

int main(){
	int stu,i;
	int first=1;
	while(scanf("%d",&stu)==1){
		init();
		if(first)first=0;else putchar('\n');
		for(i=0;i<stu;i++)scanf("%s",name[i]);
		for(i=0;i<stu;i++)solve();
		for(i=0;i<stu;i++)printf("%s %d\n",name[i],add[i]-money[i]);
	}
	return 0;
}
