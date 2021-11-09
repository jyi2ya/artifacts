#include <stdio.h>

int ftree[50009];
int n, m;
int stack[50009], top = 0;

int lowbit(int x)
{
	return x & ((~x) + 1);
}

void add(int p, int d)
{
	int i;
	for (i = p; i <= n; i += lowbit(i))
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

int main_(void)
{
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		add(i, 1);

	while (m--) {
		char op[10];
		int x;
		scanf("%s", op);

		if (*op == 'D') {
			scanf("%d", &x);
			add(x, -1);
			stack[top++] = x;
		} else if (*op == 'R') {
			add(stack[--top], 1);
		} else {
			int l, r, mid;
			int ll, rr;

			scanf("%d", &x);

			l = 1, r = x;
			while (l < r) {
				mid = l + (r - l) / 2;
				if (query(x) - query(mid - 1) == (x - mid + 1))
					r = mid;
				else
					l = mid + 1;
			}
			ll = l;

			l = x, r = n + 1;
			while (l < r) {
				mid = l + (r - l) / 2;
				if (query(mid) - query(x - 1) == (mid - x + 1))
					l = mid + 1;
				else
					r = mid;
			}
			rr = l;

			printf("%d\n", rr - ll);
			/*
			printf("%s %d\n", op, x);
			printf("%d %d\n", ll, rr);
			for (i = 1; i <= n; ++i)
				printf("%d ", query(i) - query(i - 1));
			putchar('\n');
			*/
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
