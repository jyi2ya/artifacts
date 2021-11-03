#include <stdio.h>
#include <string.h>

int dir[6][6] = { { 0, 1, 2, 3, 4, 5 }, { 1, 0, 3, 2, 5, 4 }, { 2, 0, 1, 4, 5, 3 }, { 3, 0, 4, 1, 5, 2 }, { 4, 0, 2, 3, 5, 1 }, { 5, 1, 3, 2, 4, 0 } };  

char s1[10],s2[10],s[20];

int test()
{
	int i,j;
	for (i=0;i<6;i++)
	{
		char t[10];
		for (j=0;j<6;j++)
			t[j]=s1[dir[i][j]];  
		for (j=0;j<4;j++)  
		{  
			char c_t;  
			c_t=t[1];
			t[1]=t[2];
			t[2]=t[4];
			t[4]=t[3];
			t[3]=c_t;
			if (strcmp(t,s2)==0) return 1;
		}
	}
	return 0;
}
int main()
{
	while(scanf("%s",s)==1){
		strncpy(s1,s  ,6);
		strncpy(s2,s+6,6);
		s2[6]='\0';
		s1[6]='\0';
		if (test())puts("TRUE");
		else puts("FALSE");
	}
	return 0;
}
