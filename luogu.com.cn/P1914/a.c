#include <stdio.h>

int main(void){
	char buf[110];
	int num;
	scanf("%d%s",&num,buf);
	{
		int i;
		for(i=0;buf[i]!='\0';i++)putchar((buf[i]-'a'+num)%26+'a');
	}
	putchar('\n');
	return 0;
}

