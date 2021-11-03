#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long ll;

ll a_, b_, p_;

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

ll llgcd(ll a, ll b)
{
	while (b) {
		ll t = a % b;
		a = b;
		b = t;
	}
	return a;
}

#define H_SIZE 1000007

struct h_node {
	ll key;
	ll value;
	struct h_node *next;
};

struct h_node *hash[H_SIZE];
struct h_node pool[3000000], *ptop;

void h_clear(void)
{
	memset(hash, 0, sizeof(hash));
	ptop = pool;
}
struct h_node* h_node_new(ll key, ll value)
{
	struct h_node *t = ptop++;
	t->next = NULL;
	t->key = key;
	t->value = value;
	return t;
}

int h_hash(ll key)
{
	return (int)(key % H_SIZE);
}


struct h_node* h_find(ll key)
{
	struct h_node *i;
	for (i = hash[h_hash(key)]; i != NULL; i = i->next)
		if (i->key == key)
			return i;
	return NULL;
}

void h_insert(ll key, ll value)
{
	struct h_node *n = h_node_new(key, value);
	int idx = h_hash(key);
	n->next = hash[idx];
	hash[idx] = n;
}

/*
 * x^k = y (mod p)
 * returns k
 */
ll bsgs(ll x, ll y, ll p)
{
	ll cnt = 0;
	ll a = 1;
	ll d;
	ll lmt;
	ll i;
	ll c;
	struct h_node *h;
	x %= p, y %= p;
	if (y == 1)
		return 0;
	if (x == 0 && y == 0)
		return 1;
	if (x == 0)
		return -1;
	while ((d = llgcd(x, p)) != 1) {
		if (y % d != 0)
			return -1;
		p /= d;
		y /= d;
		a = a * (x / d) % p;
		++cnt;
		if (a == y)
			return cnt;
	}
	h_clear();
	lmt = (ll)(ceil(sqrt(p))) + 1;
	for (c = 1, i = 0; i <= lmt; ++i, c = c * x % p)
		h_insert(y * c % p, i);
	x = llpow(x, lmt, p);
	for (c = x, i = 1; i <= lmt; ++i, c = c * x % p)
		if ((h = h_find(a * c % p)) != NULL)
			if (i * lmt - h->value + cnt > 0)
				return i * lmt - h->value + cnt;
	return -1;
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	while (scanf("%lld%lld%lld", &a_, &p_, &b_) == 3 && (a_ || b_ || p_)) {
		ll sol = bsgs(a_, b_, p_);
		if (sol == -1)
			puts("No Solution");
		else
			printf("%lld\n", sol);
	}
	return 0;
}
