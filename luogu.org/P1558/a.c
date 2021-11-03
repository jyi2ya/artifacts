#include <stdio.h>

void set(int l, int r, int c, int ml, int mr, int st);
int query(int l, int r, int c, int ql, int qr);

int main(void)
{
	int T, L, O, a, b, c;
	char buf[3];
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d", &L, &T, &O);
	set(1, L, 1, 1, L, 1 << 1);
	while (O--) {
		scanf("%s%d%d", buf, &a, &b);
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		if (buf[0] == 'C') {
			scanf("%d", &c);
			set(1, L, 1, a, b, 1 << c);
		} else {
			int x = query(1, L, 1, a, b), ans = 0;
			while (x) {
				++ans;
				x -= (x & -x);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

int setv[400009], sg[400009];

void pushdown(int c)
{
	if (setv[c]) {
		setv[c << 1] = setv[c];
		setv[c << 1 | 1] = setv[c];
		sg[c << 1] = setv[c];
		sg[c << 1 | 1] = setv[c];

		setv[c] = 0;
	}
}

int query(int l, int r, int c, int ql, int qr)
{
	int ans = 0;
	if (ql <= l && r <= qr) {
		ans = sg[c];
	} else {
		int m = l + (r - l) / 2;
		pushdown(c);
		if (ql <= m)
			ans |= query(l, m, c << 1, ql, qr);
		if (m + 1 <= qr)
			ans |= query(m + 1, r, c << 1 | 1, ql, qr);
		sg[c] = sg[c << 1] | sg[c << 1 | 1];
	}
	return ans;
}

void set(int l, int r, int c, int ml, int mr, int st)
{
	if (ml <= l && r <= mr) {
		setv[c] = st;
		sg[c] = st;
	} else {
		int m = l + (r - l) / 2;
		pushdown(c);
		if (ml <= m)
			set(l, m, c << 1, ml, mr, st);
		if (m + 1 <= mr)
			set(m + 1, r, c << 1 | 1, ml, mr, st);
		sg[c] = sg[c << 1] | sg[c << 1 | 1];
	}
}
