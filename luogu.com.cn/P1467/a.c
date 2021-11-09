#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 9

unsigned long use = 0;
char ans[20];
int num;

int check(void)
{
	int i;
	int width;
	int num_start;
	int tot = 0;
	int pos;
	unsigned long vis = 0;

	if (atoi(ans) <= num)
		return 0;
	for (i = 0; i < MAX_WIDTH && ans[i] == '0'; ++i);
	num_start = i;
	width = MAX_WIDTH - i;
	for (; i < MAX_WIDTH && ans[i] != '0'; ++i);
	if (ans[i] == '0')
		return 0;
	for (i = 0; i < MAX_WIDTH; ++i)
		tot += ans[i] - '0';
	if (tot % width != 0)
		return 0;

	pos = 0;
	for (i = 0; i < width; ++i) {
		if ((vis >> pos) & 1U)
			return 0;
		vis |= (1U << pos);
		pos = (pos + ans[pos + num_start] - '0') % width;
	}

	return pos == 0;
}

int dfs(int pos)
{
	int i;
	if (pos == MAX_WIDTH)
		return check();
	for (i = 0; i <= 9; ++i)
		if (!i || !((use >> i) & 1U)) {
			use |= (1U << i);
			ans[pos] = i + '0';
			if (dfs(pos + 1))
				return 1;
			use &= (~(1U << i));
		}
	return 0;
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &num);
	dfs(0);
	printf("%d\n", atoi(ans));
	return 0;
}
