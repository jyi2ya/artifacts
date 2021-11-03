#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

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

struct h_node {
	ll key;
	ll val;
	struct h_node *next;
};

#define H_SIZE 1000009
struct h_node *hash[H_SIZE];
struct h_node pool[500000], *ptop;

struct h_node* h_node_new(ll key, ll val)
{
	struct h_node *n = ptop++;
	n->key = key;
	n->val = val;
	n->next = NULL;
	return n;
}

void h_clr(void)
{
	memset(hash, 0, sizeof(hash));
	ptop = pool;
}

int h_hsh(ll key)
{
	return (int)(key % H_SIZE);
}

void h_ins(ll key, ll val)
{
	struct h_node *n = h_node_new(key, val);
	int idx = h_hsh(key);
	n->next = hash[idx];
	hash[idx] = n;
}

struct h_node* h_find(ll key)
{
	struct h_node *i;
	for (i = hash[h_hsh(key)]; i != NULL; i = i->next)
		if (i->key == key)
			return i;
	return NULL;
}

/* x^k = y (mod p) */
ll bsgs(ll x, ll y, ll p)
{
	struct h_node *h;
	ll d;
	ll a;
	ll i;
	ll c;
	ll cnt;
	ll lmt;

	x %= p, y %= p;
	if (y == 1)
		return 0;
	if (x == 0 && y == 0)
		return 1;
	if (x == 0)
		return -1;

	a = 1;
	cnt = 0;
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

	h_clr();
	lmt = (ll)(ceil(sqrt(p))) + 1;
	for (c = 1, i = 0; i <= lmt; ++i, c = c * x % p)
		h_ins(y * c % p, i);
	x = llpow(x, lmt, p);
	for (c = x, i = 1; i <= lmt; ++i, c = c * x % p)
		if ((h = h_find(a * c % p)) != NULL)
			if (i * lmt - h->val + cnt > 0)
				return i * lmt - h->val + cnt;
	return -1;
}

int main(void)
{
	ll x, z, k;
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	while (scanf("%lld%lld%lld", &x, &z, &k) == 3 && (x || z || k)) {
		ll sol = bsgs(x, k, z);
		if (sol == -1)
			puts("No Solution");
		else
			printf("%lld\n", sol);
	}
	return 0;
}
