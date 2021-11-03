#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4009

int a[MAX], b[MAX], c[MAX], d[MAX];

int vis(int x);
void ins(int x);
void init(void);
void clear(void);

int main(void)
{
	int T, first = 1;
	scanf("%d",&T);
	init();
	while (T--) {
		int n, i, j;
		long long ans = 0;
		clear();
		scanf("%d",&n);
		for (i = 0; i < n; ++i) 
			scanf("%d%d%d%d",a + i, b + i, c + i, d + i);
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				ins(a[i] + b[j]);
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				ans += vis(-(c[i] + d[j]));
		if (!first) putchar('\n'); else first = 0;
		printf("%lld\n",ans);
	}
	return 0;
}

#define MAX_HASH_NODE 10000009
#define HASH_SIZE 10000003
struct hash_node {
	int num, x;
	struct hash_node* next;
};
typedef struct hash_node hash_node;
hash_node *hash_node_pool, *hash_node_pool_top;
hash_node* hash_set[HASH_SIZE];

hash_node* new_hash_node(int x);
int abs(int x);

int vis(int x)
{
	int idx = abs(x) % HASH_SIZE;
	hash_node* now;
	for (now = hash_set[idx]; now != NULL; now = now -> next)
		if (now -> x == x)
			return now -> num;
	return 0;
}

void ins(int x)
{
	int idx = abs(x) % HASH_SIZE;
	if (hash_set[idx] == NULL) {
		hash_set[idx] = new_hash_node(x);
	} else {
		hash_node* now;
		for (now = hash_set[idx]; now != NULL; now = now -> next)
			if (now -> x == x) {
				++now->num;
				return;
			}
		now = new_hash_node(x);
		now -> next = hash_set[idx] -> next;
		hash_set[idx] -> next = now;
	}
}

void clear(void)
{
	hash_node_pool_top = hash_node_pool;
	memset(hash_set, 0, sizeof(hash_set));
}

void init(void)
{
	hash_node_pool = (hash_node*) malloc(sizeof(hash_node) * MAX_HASH_NODE);
}

hash_node* new_hash_node(int x)
{
	hash_node* r = hash_node_pool_top++;
	r -> next = NULL;
	r -> x = x;
	r -> num = 1;
	return r;
}

int abs(int x)
{
	if (x < 0) return -x;
	return x;
}
