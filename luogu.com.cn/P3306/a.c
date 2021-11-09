#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef long long ll;

void llexgcd(ll a, ll b, ll *x, ll *y)
{
	if (b) {
		llexgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	} else {
		*x = 1;
		*y = 0;
	}
}

ll llinv(ll x, ll p)
{
	ll a, b;
	x %= p;
	assert(x > 0);
	assert(p > 0);
	llexgcd(x, p, &a, &b);
	a = (a % p + p) % p;
	assert(a > 0 && a * x % p == 1);
	return a;
}

ll llpow(ll a, ll b, ll p)
{
	ll x = 1;
	a %= p;
	while (b) {
		if (b & 1)
			x = x * a % p;
		a = a * a % p;
		b /= 2;
	}
	return x;
}

typedef struct h_node {
	ll key;
	ll val;
	struct h_node *next;
} h_node;

#define H_SIZE 100009

h_node *hash[H_SIZE];
h_node pool[500009], *ptop;

int h_hsh(ll key)
{
	return (int)(key % H_SIZE);
}

h_node* h_n(ll key, ll val)
{
	h_node* t = ptop++;
	t->key = key;
	t->val = val;
	t->next = NULL;
	return t;
}

void h_clr(void)
{
	memset(hash, 0, sizeof(hash));
	ptop = pool;
}

void h_ins(ll key, ll val)
{
	h_node *n = h_n(key, val);
	int idx = h_hsh(key);
	n->next = hash[idx];
	hash[idx] = n;
}

h_node* h_fnd(ll key)
{
	h_node *i;
	for (i = hash[h_hsh(key)]; i != NULL; i = i->next)
		if (i->key == key)
			return i;
	return NULL;
}

/* x^k = y (mod p) */
ll llbsgs(ll x, ll y, ll p)
{
	ll lmt;
	ll i;
	ll c;
	h_node *h;
	x %= p, y %= p;
	if (y == 1)
		return 0;
	h_clr();
	lmt = (ll)(ceil(sqrt(p))) + 1;
	for (c = 1, i = 0; i <= lmt; ++i, c = c * x % p)
		h_ins(y * c % p, i);
	x = llpow(x, lmt, p);
	for (c = x, i = 1; i <= lmt; ++i, c = c * x % p)
		if ((h = h_fnd(c)) != NULL)
			if (i * lmt - h->val > 0)
				return i * lmt - h->val;
	return -1;
}

int main(void)
{
	int T;
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	scanf("%d", &T);
	while (T--) {
		ll p, a, b, X1, t;
		ll sol;
		scanf("%lld%lld%lld%lld%lld", &p, &a, &b, &X1, &t);
		if (X1 == t) {
			sol = 1;
		} else if (a == 0) {
			if (t == X1)
				sol = 1;
			else
				sol = (b == t ? 2 : -1);
		} else if (a == 1) {
			if (b == 0)
				sol = (X1 == t ? 1 : -1);
			else
				sol = ((t - X1 + p) % p * llinv(b, p) + 1) % p;
			if (sol == 0)
				sol = p;
		} else if ((X1 + b * llinv(a - 1, p)) % p == 0) {
			sol = -1;
		} else {
			sol = llbsgs(a, (t + b * llinv(a - 1, p)) % p *
					llinv(X1 + b * llinv(a - 1, p), p), p);
			if (sol != -1)
				++sol;
		}
		printf("%lld\n", sol);
	}
	return 0;
}
