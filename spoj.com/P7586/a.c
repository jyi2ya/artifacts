#include <stdio.h>

char S2[3009], S[1009];
int N[3009];

int palindrome(char *S);
int min(int a, int b);

int main(void)
{
	int t, i, ans = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%s", S);
	t = palindrome(S);

	for (i = 0; i < t; ++i) {
		if ((N[i] - 1) & 1)
			ans += (N[i] + 1) / 2;
		else
			ans += N[i] / 2;
	}
	printf("%d\n", ans);

	return 0;
}

int palindrome(char *S)
{
	int i, m, r, t = 0, j;
	S2[t++] = '`';
	while (*S != '\0') {
		S2[t++] = *S++;
		S2[t++] = '`';
	}
	S2[t++] = '\0';
	N[0] = 1;
	m = 0;
	r = 0;
	for (i = 1; i < t; ++i) {
		for (
				j = (i > r ? 1 : min(N[m * 2 - i], r - i));
				i - j >= 0 && S2[i - j] == S2[i + j];
				++j
		    );
		N[i] = j;
		if (i + j > r) {
			m = i;
			r = i + j;
		}
	}
	return t;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
