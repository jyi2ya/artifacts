#include <stdio.h>
#include <string.h>
#include <ctype.h>

int base;

typedef struct bgi {
	int buf[2009], top;
} bgi;

void readint(bgi *x);
void add(bgi *c, bgi *a, bgi *b);
void printint(bgi *x);

bgi a, b, c;

int main(void)
{
	scanf("%d", &base);
	readint(&a);
	readint(&b);
	add(&c, &a, &b);
	printint(&c);
	putchar('\n');
	return 0;
}

bgi tmp;
void add(bgi *c, bgi *a, bgi *b)
{
	int i;
	memset(&tmp, 0, sizeof(tmp));
	tmp.top = (a->top > b->top) ? a->top : b->top;
	for (i = 0; i < tmp.top; ++i)
		tmp.buf[i] = a->buf[i] + b->buf[i];
	for (i = 0; i < tmp.top; ++i) {
		tmp.buf[i + 1] += tmp.buf[i] / base;
		tmp.buf[i] %= base;
	}
	while (tmp.buf[tmp.top])
		++tmp.top;
	memcpy(c, &tmp, sizeof(bgi));
}

void printint(bgi *x)
{
	if (x->top == 0) {
		puts("0");
	} else {
		int i;
		for (i = x->top - 1; i >= 0; --i) {
			if (x->buf[i] < 10)
				putchar(x->buf[i] + '0');
			else
				putchar(x->buf[i] + 'A' - 10);
		}
	}
}

int buf[2009];
void readint(bgi *x)
{
	int top = 0, ch;
	memset(x, 0, sizeof(bgi));
	while (!isalnum(ch = getchar()));
	do {
		if (isdigit(ch))
			buf[top++] = ch - '0';
		else
			buf[top++] = ch - 'A' + 10;
	} while (isalnum(ch = getchar()));
	ungetc(ch, stdin);
	while (top)
		x->buf[x->top++] = buf[--top];
}
