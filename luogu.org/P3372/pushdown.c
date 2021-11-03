#include <stdio.h>
#include <ctype.h>

#define MAX 400009

typedef long long ll;

int readll(ll *ans);
void putll(ll x);

ll query(int l, int r);
void add(int l, int r, ll deltax);

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
	while (M--) {
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

void pushdown(int idx, int l, int r);
void maintain(int idx, int l, int r);

int add_l, add_r;
ll add_x;
void add_recursive(int idx, int l, int r)
{
	if (add_l <= l && r <= add_r) {
		addv[idx] += add_x;
		sgtree[idx] += add_x * (r - l + 1);
	} else {
		pushdown(idx, l, r);
		int mid = l + (r - l) / 2;
		if (add_l <= mid)
			add_recursive(idx * 2, l, mid);
		if (mid < add_r)
			add_recursive(idx * 2 + 1, mid + 1, r);
		maintain(idx, l, r);
	}
}
void add(int l, int r, ll deltax)
{
	add_l = l;
	add_r = r;
	add_x = deltax;
	add_recursive(1, 1, N);
}

int query_l, query_r;
ll query_recursive(int idx, int l, int r)
{
	if (query_l <= l && r <= query_r) {
		return sgtree[idx];
	} else {
		int mid = l + (r - l) / 2;
		pushdown(idx, l, r);
		ll ans = 0;
		if (query_l <= mid)
			ans += query_recursive(idx * 2, l, mid);
		if (mid < query_r)
			ans += query_recursive(idx * 2 + 1, mid + 1, r);
		return ans;
	}
}
ll query(int l, int r)
{
	query_l = l;
	query_r = r;
	return query_recursive(1, 1, N);
}

void pushdown(int idx, int l, int r)
{
	int mid = l + (r - l) / 2;
	addv[idx * 2] += addv[idx];
	addv[idx * 2 + 1] += addv[idx];
	sgtree[idx * 2] += addv[idx] * (mid - l + 1);
	sgtree[idx * 2 + 1] += addv[idx] * (r - mid);
	addv[idx] = 0;
}

void maintain(int idx, int l, int r)
{
	sgtree[idx] = sgtree[idx * 2] + sgtree[idx * 2 + 1];
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
