#include <stdio.h>

int sg[200009 << 2], xorv[200009 << 2];

void modify(int l, int r, int c, int ml, int mr);
int query(int l, int r, int c, int ql, int qr);

int main(void)
{
	int n, m, p, l, r;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &p, &l, &r);
		if (p == 0)
			modify(1, n, 1, l, r);
		else
			printf("%d\n", query(1, n, 1, l, r));
	}
	return 0;
}

void modify(int l, int r, int c, int ml, int mr)
{
	if (ml <= l && r <= mr) {
		xorv[c] ^= 1;
		sg[c] = r - l + 1 - sg[c];
	} else {
		int mid = l + (r - l) / 2;
		if (xorv[c]) {
			xorv[c << 1] ^= 1;
			sg[c << 1] = mid - l + 1 - sg[c << 1];
			xorv[c << 1 | 1] ^= 1;
			sg[c << 1 | 1] = r - mid - sg[c << 1 | 1];

			xorv[c] = 0;
		}
		if (ml <= mid)
			modify(l, mid, c << 1, ml, mr);
		if (mid + 1 <= mr)
			modify(mid + 1, r, c << 1 | 1, ml, mr);

		sg[c] = 0;
		sg[c] = sg[c << 1] + sg[c << 1 | 1];
	}
}

int query(int l, int r, int c, int ql, int qr)
{
	int ans = 0;
	if (ql <= l && r <= qr) {
		ans = sg[c];
	} else {
		int mid = l + (r - l) / 2;
		if (xorv[c]) {
			xorv[c << 1] ^= 1;
			sg[c << 1] = mid - l + 1 - sg[c << 1];
			xorv[c << 1 | 1] ^= 1;
			sg[c << 1 | 1] = r - mid - sg[c << 1 | 1];

			xorv[c] = 0;
		}
		if (ql <= mid)
			ans += query(l, mid, c << 1, ql, qr);
		if (mid + 1 <= qr)
			ans += query(mid + 1, r, c << 1 | 1, ql, qr);
	}
	return ans;
}
