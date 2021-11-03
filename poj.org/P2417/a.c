#include <stdio.h>
#include <math.h>

typedef long long ll;

ll llpow(ll a, ll b, ll mod)
{
	ll ans = 1;
	a %= mod;
	b %= mod;
	while (b) {
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return ans;
}

#define HASH_SIZE 1000009

struct hash_node {
	ll key;
	ll value;
	struct hash_node *next;
};

struct {
	struct hash_node* head[HASH_SIZE];
	struct hash_node pool[4000009];
	struct hash_node* top;
} hash;

struct hash_node* hash_node_new(ll key, ll value)
{
	hash.top->key = key;
	hash.top->value = value;
	hash.top->next = NULL;
	return hash.top++;
}

int hash_hash(ll key)
{
	return key % HASH_SIZE;
}

void hash_clear(void)
{
	int i;
	for (i = 0; i < HASH_SIZE; ++i)
		hash.head[i] = NULL;
	hash.top = hash.pool;
}

void hash_insert(ll key, ll value)
{
	struct hash_node *n = hash_node_new(key, value);
	int idx = hash_hash(key);
	n->next = hash.head[idx];
	hash.head[idx] = n;
}

struct hash_node* hash_find(ll key)
{
	struct hash_node *i;
	for (i = hash.head[hash_hash(key)]; i != NULL; i = i->next)
		if (i->key == key)
			return i;
	return NULL;
}

int main(void)
{
	ll P, B, N;
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	while (scanf("%lld%lld%lld", &P, &B, &N) == 3) {
		int k = (int)ceil(sqrt(P));
		int i;
		ll ans = -1;
		struct hash_node *h;

		hash_clear();
		for (i = 0; i <= k; ++i)
			hash_insert(N * llpow(B, i, P) % P, i);
		for (i = 0; i <= k; ++i)
			if ((h = hash_find(llpow(B, i * k, P))) != NULL)
				if (i * k >= h->value) {
					ans = i * k - h->value;
					break;
				}

		if (ans == -1)
			puts("no solution");
		else
			printf("%lld\n", ans);
	}
	return 0;
}
