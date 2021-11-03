#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lbase {
	unsigned long long v[64];
};

void lbase_init(struct lbase *p)
{
	memset(p, 0, sizeof(struct lbase));
}

int lbase_insert(struct lbase *p, unsigned long long x)
{
	int i;
	for (i = 62; i >= 0; --i)
		if (x >> i) {
			if (p->v[i] == 0) {
				p->v[i] = x;
				break;
			} else {
				x ^= p->v[i];
				if (x == 0)
					return 1;
			}
		}
	return 0;
}

struct magic {
	unsigned long long number;
	int magic;
};

struct magic stone[1009];

int cmp(const void *p1, const void *p2)
{
	struct magic *a = (struct magic*)p1;
	struct magic *b = (struct magic*)p2;
	return a->magic < b->magic ? 1 : -1;
}

struct lbase lb;

int main_(void)
{
	int i;
	int n;
	int ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%llu%d", &stone[i].number, &stone[i].magic);
	qsort(stone, n, sizeof(stone[0]), cmp);
	lbase_init(&lb);
	for (i = 0; i < n; ++i)
		if (lbase_insert(&lb, stone[i].number) == 0)
			ans += stone[i].magic;
	printf("%d\n", ans);
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
