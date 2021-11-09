#include <stdio.h>
#include <string.h>

char s1[1000009], s2[1000009];
int s2_fail[1000009];
void get_fail(int *fail, const char *str);
void kmp_cmp(const char *str1, const char *str2);

int main(void)
{
	int i;
	scanf("%s%s", s1, s2);
	kmp_cmp(s1, s2);
	for (i = 1; s2[i - 1] != '\0'; ++i)
		printf("%d ", s2_fail[i]);
	putchar('\n');
	return 0;
}

void get_fail(int *fail, const char *str)
{
	int i, j;
	fail[0] = 0;
	j = fail[0];
	for (i = 1; str[i] != '\0'; ++i) {
		while (j != fail[0] && str[i] != str[j])
			j = fail[j];
		if (str[i] == str[j])
			++j;
		fail[i + 1] = j;
	}
}

void kmp_cmp(const char *str1, const char *str2)
{
	int i, j, s2len = strlen(str2);
	get_fail(s2_fail, str2);
	j = 0;
	for (i = 0; str1[i] != '\0'; ++i) {
		while (j != s2_fail[0] && str2[j] != str1[i])
			j = s2_fail[j];
		if (str1[i] == str2[j])
			++j;
		if (str2[j] == '\0')
			printf("%d\n", i - s2len + 2);
	}
}
