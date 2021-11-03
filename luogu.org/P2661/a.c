#include <stdio.h>

int nxt[200009], vis[200009];
#define check(luotianyi) do { \
	if (vis[(luotianyi)]) \
	goto NEXT; \
	else \
	vis[(luotianyi)] = 1; \
} while (0)

int main(void)
{
	int n, i, min = 0x7f7f7f7f;
	scanf("%d", &n);

	for (i = 1; i <= n; ++i)
		scanf("%d", nxt + i);

	for (i = 1; i <= n; ++i) {
		int pos = nxt[i], fast = nxt[nxt[i]], length = 1;
		check(i);
		while (pos != fast) {
			check(pos);
			pos = nxt[pos];
			fast = nxt[nxt[fast]];
		}
		pos = nxt[pos], length = 1;
		while (pos != fast) {
			vis[pos] = 1;
			++length;
			pos = nxt[pos];
		}
		if (length < min)
			min = length;
NEXT:
		continue;
	}
	printf("%d\n", min);
	return 0;
}
