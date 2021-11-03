#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct bgi {
	int buf[10009], top, lt0;
} bgi;

int cmp(bgi *a, bgi *b);
void sub(bgi *c, bgi *a, bgi *b);
void readint(bgi *x);
void printint(bgi *x);

bgi a, b, c;

int main(void)
{
	readint(&a);
	readint(&b);
	sub(&c, &a, &b);
	printint(&c);
	putchar('\n');
	return 0;
}

void printint(bgi *x)
{
	if (x->top == 0) {
		puts("0");
	} else {
		int i;
		if (x->lt0)
			putchar('-');
		for (i = x->top - 1; i >= 0; --i)
			printf("%d", x->buf[i]);
	}
}

int buf[10009];
void readint(bgi *x)
{
	int top = 0, ch;
	memset(x, 0, sizeof(bgi));
	while (!isdigit(ch = getchar()));
	do {
		buf[top++] = ch - '0';
	} while (isdigit(ch = getchar()));
	ungetc(ch, stdin);
	while (top)
		x->buf[x->top++] = buf[--top];
}

bgi tmp;
void sub(bgi *c, bgi *a, bgi *b)
{
	int i;
	memset(&tmp, 0, sizeof(tmp));
	if (cmp(a, b) < 0) {
		tmp.lt0 = 1;
		bgi *t = a; a = b; b = t;
	}
	for (i = 0; i < a->top; ++i)
		tmp.buf[i] = a->buf[i] - b->buf[i];
	for (i = 0; i < a->top; ++i)
		if (tmp.buf[i] < 0) {
			--tmp.buf[i + 1];
			tmp.buf[i] += 10;
		}
	tmp.top = a->top;
	while (tmp.buf[tmp.top] == 0 && tmp.top > 0)
		--tmp.top;
	++tmp.top;
	memcpy(c, &tmp, sizeof(bgi));
}

int cmp(bgi *a, bgi *b)
{
	if (a->top == b->top) {
		int i;
		for (i = a->top - 1; i >= 0; --i)
			if (a->buf[i] != b->buf[i])
				return a->buf[i] - b->buf[i];
		return 0;
	} else {
		return a->top - b->top;
	}
}
