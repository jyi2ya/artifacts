#include <stdio.h>

void read(void);

int N;
double D1, C, D2;
double D[10], P[10];

int find_next_lower(int current);
int find_after_lowest(int current);

int main(void)
{
	int pos = 0;
	double res = 0.0, ans = 0.0;

	read();
	while (pos < N - 1) {
		int next_pos = find_next_lower(pos);

		if (D[pos + 1] - D[pos] > D2 * C)
			goto FUCK;

		if (next_pos < 0) {
			next_pos = find_after_lowest(pos);
			ans += (C - res) * P[pos]; /* Fill */
			res = C - (D[next_pos] - D[pos]) / D2;
		} else {
			if (res * D2 < (D[next_pos] - D[pos])) {
				ans += ((D[next_pos] - D[pos]) / D2 - res) * P[pos];
				res = 0;
			} else {
				res -= (D[next_pos] - D[pos]) / D2;
			}
		}
		pos = next_pos;
	}
	printf("%.2f\n", ans);
	return 0;
FUCK:
	puts("No Solution");
	return 0;
}

int find_after_lowest(int current)
{
	int i, answer = current + 1;
	for (i = current + 1; i < N && D[i] - D[current] <= C * D2; ++i)
		if (P[i] < P[answer]) {
			answer = i;
		}
	return answer;
}

int find_next_lower(int current)
{
	int i, ans = -1;
	for (i = current; i < N && D[i] - D[current] <= C * D2; ++i)
		if (P[i] < P[current]) {
			ans = i;
			break;
		}
	return ans;
}

void read(void)
{
	register int i;
	double PP;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%lf%lf%lf%lf%d", &D1, &C, &D2, &PP, &N);
	++N;
	D[0] = 0;
	P[0] = PP;
	for (i = 1; i < N; ++i)
		scanf("%lf%lf", D + i, P + i);
	D[N] = D1;
	P[N] = 0;
	++N;
}
