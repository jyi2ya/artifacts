#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* type */
struct node{
	int isend;
	struct node *next[33];
};
typedef struct node node;
/* end */

/* global */
char buf[1023];
node* head;
int top=0;
/* end */

/* function */
int readword(void);

/* trie */
void init(void);
node* newnode(void);
void insert(void);
void prt(node* now);
void delall(node* now);
/* end */

/* end */

int main(void){
	init();
	while(readword()) insert();
	prt(head);
	delall(head);
	free(head);
	return 0;
}

void init(void){
	head=newnode();
}

int readword(void){
	int ch,cnt=0;
	while(!isalpha(ch=getchar()))
		if(ch==EOF)
			return 0;
	buf[cnt++]=tolower(ch);
	while(isalpha(ch=getchar()))
		buf[cnt++]=tolower(ch);
	buf[cnt]='\0';
	return 1;
}

node* newnode(void){
	int i;
	node* ret=(node*)malloc(sizeof(node));
	ret->isend=0;
	for(i=0;i<27;++i) ret->next[i]=NULL;
	return ret;
}

void insert(void){
	int pos=0;
	node* now=head;
	while(buf[pos]!='\0'){
		if((now->next)[buf[pos]-'a'] == NULL) (now->next)[buf[pos]-'a']=newnode();
		now=(now->next)[buf[pos]-'a'];
		++pos;
	}
	now->isend=1;
}

void prt(node* now){
	int i;
	if(now->isend){
		for(i=0;i<top;++i) putchar(buf[i]);
		putchar('\n');
	}
	for(i=0;i<27;++i)
		if(now->next[i]!=NULL){
			buf[top++]=i+'a';
			prt(now->next[i]);
			--top;
		}
}

void delall(node* now){
	int i;
	for(i=0;i<27;++i) {
		if(now->next[i]!=NULL) delall(now->next[i]);
		free(now->next[i]);
	}
}
