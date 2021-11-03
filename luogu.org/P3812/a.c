#include <stdio.h>
#include <string.h>

struct lbase {
	unsigned long long v[64];
};

void lbase_init(struct lbase *p)
{
	memset(p, 0, sizeof(struct lbase));
}

void lbase_insert(struct lbase *p, unsigned long long x)
{
	int i;

	for (i = 60; i >= 0; --i)
		if (x >> i) {
			if (p->v[i] == 0) {
				p->v[i] = x;
				break;
			} else {
				x ^= p->v[i];
			}
		}
}

unsigned long long lbase_query_max(struct lbase *p)
{
	int i;
	unsigned long long ans = 0;
	for (i = 60; i >= 0; --i)
		if ((ans ^ p->v[i]) > ans)
			ans ^= p->v[i];
	return ans;
}

int main_(void)
{
	struct lbase x;
	int n;
	lbase_init(&x);
	scanf("%d", &n);
	while (n--) {
		unsigned long long t;
		scanf("%llu", &t);
		lbase_insert(&x, t);
	}
	printf("%llu\n", lbase_query_max(&x));
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
