#if 0
name="a"
gcc -Wall -Werror -Wshadow -O0 -g -fsanitize=address -pg "$name".c -o __"$name" || exit 1
# gcc -Wall -Werror -Wshadow -O0 -g -static -pg -lc_p "$name".c -o __"$name" || exit 1
./__"$name" "$@"
ret=$?
exit $ret
#endif

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) do { \
	int ttt = a; a = b; b = ttt; \
} while (0)

int find_kth(int *arr, int n, int k)
{
	int i, j;
	int t = arr[rand() % n];

	if (k >= n)
		return -1;

	for (i = 0, j = n - 1; i <= j;) {
		while (arr[i] < t)
			++i;
		while (arr[j] > t)
			--j;
		if (i <= j) {
			swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}

	/* < i: >= t
	 * > j: <= t
	 */
	if (j < k && k < i)
		return t;
	if (k <= j)
		return find_kth(arr, j + 1, k);
	return find_kth(arr + i, n - i, k - i);
}

int main(void)
{
	int n, k;
	int i;
	static int a[5000009];
	srand(1926);
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	printf("%d\n", find_kth(a, n, k));
	return 0;
}
