#include <stdio.h>

int cnt_l[100], cnt_r[100];

int main(void)
{
	int i;
	int l, r;
	int ans = 0;

	scanf("%d%d", &l, &r);
	for (i = 0; i < l; ++i) {
		int t;
		scanf("%d", &t);
		++cnt_l[t];
	}
	for (i = 0; i < r; ++i) {
		int t;
		scanf("%d", &t);
		++cnt_r[t];
	}
	for (i = 0; i < 100; ++i)
		while (cnt_l[i] && cnt_r[i]) {
			++ans;
			--cnt_l[i];
			--cnt_r[i];
		}
	printf("%d\n", ans);
	return 0;
}
