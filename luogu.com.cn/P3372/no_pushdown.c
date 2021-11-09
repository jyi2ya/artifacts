#include <stdio.h>
#include <ctype.h>

#define MAX 400009

typedef long long ll;

int readll(ll *ans);
void putll(ll x);

void add(int l, int r, ll deltax);
ll query(int l, int r);

int N, M;

int main(void)
{
	int i;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i) {
		ll x;
		readll(&x);
		add(i, i, x);
	}
	for (i = 0; i < M; ++i) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			ll k;
			readll(&k);
			add(x, y, k);
		} else {
			putll(query(x, y));
			putchar('\n');
		}
	}
	return 0;
}

ll sgtree[MAX], addv[MAX];

void modify(int idx, int l, int r);

int add_l, add_r;
ll add_x;
void add_recursive(int idx, int l, int r)
{
	if (add_l <= l && r <= add_r) {
		addv[idx] += add_x;
	} else {
		int mid = l + (r - l) / 2;
		if (add_l <= mid) add_recursive(idx * 2, l, mid);
		if (mid < add_r) add_recursive(idx * 2 + 1, mid + 1, r);
	}
	modify(idx, l, r);
}
void add(int l, int r, ll deltax)
{
	add_l = l;
	add_r = r;
	add_x = deltax;
	add_recursive(1, 1, N);
}

int query_l, query_r;
ll query_recursive(int idx, int l, int r, ll k)
{
	if (query_l <= l && r <= query_r) {
		return sgtree[idx] + (r - l + 1) * k;
	} else {
		ll ans = 0;
		int mid = l + (r - l) / 2;
		if (query_l <= mid)
			ans += query_recursive(idx * 2, l, mid, k + addv[idx]);
		if (mid < query_r)
			ans += query_recursive(idx * 2 + 1, mid + 1, r, k + addv[idx]);
		return ans;
	}
}
ll query(int l, int r)
{
	query_l = l;
	query_r = r;
	return query_recursive(1, 1, N, 0);
}

void modify(int idx, int l, int r)
{
	sgtree[idx] = 0;
	if (l < r) sgtree[idx] = sgtree[idx * 2] + sgtree[idx * 2 + 1];
	sgtree[idx] += addv[idx] * (r - l + 1);
}

/* fastio {{{ */
int readll(ll *ans)
{
	int ch, lt0 = 0;
	*ans = 0;

	while (!isdigit(ch = getchar()) && ch != EOF && ch != '-');
	if (ch == EOF) return 0;
	else if (ch == '-') lt0 = 1;
	else *ans = ch - '0';

	while (isdigit(ch = getchar())) *ans = *ans * 10 + ch - '0';
	ungetc(ch, stdin);

	if (lt0) *ans = -*ans;
	return 1;
}

void putll(ll x)
{
	char buf[64], *top = buf;
	if (x == 0) putchar('0');
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	while (x) {
		*top++ = x % 10 + '0';
		x /= 10;
	}
	while (top != buf) putchar(*--top);
}
/* }}} */
