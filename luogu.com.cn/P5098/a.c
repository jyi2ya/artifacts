#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main_(void)
{
	int n;
	int x, y;
	int xmax = 0, xmin = INT_MAX, ymax = 0, ymin = INT_MAX;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &x, &y);
		xmax = max(xmax, x + y);
		xmin = min(xmin, x + y);
		ymax = max(ymax, x - y);
		ymin = min(ymin, x - y);
	}
	printf("%d\n", max(xmax - xmin, ymax - ymin));
	return 0;
}

int start_(void)
{
	return main_();
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	start_();

#ifdef DEBUG
	fclose(stdin);
#endif
	
	return 0;
}
