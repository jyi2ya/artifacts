#include <stdio.h>

long long gans;
long long cnt;

int stk1[5000009], stk2[5000009];
int tp1, tp2;

void init(void)
{
	cnt = 1;
	gans = 0;
	tp1 = tp2 = 0;
}

void PUSH(int x)
{
	stk1[tp1++] = x;
	if (tp2 == 0 || x >= stk2[tp2 - 1])
		stk2[tp2++] = x;
	gans ^= cnt * stk2[tp2 - 1];
	++cnt;
}

void POP(void)
{
	if (tp1 > 0) {
		--tp1;
		if (tp1 > 0) {
			if (stk2[tp2 - 1] == stk1[tp1])
				--tp2;
			gans ^= cnt * stk2[tp2 - 1];
		} else {
			tp2 = 0;
		}
	}
	++cnt;
}

int n, p, q, m;
unsigned int SA, SB, SC;
unsigned int rng61(void)
{
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA; SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}

void gen(void)
{
	scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
	for(int i = 1; i <= n; i++) {
		if(rng61() % (p + q) < (unsigned int)p)
			PUSH(rng61() % m + 1);
		else
			POP();
	}
}

int main(void)
{
	int T;
	int i;
	scanf("%d", &T);
	for (i = 1; i <= T; ++i) {
		init();
		gen();
		printf("Case #%d: %lld\n", i, gans);
	}
	return 0;
}

