#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>
#include <string.h>

struct person {
	char name[40];
	char position[40];
	long bg;
	int level;
	int idx;
} person[209];

int n;

#define MAX 2000000000

const char *positions[] = {
	"BangZhu", "FuBangZhu", "HuFa", "ZhangLao",
       	"TangZhu", "JingYing", "BangZhong",
};

int num[] = {
	1, 2, 2, 4, 7, 25, MAX
};

int gt(struct person *a, struct person *b)
{
	int i, j;
	for (i = 0; i < 7; ++i)
		if (strcmp(a->position, positions[i]) == 0)
			break;
	for (j = 0; j < 7; ++j)
		if (strcmp(b->position, positions[j]) == 0)
			break;
	if (i < j)
		return 1;
	if (i > j)
		return 0;
	if (a->level > b->level)
		return 1;
	if (a->level < b->level)
		return 0;
	return a->idx < b->idx;
}

void swap(struct person *a, struct person *b)
{
	struct person t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	int i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s%s%ld%d", person[i].name, person[i].position,
				&person[i].bg, &person[i].level);
		person[i].idx = i;
		if (strcmp(person[i].position, "BangZhu") == 0)
			person[i].bg = MAX;
		if (strcmp(person[i].position, "FuBangZhu") == 0)
			person[i].bg = MAX;
	}

	for (i = 0; i < n; ++i)
		for (j = 1; j < n; ++j)
			if (person[j].bg > person[j - 1].bg)
				swap(&person[j], &person[j - 1]);

	k = 0;
	for (i = 0; i < 7; ++i)
		for (j = 0; j < num[i]; ++j) {
			if (k >= n)
				break;
			else
				strcpy(person[k++].position, positions[i]);
		}

	for (i = 0; i < n; ++i)
		for (j = 1; j < n; ++j)
			if (gt(&person[j], &person[j - 1]))
				swap(&person[j], &person[j - 1]);

	for (i = 0; i < n; ++i)
		printf("%s %s %d\n", person[i].name, person[i].position,
				person[i].level);
	return 0;
}
