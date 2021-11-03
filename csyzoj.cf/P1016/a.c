#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE (10000)

typedef struct bgi {
	long long b[10009];
	int t;
} bgi;

int bgi_cmp(bgi *op1, bgi *op2);
int bgi_is_odd(bgi *c);
void bgi_div_ll(bgi *dest, bgi *op1, long long op2);
void bgi_mul_ll(bgi *dest, bgi *op1, long long op2);
void bgi_print(bgi *src);
void bgi_set_bgi(bgi *dest, bgi *src);
void bgi_set_str(bgi *dest, char *str);
void bgi_sub_bgi(bgi *dest, bgi *op1, bgi *op2);
void bgi_add_bgi(bgi *dest, bgi *op1, bgi *op2);

char R[10009];

int main(void)
{
	static struct bgi n;
	static struct bgi one;
	static struct bgi t;
#ifndef ONLINE_JUDGE
	freopen("tenki.in", "r", stdin);
	freopen("tenki.out", "w", stdout);
#endif
	bgi_set_str(&t, "1");
	bgi_set_str(&one, "1");
	scanf("%s", R);
	bgi_set_str(&n, R);
	bgi_sub_bgi(&n, &n, &one);
	while (bgi_cmp(&t, &n) < 0)
		bgi_mul_ll(&t, &t, 2);
	bgi_add_bgi(&t, &t, &n);
	bgi_add_bgi(&t, &t, &one);
	bgi_print(&t);
	putchar('\n');
	return 0;
}

void bgi_mul_ll(bgi *dest, bgi *op1, long long op2)
{
	int i;
	bgi *t = (bgi *)malloc(sizeof(bgi));
	memset(t, 0, sizeof(bgi));
	for (i = 0; i < op1->t; ++i)
		t->b[i] = op1->b[i] * op2;
	for (i = 0; i < op1->t; ++i) {
		t->b[i + 1] += t->b[i] / BASE;
		t->b[i] %= BASE;
	}
	for (i = op1->t; t->b[i]; ++i) {
		t->b[i + 1] += t->b[i] / BASE;
		t->b[i] %= BASE;
	}
	t->t = i;
	bgi_set_bgi(dest, t);
	free(t);
}

void bgi_div_ll(bgi *dest, bgi *op1, long long op2)
{
	int i;
	long long res = 0;
	bgi *t = (bgi *)malloc(sizeof(bgi));
	memset(t, 0, sizeof(bgi));
	for (i = op1->t - 1; i >= 0; --i) {
		res = res * BASE + op1->b[i];
		t->b[i] = res / op2;
		res %= op2;
	}
	for (t->t = op1->t; t->b[t->t] == 0 && t->t >= 0; --t->t)
		;
	++t->t;
	bgi_set_bgi(dest, t);
	free(t);
}

int bgi_is_odd(bgi *c)
{
	return c->b[0] & 1;
}

void bgi_print(bgi *src)
{
	int i;
	if (!src->t)
		putchar('0');
	printf("%lld", src->b[src->t - 1]);
	for (i = src->t - 2; i >= 0; --i)
		printf("%04lld", src->b[i]);
}

void bgi_add_bgi(bgi *dest, bgi *op1, bgi *op2)
{
	int i;
	bgi *t = (bgi *)malloc(sizeof(bgi));
	memset(t, 0, sizeof(bgi));
	for (i = 0; i < op1->t; ++i)
		t->b[i] = op1->b[i] + op2->b[i];
	for (i = 0; i < op1->t; ++i) {
		t->b[i + 1] += t->b[i] / BASE;
		t->b[i] %= BASE;
	}
	for (t->t = op1->t > op2->t ? op1->t : op2->t; t->b[t->t]; ++t->t) {
		t->b[t->t + 1] += t->b[t->t] / BASE;
		t->b[t->t] %= BASE;
	}
	bgi_set_bgi(dest, t);
	free(t);
}

void bgi_sub_bgi(bgi *dest, bgi *op1, bgi *op2)
{
	int i;
	bgi *t = (bgi *)malloc(sizeof(bgi));
	memset(t, 0, sizeof(bgi));
	for (i = 0; i < op1->t; ++i)
		t->b[i] = op1->b[i] - op2->b[i];
	for (i = 0; i < op1->t; ++i)
		if (t->b[i] < 0) {
			--t->b[i + 1];
			t->b[i] += BASE;
		}
	t->t = op1->t;
	while (t->t >= 0 && t->b[t->t] == 0)
		--t->t;
	++t->t;
	bgi_set_bgi(dest, t);
	free(t);
}

void bgi_set_str(bgi *dest, char *str)
{
	int i, j;
	memset(dest, 0, sizeof(bgi));
	dest->t = 0;
	for (i = strlen(str); i >= 0; i -= 4) {
		for (j = (i - 4 > 0) ? i - 4 : 0; j < i; ++j)
			dest->b[dest->t] = dest->b[dest->t] * 10 + str[j] - '0';
		++dest->t;
	}
	while (dest->b[dest->t] == 0)
		--dest->t;
	++dest->t;
}

void bgi_set_bgi(bgi *dest, bgi *src)
{
	if (dest == src)
		return;
	memcpy(dest, src, sizeof(bgi));
}

int bgi_cmp(bgi *op1, bgi *op2)
{
	int i;
	if (op1->t != op2->t)
		return op1->t - op2->t;
	for (i = op1->t - 1; i >= 0; --i)
		if (op1->b[i] != op2->b[i])
			return op1->b[i] - op2->b[i];
	return 0;
}
