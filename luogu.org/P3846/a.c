#include <stdio.h>
#include <math.h>

typedef long long ll;

ll llpow(ll a, ll b, ll p)
{
	ll x = 1;
	while (b) {
		if (b & 1)
			x = x * a % p;
		a = a * a % p;
		b /= 2;
	}
	return x;
}

#define H_S 1000009

typedef struct h_n {
	ll k;
	ll v;
	struct h_n *n;
} h_n;

h_n *H[H_S];

int h_hsh(ll k)
{
	return k % H_S;
}

h_n* h_new(ll k, ll v)
{
	static h_n p[1000009], *t = p;
	t->k = k;
	t->v = v;
	t->n = NULL;
	return t++;
}

void h_ins(ll k, ll v)
{
	h_n *n = h_new(k, v);
	int i = h_hsh(k);
	n->n = H[i];
	H[i] = n;
}

h_n* h_fid(ll k)
{
	h_n *i;
	for (i = H[h_hsh(k)]; i; i = i->n)
		if (i->k == k)
			return i;
	return NULL;
}

int main(void)
{
	ll P, B, N;
	int k;
	int i;
	ll a = -1;
	h_n *h;
	scanf("%lld%lld%lld", &P, &B, &N);
	k = (int)ceil(sqrt(P));
	for (i = 0; i <= k; ++i)
		h_ins(N * llpow(B, i, P) % P, i);
	for (i = 0; i <= k; ++i)
		if ((h = h_fid(llpow(B, i * k, P))) != NULL)
			if (i * k >= h->v) {
				a = i * k - h->v;
				break;
			}
	if (a == -1)
		puts("no solution");
	else
		printf("%lld\n", a);
	return 0;
}
