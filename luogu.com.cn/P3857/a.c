#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long ullpow(unsigned long long a, unsigned long long b, 
		unsigned long long mod)
{
	unsigned long long ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

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

unsigned long long lbase_count_method(struct lbase *p)
{
	int cnt = 0;
	int i;
	for (i = 0; i < 64; ++i)
		if (p->v[i])
			++cnt;
	return ullpow(2, cnt, 2008);
}

int main_(void)
{
	int n, m;
	struct lbase lb;
	lbase_init(&lb);
	scanf("%d%d", &n, &m);
	while (m--) {
		int i;
		char buf[60];
		scanf("%s", buf);
		for (i = 0; i < n; ++i)
			buf[i] = (buf[i] == 'O' ? '0' : '1');
		lbase_insert(&lb, strtoull(buf, NULL, 2));
	}
	printf("%llu\n", lbase_count_method(&lb));
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
