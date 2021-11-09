#include <stdio.h>
#include <string.h>

#define MAX 1000009
#define MOD 100003

typedef struct edge {
	int t, n;
} edge;
edge E[3000009];
int Etop = MAX;
void adeg(int f, int t);

int D[MAX], V[MAX], Q[MAX << 2], Qtop, Qbot, N[MAX];

int main(void)
{
	int n, m, x, y, c, i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		adeg(x, y);
		adeg(y, x);
	}
	memset(D, 0x7f, sizeof(D));
	Qtop = 0;
	Qbot = 0;
	Q[Qtop++] = 1;
	D[1] = 0;
	while (Qtop != Qbot) {
		c = Q[Qbot++];
		V[c] = 0;
		for (i = E[c].n; i; i = E[i].n)
			if (D[E[i].t] > D[c] + 1 && !V[E[i].t]) {
				V[E[i].t] = 1;
				D[E[i].t] = D[c] + 1;
				Q[Qtop++] = E[i].t;
			}
	}
	memset(V, 0, sizeof(V));
	Qtop = 0;
	Qbot = 0;
	Q[Qtop++] = 1;
	N[1] = 1;
	while (Qtop != Qbot) {
		c = Q[Qbot++];
		if (V[c])
			continue;
		V[c] = 1;
		for (i = E[c].n; i; i = E[i].n) {
			if (D[E[i].t] == D[c] + 1)
				N[E[i].t] = (N[E[i].t] + N[c]) % MOD;
			Q[Qtop++] = E[i].t;
		}
	}
	for (i = 1; i <= n; ++i)
		printf("%d\n", N[i]);
	return 0;
}

void adeg(int f, int t)
{
	E[Etop].t = t;
	E[Etop].n = E[f].n;
	E[f].n = Etop++;
}
