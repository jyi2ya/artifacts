#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a < *(int *)b ? -1 : 1;
}

struct val {
	int ref, val;
};

struct {
	struct val v[1000009];
	int top, siz;
} H;

void h_ini(void)
{
	H.top = 1;
	H.siz = 0;
}

void vswap(struct val *a, struct val *b)
{
	struct val t = *a;
	*a = *b;
	*b = t;
}

void h_push(struct val v)
{
	int p = H.top;
	H.v[H.top++] = v;
	while (p >= 1) {
		int n = p / 2;
		if (H.v[n].val > H.v[p].val)
			vswap(&H.v[n], &H.v[p]);
		else
			break;
		p = n;
	}
	++H.siz;
}

struct val h_top(void)
{
	return H.v[1];
}

void h_pop(void)
{
	int p = 1;
	H.v[1].val = 0x3f3f3f3f;
	while (p * 2 < H.top) {
		int n = p * 2;
		if (n + 1 < H.top && H.v[n + 1].val < H.v[n].val)
			++n;
		vswap(&H.v[p], &H.v[n]);
		p = n;
	}
	--H.siz;
}

int main(void)
{
	int n;
	static int a[1000009];
	static int b[1000009];
	static int cnt[1000009];
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	qsort(a, n, sizeof(*a), cmp);
	qsort(b, n, sizeof(*b), cmp);
	h_ini();
	for (i = 0; i < n; ++i) {
		struct val t;
		t.val = a[0] + b[i];
		t.ref = i;
		h_push(t);
	}
	while (n--) {
		struct val cur = h_top();
		h_pop();
		++cnt[cur.ref];
		printf("%d ", cur.val);
		cur.val = a[cnt[cur.ref]] + b[cur.ref];
		h_push(cur);
	}
	putchar('\n');
	return 0;
}
