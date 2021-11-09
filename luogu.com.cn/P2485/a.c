#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll mod;

#define HASH_SIZE 1000009

struct hash_node {
	ll val;
	ll b;
	struct hash_node *next;
};

struct hash_node *hash[HASH_SIZE];

void hash_clear(void)
{
	int i;
	for (i = 0; i < HASH_SIZE; ++i)
		hash[i] = NULL;
}

struct hash_node* hash_node_new(ll val, ll b)
{
	struct hash_node *r = (struct hash_node*)malloc(sizeof(*r));
	r->val = val;
	r->b = b;
	r->next = NULL;
	return r;
}

int hash_hash(ll val)
{
	return (int)(val % HASH_SIZE);
}

struct hash_node* hash_find(ll val)
{
	struct hash_node *i;
	for (i = hash[hash_hash(val)]; i != NULL; i = i->next)
		if (i->val == val)
			return i;
	return NULL;
}

void hash_insert(ll val, ll b)
{
	struct hash_node *n = hash_node_new(val, b);
	int idx = hash_hash(val);
	n->next = hash[idx];
	hash[idx] = n;
}

/*
 * k = a^b
 * returns k
 */
ll llpow(ll a, ll b)
{
	ll ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

ll llinv(ll x)
{
	return llpow(x, mod - 2);
}

/*
 * y^x = z
 * returns x
 */
ll llbsgs(ll y, ll z)
{
	ll a, k, b;
	struct hash_node *h;
	hash_clear();
	k = 100000;
	for (b = 0; b <= k; ++b)
		hash_insert(z * llpow(y, b) % mod, b);
	for (a = 0; a <= k; ++a)
		if ((h = hash_find(llpow(y, a * k))) != NULL)
			if (a * k - h->b >= 0)
				return a * k - h->b;
	return -1;
}

int main(void)
{
	int T;
	int type;
	scanf("%d%d", &T, &type);

	while (T--) {
		ll x, y, z;
		scanf("%lld%lld%lld", &y, &z, &mod);
		if (type == 1) {
			x = llpow(y, z);
		} else if (type == 2) {
			x = llinv(y) * z % mod;
			if (x * y % mod != z % mod)
				x = -1;
		} else {
			x = llbsgs(y, z);
			if (x == -1 || llpow(y, x) != z % mod)
				x = -1;
		}

		if (x == -1)
			puts("Orz, I cannot find x!");
		else
			printf("%lld\n", x);
	}

	return 0;
}
