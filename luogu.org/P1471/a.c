#include <stdio.h>

#define MAX 400009

void init(void);
void add(int l, int r, int c, int a, int b, double u);
double qsum(int l, int r, int c, int a, int b);
double qsqu(int l, int r, int c, int a, int b);

int main(void)
{
	int n, m, i, op, l, r;
	double x;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	init();
	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; ++i) {

		scanf("%lf", &x);
		add(1, n, 1, i, i, x);
	}

	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			scanf("%lf", &x);
			add(1, n, 1, l, r, x);
		} else if (op == 2) {
			printf("%.4f\n", qsum(1, n, 1, l, r) / (r - l + 1));
		} else {
			double sum = qsum(1, n, 1, l, r);
			double ave = sum / (r - l + 1);
			double squ = qsqu(1, n, 1, l, r);
			printf("%.4f\n", (squ + (r - l + 1) * ave * ave -
						2 * ave * sum) / (r - l + 1));
		}
	}
	return 0;
}

double sum[MAX], squ[MAX], addv[MAX];

void init(void)
{
	int i;
	for (i = 0; i < MAX; ++i) {
		sum[i] = 0.0;
		squ[i] = 0.0;
		addv[i] = 0.0;
	}
}

void pd(int l, int r, int c)
{
	int m = l + (r - l) / 2;

	addv[c << 1] += addv[c];
	squ[c << 1] += sum[c << 1] * addv[c] * 2 + (m - l + 1) * addv[c] * addv[c];
	sum[c << 1] += (m - l + 1) * addv[c];

	addv[c << 1 | 1] += addv[c];
	squ[c << 1 | 1] += sum[c << 1 | 1] * addv[c] * 2 + (r - m) * addv[c] * addv[c];
	sum[c << 1 | 1] += (r - m) * addv[c];

	addv[c] = 0;
}

void add(int l, int r, int c, int a, int b, double u)
{
	if (a <= l && r <= b) {
		addv[c] += u;
		squ[c] += sum[c] * u * 2 + (r - l + 1) * u * u;
		sum[c] += (r - l + 1) * u;
	} else {
		int m = l + (r - l) / 2;
		pd(l, r, c);
		if (a <= m)
			add(l, m, c << 1, a, b, u);
		if (m + 1 <= b)
			add(m + 1, r, c << 1 | 1, a, b, u);
		sum[c] = sum[c << 1] + sum[c << 1 | 1];
		squ[c] = squ[c << 1] + squ[c << 1 | 1];
	}
}

double qsum(int l, int r, int c, int a, int b)
{
	double ans = 0;
	if (a <= l && r <= b) {
		ans = sum[c];
	} else {
		int m = l + (r - l) / 2;
		pd(l, r, c);
		if (a <= m)
			ans += qsum(l, m, c << 1, a, b);
		if (m + 1 <= b)
			ans += qsum(m + 1, r, c << 1 | 1, a, b);
	}
	return ans;
}

double qsqu(int l, int r, int c, int a, int b)
{
	double ans = 0;
	if (a <= l && r <= b) {
		ans = squ[c];
	} else {
		int m = l + (r - l) / 2;
		pd(l, r, c);
		if (a <= m)
			ans += qsqu(l, m, c << 1, a, b);
		if (m + 1 <= b)
			ans += qsqu(m + 1, r, c << 1 | 1, a, b);
	}
	return ans;
}
