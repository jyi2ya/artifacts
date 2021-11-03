#include <stdio.h>
#include <stdlib.h>

/* type */
struct node{
	int ch;
	struct node* next;
};
typedef struct node node;
/* end */

/* global */
node *pos,*head,*tail;
/* end */

/* function */
void gotohead(void);
void gotoend(void);

node* newnode(void);
void add(int ch);
void delall(void);
void init(void);
/* end */

int main(void)
{
	int ch;
	while((ch=getchar())!=EOF){
		ungetc(ch,stdin);
		init();
		while((ch=getchar())!='\n' && ch!=EOF){
			switch(ch){
				case '[':{gotohead();break;}
				case ']':{gotoend();break;}
				default:{add(ch);break;}
			}
		}
		for(pos=head->next;pos!=NULL;pos=pos->next) putchar(pos->ch);
		putchar('\n');
		delall();
	}
	return 0;
}

node* newnode(void)
{
	node* ret=(node*)malloc(sizeof(ret));
	ret->ch='\0';
	ret->next=NULL;
	return ret;
}

void add(int ch)
{
	node* n=newnode();
	n->ch=ch;
	n->next=pos->next;
	pos->next=n;
	pos=n;
	if(pos->next==NULL) tail=pos;
}

void delall(void)
{
	while(head->next!=NULL) {
		node* d=head->next;
		head->next=d->next;
		free(d);
	}
	free(head);
}

void init(void)
{
	head=newnode();
	pos=head;
	tail=head;
}

void gotohead(void)
{
	pos=head;
}

void gotoend(void)
{
	pos=tail;
}
