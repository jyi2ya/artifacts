#include <stdio.h>
#include <string.h>

#define base 101

unsigned long long hash(const char *s, int l)
{
	unsigned long long val = 0;
	for (int i = 0; i < l; i++)
		val = val * base + s[i] - 'a';
	return val;
}

char str1[32767], str2[32767];

void check(void)
{
	puts((hash(str1, strlen(str1)) == hash(str2, strlen(str2)) &&
		strcmp(str1, str2) != 0) ?  "OK" : "Error");
}

void generate(void)
{
	int i, j;
	int len = 1;
	str1[0] = 'a';
	str2[0] = 'b';
	for (i = 0; i < 12; ++i) {
		for (j = 0; j < len; ++j)
			str1[len + j] = str2[j];
		strcpy(str2, str1);
		len <<= 1;
		for (j = 0; j < len; ++j)
			str2[j] = (str1[j] == 'a' ? 'b' : 'a');
	}
}

int main(void)
{
	generate();
#ifdef DEBUG
	check();
	return 0;
#endif
	printf("%ld %ld\n", strlen(str1) + strlen(str2), strlen(str1));
	printf("%s%s\n", str1, str2);
	return 0;
}
