#include <stdio.h>

#define MAX 500009

int arr[MAX], que[MAX];

int main(void)
{
	int N, M, i, l = 0, r = 0, ans = -0x7f7f7f7f;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; ++i) scanf("%d", arr + i);
	for (i = 1; i < N; ++i) arr[i] = arr[i - 1] + arr[i];
	for (i = 0; i < N; ++i) {
		if (arr[i] - arr[que[l]] > ans) ans = arr[i] - arr[que[l]];
		while (que[l] <= i - M  && l < r) ++l;
		while (arr[que[r - 1]] > arr[i] && r > l) --r;
		que[r++] = i;
	}
	printf("%d\n", ans);
	return 0;
}
