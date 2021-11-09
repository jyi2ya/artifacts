#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct str {
	char s[128];
	int step;
} str;

void push(str *pthis);
void pop(str *pans);
int is_empty(void);
int que_size(void);

str A, B;
str rule[6][2];
int rule_len[6][2];
int rule_num;

#define HASH_SIZE 2000009
#define QUE_SIZE 100000

str que[QUE_SIZE];
int top, bot;

char tmp[1000];
char vis[HASH_SIZE];

void read(void);
int hash(const char *a);

int main(void)
{
	str now;

	read();
	/*
	int i;
	for (i = 0; i < rule_num; ++i)
		printf("%d:%s %d:%s\n", rule_len[i][0], rule[i][0].s, rule_len[i][1], rule[i][1].s);
		*/

	A.step = 0;
	push(&A);
	vis[hash(A.s)] = 1;
	while (!is_empty()) {
		int rules, start;
		pop(&now);
		if (strcmp(now.s, B.s) == 0 || now.step > 10)
			break;
		++now.step;
		for (rules = 0; rules < rule_num; ++rules)
			for (start = 0; now.s[start] != '\0'; ++start)
				if (strncmp(now.s + start, rule[rules][0].s, rule_len[rules][0]) == 0) {
					int hs;
					str newstr;

					memcpy(&newstr, &now, sizeof(str));
					strcpy(tmp, newstr.s + start + rule_len[rules][0]);
					newstr.s[start] = '\0';
					strcat(newstr.s, rule[rules][1].s);
					strcat(newstr.s, tmp);

					hs = hash(newstr.s);
					if (!vis[hs]) {
						vis[hs] = 1;
						push(&newstr);
					}
				}
	}
	if (strcmp(now.s, B.s) == 0)
		printf("%d\n", now.step);
	else
		puts("NO ANSWER!");

	return 0;
}

void read(void)
{
	int i;
	rule_num = 0;
#ifdef DEBUG
	freopen("testdata.in", "r",stdin);
#endif
	scanf("%s%s", A.s, B.s);
	while (scanf("%s%s", rule[rule_num][0].s, rule[rule_num][1].s) != EOF)
		++rule_num;
	for (i = 0; i < rule_num; ++i) {
		rule_len[i][0] = strlen(rule[i][0].s);
		rule_len[i][1] = strlen(rule[i][1].s);
	}
}

void push(str *pthis)
{
	memcpy(que + top, pthis, sizeof(str));
	++top;
	if (top == QUE_SIZE)
		top = 0;
}
void pop(str *pans)
{
	memcpy(pans, que + bot, sizeof(str));
	++bot;
	if (bot == QUE_SIZE)
		bot = 0;
}
int is_empty(void)
{
	return top == bot;
}

int hash(const char *a)
{
	int ans = 0;
	while (*a != '\0')
		ans = (ans * 256 + *a++) % HASH_SIZE;
	return ans;
}

int que_size(void)
{
	return (top + QUE_SIZE - bot) % QUE_SIZE;
}
