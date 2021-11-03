#include <stdio.h>
#include <string.h>

#define MAX 200009

char S[MAX], T[MAX], map[64];

int main(void)
{
	int i, j, ok = 1;
	scanf("%s%s", S, T);

	memset(map, -1, sizeof(map));
	for (i = 0; i < 27; ++i) map[i] = i + 'a';
	for (i = 0; S[i] != '\0'; ++i) {
		if (S[i] != T[i]) map[S[i] - 'a'] = T[i];

		int j;
		for (j = 0; S[j] != '\0'; ++j) putchar(map[S[j] - 'a']);
		putchar('\n');
	}
	for (i = 0; S[i] != '\0'; ++i)
		if (map[S[i] - 'a'] != T[i])
			ok = 0;

	if (ok) puts("Yes");
	else puts("No");
	return 0;
}
