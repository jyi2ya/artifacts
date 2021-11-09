#include <stdio.h>

long long stk[200009], pos[200009];
char buf[3];

int main(void)
{
	long long M, D, x, ans, t = 0;
	int top = 0, cnt = 0, l, r, mid;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &M, &D);
	while (M--) {
		scanf("%s%lld", buf, &x);
		if (buf[0] == 'Q') {
			ans = 0;
			l = 0, r = top - 1;
			while (l < r) {
				mid = l + (r - l) / 2;
				if (cnt - pos[mid] <= x)
					r = mid;
				else
					l = mid + 1;
			}

			ans = stk[l];
			printf("%lld\n", ans);
			t = ans;
		} else {
			x = (x + t) % D;
			if (top) {
				--top;
				while (stk[top] <= x && top >= 0)
					--top;
				++top;
			}
			stk[top] = x;
			pos[top++] = cnt++;
		}
	}
	return 0;
}
