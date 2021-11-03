#include <stdio.h>

int a[10009], t[10009], N, ansl[50009], ansr[50009], top = 0;

void read(void);
void reverse(int l, int r);
void prt(void);

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int i, j;
		read();
		top = 0;
		for (i = 1; i <= N; ++i) {
			int l = i, r = N;
			if (a[i] == i) continue;
			for (j = i; j <= N; ++j)
				if (a[j] == i)
					break;
			if (((j - i + 1) & 1)) {
				reverse(j - 1, j);
				--j;
			}
			if ((j - i) * 2 + i - 1 > N) {
				reverse(i, j);
				for (j = i; j <= N; ++j)
					if (a[j] == i)
						break;
			}
			reverse(i, (j - i) * 2 + i - 1);
		}
		printf("%d\n", top);
		for (i = 0; i < top; ++i) printf("%d %d\n", ansl[i], ansr[i]);
	}
	return 0;
}

void read(void)
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i) scanf("%d", a + i);
}

void reverse(int l, int r)
{
	int i, j;
	int mid = l + (r - l) / 2;
	if (l == r) return;
	ansl[top] = l; ansr[top] = r; ++top;
	for (i = l; i <= mid; ++i) t[i] = a[i];
	for (i = l, j = mid + 1; i <= mid; ++i, ++j) a[i] = a[j];
	for (i = l, j = mid + 1; i <= mid; ++i, ++j) a[j] = t[i];
}

void prt(void)
{
	int i;
	for (i = 1; i <= N; ++i) printf("%d ", a[i]);
	putchar('\n');
}
