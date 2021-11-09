#include <stdio.h>
#include <stdlib.h>

enum {
	ADD, MID
};

int op[200009];
long long num[200009];
long long map[200009];
int maptop = 1;
int n, q;
int nq;

void read(void)
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		long long x;
		scanf("%lld", &x);
		op[i] = ADD;
		num[i] = x;
	}

	scanf("%d", &q);
	nq = n + q;
	for (i = n; i < nq; ++i) {
		char o[10];
		scanf("%s", o);
		if (*o == 'a') {
			long long x;
			scanf("%lld", &x);
			op[i] = ADD;
			num[i] = x;
		} else {
			op[i] = MID;
		}
	}
}

int cmp(const void *a, const void *b)
{
	return *(long long*)a < *(long long*)b ? -1 : 1;
}

void init(void)
{
	int i;
	for (i = 0; i < nq; ++i)
		if (op[i] == ADD)
			map[maptop++] = num[i];
	qsort(map + 1, maptop - 1, sizeof(long long), cmp);
}

int idx(long long x)
{
	int l = 1, r = maptop, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (map[m] < x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int ftree[300009];

int lowbit(int x)
{
	return x & ((~x) + 1);
}

void add(int p, int d)
{
	int i;
	for (i = p; i <= maptop; i += lowbit(i))
		ftree[i] += d;
}

int query(int p)
{
	int ans = 0;
	int i;
	for (i = p; i >= 1; i -= lowbit(i))
		ans += ftree[i];
	return ans;
}

int find(int d)
{
	int l = 1, r = maptop, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (d <= query(m))
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int main_(void)
{
	int i;
	int tot = 0;

	read();
	init();

	for (i = 0; i < nq; ++i) {
		if (op[i] == ADD) {
			add(idx(num[i]), 1);
			++tot;
		} else {
			int ans;
			ans = find((tot & 1) == 0 ? tot / 2 : tot / 2 + 1);
			printf("%lld\n", map[ans]);
		}

	}

	return 0;
}

int start_(void)
{
	return main_();
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	start_();

#ifdef DEBUG
	fclose(stdin);
#endif

	return 0;
}
