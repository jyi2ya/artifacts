#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int a[MAX], b[MAX], c[MAX], num[MAX], nxt[MAX], n, cnt, used[MAX];
char s1[MAX], s2[MAX], s3[MAX];

void init(int x);
void dfs(int x);

int main(void)
{
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	scanf("%s%s%s", s1, s2, s3);

	for (i = 0; i < n; i++) {
		a[i] = s1[i] - 'A';
		b[i] = s2[i] - 'A';
		c[i] = s3[i] - 'A';
		num[i] = -1;
	}

	for (i = n - 1; i >= 0; i--) {
		init(a[i]);
		init(b[i]);
		init(c[i]);
	}
	for (i = 0; i < n; i++)
		used[i] = 0;
	dfs(0);
	return 0;
}

int check(void)
{
	int i, A, B, C, x;
	for (i = n - 1, x = 0; i >= 0; i--) {
		A = num[a[i]], B = num[b[i]], C = num[c[i]];
		if ((A + B + x) % n != C)
			return 0;
		x = (A + B + x) / n;
	}
	return 1;
}

int prune_test(void)
{
	int i, x, A, B, C;
	if (num[a[0]] + num[b[0]] >= n)
		return 1;
	for (i = n - 1; i >= 0; i--) {
		A = num[a[i]], B = num[b[i]], C = num[c[i]];
		if (A == -1 || B == -1 || C ==-1)
			continue;
		if ((A + B) % n != C && (A + B + 1) % n != C)
			return 1;
	}
	return 0;
}

void print_ans(void)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", num[i]);
	exit(0);
}

void dfs(int x)
{
	int i;
	if (prune_test())
		return;
	if (x == n) {
		if (check())
			print_ans();
		return;
	}
	for (i = n - 1; i >= 0; i--)
		if(used[i] == 0) {
			num[nxt[x]] = i;
			used[i] = 1;
			dfs(x + 1);
			num[nxt[x]] = -1;
			used[i] = 0;
		}
}

void init(int x)
{
	if (!used[x]) {
		used[x] = 1;
		nxt[cnt++] = x;
	}
}
