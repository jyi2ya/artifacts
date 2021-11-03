#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct bgi {
	int buf[4009], top;
} bgi;

void readint(bgi *x);
void multi(bgi *c, bgi *a, bgi *b);
void printbgi(bgi *x);

bgi a, b, c;
int main(void)
{
	readint(&a);
	readint(&b);
	multi(&c, &a, &b);
	printbgi(&c);
	putchar('\n');
	return 0;
}

void printbgi(bgi *x)
{
	if (x->top == 0) {
		puts("0");
	} else {
		int i;
		for (i = x->top - 1; i >= 0; --i)
			printf("%d", x->buf[i]);
	}
}

bgi tmp;
void multi(bgi *c, bgi *a, bgi *b)
{
	int i, j;
	memset(&tmp, 0, sizeof(tmp));
	tmp.top = a->top + b->top + 5;
	for (i = 0; i < a->top; ++i)
		for (j = 0; j < b->top; ++j)
			tmp.buf[i + j] += a->buf[i] * b->buf[j];
	for (i = 0; i < tmp.top; ++i)
		if (tmp.buf[i] > 9) {
			tmp.buf[i + 1] += tmp.buf[i] / 10;
			tmp.buf[i] %= 10;
		}
	while (tmp.buf[tmp.top] == 0 && tmp.top > 0)
		--tmp.top;
	++tmp.top;
	memcpy(c, &tmp, sizeof(bgi));
}

int buf[2009];
void readint(bgi *x)
{
	int ch, top = 0;
	memset(x, 0, sizeof(bgi));
	x->top = 0;
	while (!isdigit(ch = getchar()));
	do {
		buf[top++] = ch - '0';
	} while (isdigit(ch = getchar()));
	ungetc(ch, stdin);
	while (top)
		x->buf[x->top++] = buf[--top];
}
