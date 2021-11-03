#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	int i;
	int op;
	static char buf[1009][100009];
	FILE *in;

	in = fopen("in", "r");
	fscanf(in, "%d", &n);
	for (i = 1; i <= n; ++i)
		fscanf(in, "%s", buf[i]);

	for (i = 1; i <= n; ++i)
		printf("%s ", buf[i]);
	putchar('\n');
	scanf("%d", &op);
	while (op--) {
		static char tmp[100009];
		int a, b;
		scanf("%d%d", &a, &b);
		strcpy(tmp, buf[a]);
		strcpy(buf[a], buf[b]);
		strcpy(buf[b], tmp);
		for (i = 1; i <= n; ++i)
			printf("%s ", buf[i]);
		putchar('\n');
	}

	for (i = 1; i <= n; ++i)
		printf("%s\n", buf[i]);

	return 0;
}
