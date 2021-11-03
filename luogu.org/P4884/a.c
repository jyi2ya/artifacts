#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

ll llmul(ll a, ll b, ll p)
{
	ll x = 0;
	while (b) {
		if (b & 1)
			x = (x + a) % p;
		a = (a + a) % p;
		b /= 2;
	}
	return x;
}

typedef struct h_n {
	ll key;
	ll val;
	struct h_n *next;
} h_n;

h_n* h_n_new(ll key, ll val)
{
	static h_n pool[2000009], *t = pool;
	t->key = key;
	t->val = val;
	t->next = NULL;
	return t++;
}

#define H_SIZE 1000009

h_n *hash[H_SIZE];

int h_hsh(ll key)
{
	return (int)(key % H_SIZE);
}

void h_ins(ll key, ll val)
{
	h_n *n = h_n_new(key, val);
	int idx = h_hsh(key);
	n->next = hash[idx];
	hash[idx] = n;
}

h_n* h_fnd(ll key)
{
	h_n *i;
	for (i = hash[h_hsh(key)]; i != NULL; i = i->next)
		if (i->key == key)
			return i;
	return NULL;
}

int main(void)
{
	ll k, m;
	ll lmt;
	ll i;
	ll c;
	ll x;
	ll ans = -1;
	h_n *h;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &k, &m);
	k = (llmul(k, 9, m) + 1) % m;
	lmt = (ll)ceil(sqrt(m)) + 1;
	for (c = 1, i = 0; i <= lmt; ++i, c = llmul(c, 10, m))
		h_ins(llmul(k, c, m), i);
	for (x = 1, i = 0; i < lmt; ++i, x = llmul(x, 10, m));
	for (c = x, i = 1; i <= lmt; ++i, c = llmul(c, x, m))
		if ((h = h_fnd(c)) != NULL)
			if (i * lmt - h->val > 0) {
				ans = i * lmt - h->val;
				break;
			}
	printf("%lld\n", ans);
	return 0;
}
