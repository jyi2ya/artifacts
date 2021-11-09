/*
ID:lindong6
PROG:crypt1
LANG:C
*/

#include <stdio.h>

#define ff(x) for(x = 0; x < N; ++x)
#define check(x) while (x) { \
	if (!ok[x % 10]) { \
		yes = 0; \
		break; \
	} else { \
		x /= 10; \
	} \
}


int N;
int arr[109];

int ok[10];

int main(void)
{
	register int a, b, c, d, e;
	int ans = 0;

	scanf("%d", &N);
	for (a = 0; a < N; ++a) {
		scanf("%d", arr + a);
		ok[arr[a]] = 1;
	}


	ff(a) 
		ff(b)
		ff(c)
		ff(d)
		ff(e) {
			int now = (arr[a] * 100 + arr[b] * 10 +arr[c]) *
				(arr[d] * 10 + arr[e])
				,part1 = (arr[a] * 100 + arr[b] * 10 + arr[c]) *
				arr[d]
				,part2 = (arr[a] * 100 + arr[b] * 10 + arr[c]) *
				arr[e],
				yes = 1;

				if (arr[a] == 0 || arr[d] == 0 ||
						now >= 10000 || now < 1000 ||
						part1 >= 1000 || part1 < 100 ||
						part2 >= 1000 || part2 < 100)
					continue;

				check(now);
				check(part1);
				check(part2);

				if (yes)
					++ans;
		}
#undef ff

	printf("%d\n", ans);

	return 0;
}
