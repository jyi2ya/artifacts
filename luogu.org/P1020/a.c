#include <stdio.h>
#include <string.h>

int n;
int d[100019], top = 0;
int height[100009];

void read(void);

int main(void)
{
	register int i;

	read();

	d[0] = 0x7fffffff;
	for (i = 0; i < n; ++i) {
		if (height[i] <= d[top]) {
			++top;
			d[top] = height[i];
		} else {
			int l = 0, r = top;
			while (l < r) {
				int mid = l + (r - l) / 2;
				if (height[i] <= d[mid])
					l = mid + 1;
				else
					r = mid;
			}
			d[l] = height[i];
		}
	}
	printf("%d\n", top);

	memset(d, -1, sizeof(d));
	d[0] = -0x7fffffff;

	top = 0;
	for (i = 0; i < n; ++i) {
		if (height[i] > d[top]) {
			++top;
			d[top] = height[i];
		} else {
			int l = 0, r = top;
			while (l < r) {
				int mid = l + (r - l) / 2;
				if (height[i] <= d[mid])
					r = mid;
				else
					l = mid + 1;
			}
			d[l] = height[i];
		}
	}
	printf("%d\n", top);
	return 0;
}

void read(void)
{
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	n = 0;
	while (scanf("%d", height + n) == 1)
		++n;
}
