#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX (200009)

struct pst {
	struct {
		int size;
		int l, r;
	} N[N_MAX * 25];
	int N_cnt;
	int R[N_MAX];
	int R_cnt;
	int n;
	int M[N_MAX];
} P;

#define p_map(y_, x_) \
	do { \
		int l_ = 0, r_ = P.n, m_; \
		while (l_ < r_) { \
			m_ = l_ + (r_ - l_) / 2; \
			if (P.M[m_] < (x_)) \
				l_ = m_ + 1; \
			else \
				r_ = m_; \
		} \
		(y_) = l_; \
	} while (0)

#define p_unmap(y_, x_) ((y_) = P.M[x_])

int p_cmp(const void *a, const void *b)
{
	return *(int*)a < *(int*)b ? -1 : 1;
}

#define p_alc(x_) \
	do { \
		P.N[P.N_cnt].l = -1; \
		P.N[P.N_cnt].r = -1; \
		P.N[P.N_cnt].size = 0; \
		(x_) = P.N_cnt++; \
	} while (0)

#define p_dct(v_, n_) \
	do { \
		memcpy(P.M, (v_), sizeof(int) * (n_)); \
		qsort(P.M, (n_), sizeof(P.M[0]), p_cmp); \
	} while (0)

int p_bld_r(int l, int r)
{
	int rt;
	int m;
	p_alc(rt);
	if (r - l == 1)
		return rt;
	m = l + (r - l) / 2;
	P.N[rt].l = p_bld_r(l, m);
	P.N[rt].r = p_bld_r(m, r);
	return rt;
}

#define p_bld() \
	do { \
		P.R[0] = p_bld_r(0, P.n); \
	} while (0)

#define p_ini(v_, n_) \
	do { \
		P.N_cnt = 0; \
		P.R_cnt = 1; \
		P.n = (n_); \
		p_dct(v_, n_); \
		p_bld(); \
	} while (0)

int p_apd_r(int rt, int l, int r, int val)
{
	int nr;
	int m;
	p_alc(nr);
	P.N[nr].l = P.N[rt].l;
	P.N[nr].r = P.N[rt].r;
	P.N[nr].size = P.N[rt].size + 1;
	if (r - l == 1)
		return nr;
	m = l + (r - l) / 2;
	if (val < m)
		P.N[nr].l = p_apd_r(P.N[rt].l, l, m, val);
	else
		P.N[nr].r = p_apd_r(P.N[rt].r, m, r, val);
	return nr;
}

#define p_apd(x_) \
	do { \
		int pos_; \
		p_map(pos_, x_); \
		P.R[P.R_cnt] = p_apd_r(P.R[P.R_cnt - 1], 0, n, pos_); \
		++P.R_cnt; \
	} while (0)

int p_qry_r(int lr, int rr, int l, int r, int k)
{
	int size = P.N[P.N[rr].l].size - P.N[P.N[lr].l].size;
	int m;
	if (r - l == 1)
		return l;
	m = l + (r - l) / 2;
	if (size < k)
		return p_qry_r(P.N[lr].r, P.N[rr].r, m, r, k - size);
	return p_qry_r(P.N[lr].l, P.N[rr].l, l, m, k);
}

#define p_qry(ans, l, r, k) \
	do { \
		int ans_ = p_qry_r(P.R[l - 1], P.R[r], 0, P.n, k); \
		p_unmap(ans, ans_); \
	} while (0)

void p_prt(int rt)
{
	static int depth = 0;
	int i;
	if (rt == -1)
		return ;
	if (depth == 0)
		puts("=======");
	++depth;
	p_prt(P.N[rt].l);
	--depth;
	for (i = 0; i < depth; ++i)
		putchar('=');
	printf("%d\n", P.N[rt].size);
	++depth;
	p_prt(P.N[rt].r);
	--depth;
}

int main(void)
{
	int n, m;
	int i;
	static int val[N_MAX];
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	p_ini(val, n);
	for (i = 0; i < n; ++i)
		p_apd(val[i]);
	while (m--) {
		int l, r, k;
		int ans;
		scanf("%d%d%d", &l, &r, &k);
		p_qry(ans, l, r, k);
		printf("%d\n", ans);
	}
	return 0;
}
