#include <stdio.h>

int l[30], r[30], t[30], top = 1;

int count_son(int root);
void print_tree(int root);

int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		char buf[4];
		scanf("%s", buf);
		l[buf[0] - 'a' + 1] = (buf[1] == '*') ? 0 : buf[1] - 'a' + 1;
		r[buf[0] - 'a' + 1] = (buf[2] == '*') ? 0 : buf[2] - 'a' + 1;

	}
	for (i = 1; i <= 26; ++i)
		if (count_son(i) == n)
			break;
	print_tree(i);
	return 0;
}

void print_tree(int root)
{
	if (!root)
		return;
	putchar(root + 'a' - 1);
	print_tree(l[root]);
	print_tree(r[root]);
}

int count_son(int root)
{
	int ans = 1;
	if (!root)
		return 0;
	ans += count_son(l[root]);
	ans += count_son(r[root]);
	return ans;
}
