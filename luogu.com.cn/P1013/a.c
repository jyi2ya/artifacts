#include <stdio.h>
#include <string.h>

void read(void);
int strequ(const char *a, const char *b);

char table[10][10][10];

int get_zero(void);
int get_one(void);

int N;
int map[255], nu[30], base;

int check(void);

int main(void)
{
	int i, j, now;

	read();

	if (N <= 2) {
		puts("ERROR!");
		return 0;
	}

	base = N - 1;

	nu[0] = get_zero();
	map[nu[0]] = 0;

	nu[1] = get_one();
	map[nu[1]] = 1;

	for (now = 2; now < base; ++now)
		for (i = 0; i < N; ++i)
			for (j = 0; j < N; ++j)
				if (
						table[i][0][0] == nu[now - 1] &&
						table[0][j][0] == nu[1]
				   )
					nu[now] = table[i][j][0], map[nu[now]] = now;

	if (!check()) {
		puts("ERROR!");
		return 0;
	}

	for (i = 1; i <= base; ++i)
		printf("%c=%d ", table[i][0][0], map[(int)table[i][0][0]]);
	putchar('\n');
	printf("%d\n", base);
	return 0;
}

int get_one(void)
{
	register int i, j;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			if (strlen(table[i][j]) > 1)
				return table[i][j][0];
	return '@';
}

int get_zero(void)
{
	register int i, j;
	for (i = 1; i < N; ++i) {
		int ok = 1;
		for (j = 1; j < N; ++j) {
			if (strcmp(table[i][j], table[0][j]) != 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return table[i][0][0];
		}
	}
	return '@';
}

void read(void)
{
	register int i, j;

#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif

	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			scanf("%s", table[i][j]);
}

int strequ(const char *a, const char *b)
{
	return strcmp(a, b) == 0;
}

int str2int(char *str)
{
	int ans = 0;
	while (*str != '\0') {
		ans = ans * base + map[(int)(*str)];
		++str;
	}
	return ans;
}

int check(void)
{
	register int i = 0, j = 0;
	for (i = 1; i < N; ++i)
		for (j = 1; j < N; ++j)
			if (str2int(table[i][0]) + str2int(table[0][j]) !=
					str2int(table[j][i])) {
				return 0;
			}
	return 1;
}
