#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX (1 << 22)

struct cplx {
	double real;
	double imag;
};

struct cplx c_new(double real, double imag)
{
	struct cplx r;
	r.real = real;
	r.imag = imag;
	return r;
}

struct cplx c_sub(struct cplx p, struct cplx q)
{
	return c_new(p.real - q.real, p.imag - q.imag);
}

struct cplx c_add(struct cplx p, struct cplx q)
{
	return c_new(p.real + q.real, p.imag + q.imag);
}

struct cplx c_mul(struct cplx p, struct cplx q)
{
	return c_new(p.real * q.real - p.imag * q.imag,
		     p.real * q.imag + p.imag * q.real);
}

void c_swap(struct cplx *p, struct cplx *q)
{
	struct cplx t = *p;
	*p = *q;
	*q = t;
}

const double PI = acos(-1);

struct {
	int v[MAX];
	int n;
} rev;

struct poly {
	struct cplx v[MAX][1];
	int n;
};

struct poly *p_fft(struct poly *p, int len, int type)
{
	int i, j;
	int mid;

	for (i = 0; i < len; ++i)
		if (i < rev.v[i])
			c_swap(p->v[i], p->v[rev.v[i]]);

	for (mid = 1; mid < len; mid <<= 1) {
		struct cplx wn = c_new(cos(PI / mid), type * sin(PI / mid));
		for (i = 0; i < len; i += (mid << 1)) {
			struct cplx w = c_new(1, 0);
			for (j = 0; j < mid; ++j) {
				struct cplx x = p->v[i + j][0];
				struct cplx y = c_mul(w, p->v[i + mid + j][0]);
				p->v[i + j][0] = c_add(x, y);
				p->v[i + mid + j][0] = c_sub(x, y);
				w = c_mul(w, wn);
			}
		}
	}
	return p;
}

struct poly *p_mul(struct poly *ans, struct poly *op1, struct poly *op2)
{
	static struct poly tmp;
	struct poly *t = (ans == op1 || ans == op2) ? &tmp : ans;
	int len = 1;
	int lg = 0;
	int i;

	t->n = op1->n + op2->n;
	while (len <= t->n) {
		len <<= 1;
		++lg;
	}
	for (; rev.n < len; ++rev.n)
		rev.v[rev.n] = (rev.v[rev.n >> 1] >> 1) | ((rev.n & 1) << (lg - 1));
	p_fft(op1, len, 1);
	p_fft(op2, len, 1);
	for (i = 0; i < len; ++i)
		t->v[i][0] = c_mul(op1->v[i][0], op2->v[i][0]);
	p_fft(t, len, -1);
	for (i = 0; i <= t->n; ++i)
		t->v[i]->real /= len;
	if (ans == op1 || ans == op2)
		memcpy(ans, t, sizeof(struct poly));
	return ans;
}

int main(void)
{
	int i;
	static struct poly a[1], b[1], c[1];

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &a->n, &b->n);
	for (i = 0; i <= a->n; ++i)
		scanf("%lf", &a->v[i]->real);
	for (i = 0; i <= b->n; ++i)
		scanf("%lf", &b->v[i]->real);
	p_mul(c, a, b);
	for (i = 0; i <= c->n; ++i)
		printf("%lld ", (long long)(c->v[i]->real + 0.5));
	putchar('\n');
	return 0;
}
