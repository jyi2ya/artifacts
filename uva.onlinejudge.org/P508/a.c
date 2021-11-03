#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char morse_table[128][16]
, word_base[209][16]
, word_morse[209][1024]
, morse_code[1009][128]
, *word[209];

int diff[209], wordnum, codenum;

void read(void);
void init(void);
void pretreat(void);
void solve(void);

int main(void)
{
	init();
	read();
	pretreat();
	solve();
	return 0;
}

int get_diff(char* morse, char* word);

void solve(void)
{
	int i, j;
	for (i = 0; i < codenum; ++i) {
		int ans = 0, cnt = 1;
		for (j = 0; j < wordnum; ++j)
			diff[j] = get_diff(morse_code[i], word_morse[j]);
		for (j = 1; j < wordnum; ++j) {
			if (diff[ans] == diff[j]) ++cnt;
			if (diff[ans] < 0 || (diff[j] < diff[ans] && diff[j] >= 0)) {
				ans = j;
				cnt = 1;
			}
		}

		printf(word[ans]);

		if (diff[ans] == 0 && cnt > 1) putchar('!');
		if (diff[ans] > 0) putchar('?');
		putchar('\n');
	}
}

int get_diff(char* morse, char* word)
{
	int ans;
	while (*morse != '\0' && *word != '\0') {
		if (*morse != *word) return -2147483647;
		++morse, ++word;
	}
	ans = strlen(word) - strlen(morse);
	if (ans < 0) ans = -ans;
	return ans;
}

/* init {{{ */
void init(void)
{
	int i;
	for (i = 0; i < 209; ++i) word[i] = word_base[i];
	for (i = 0; i < 209; ++i) *word_morse[i] = '\0';
}
/* }}} */

/* pretreat {{{ */
int cmp(const void* a, const void *b)
{
	return strcmp(*(char**)a, *(char**)b);
}

void pretreat(void)
{
	int i;
	qsort(word, wordnum, sizeof(char*), cmp);
	for (i = 0; i < wordnum; ++i) {
		char *s = word[i];
		while (*s != '\0') {
			strcat(word_morse[i], morse_table[(int)*s]);
			++s;
		}
	}
}
/* }}} */

/* read {{{ */
void read(void)
{
	char buf[1024];
	while (
			scanf("%s", buf) == 1 
			&& buf[0] != '*'
	      ) scanf("%s", morse_table[(int)buf[0]]);
	wordnum = 0;
	while (
			scanf("%s", word[wordnum]) == 1 
			&& word[wordnum][0] != '*'
	      ) ++wordnum;
	codenum = 0;
	while (
			scanf("%s", morse_code[codenum]) == 1 
			&& morse_code[codenum][0] != '*'
	      ) ++codenum;
}
/* }}} */
