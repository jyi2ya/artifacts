#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARSET_SIZE 26
#define SAM_POOL_SIZE 2000009

struct sam_node;

struct edge {
	int dest;
	int next;
};

struct sam_node {
	int len;
	int size;
	int link;
	int trans[CHARSET_SIZE];
	int child;
};

struct sam {
	struct sam_node v[SAM_POOL_SIZE];
	int vtop;
	struct edge e[3000009];
	int etop;
	int vis[2000008];
	int start;
	int last;
} sam;

void sam_add_edge(int u, int v)
{
	sam.e[sam.etop].dest = v;
	sam.e[sam.etop].next = sam.v[u].child;
	sam.v[u].child = sam.etop++;
}

int sam_node_new(int len, int link)
{
	sam.v[sam.vtop].len = len;
	sam.v[sam.vtop].link = link;
	sam.v[sam.vtop].size = 0;
	sam.v[sam.vtop].child = -1;
	memset(sam.v[sam.vtop].trans, -1, sizeof(int) * CHARSET_SIZE);
	return sam.vtop++;
}

void sam_init(void)
{
	sam.vtop = 0;
	sam.etop = 0;
	memset(sam.vis, 0, sizeof(int) * 2000008);
	sam.start = sam_node_new(0, -1);
	sam.last = sam.start;
}

void sam_append(int ch)
{
	int cur = sam_node_new(sam.v[sam.last].len + 1, -1);
	int p;

	sam.v[cur].size = 1;
	for (p = sam.last; p != -1 && sam.v[p].trans[ch] == -1;
			p = sam.v[p].link)
		sam.v[p].trans[ch] = cur;

	if (p == -1) {
		sam.v[cur].link = sam.start;
	} else {
		int q = sam.v[p].trans[ch];
		if (sam.v[q].len == sam.v[p].len + 1) {
			sam.v[cur].link = q;
		} else {
			int neo = sam_node_new(0, -1);
			memcpy(sam.v + neo, sam.v + q, sizeof(struct sam_node));
			sam.v[neo].len = sam.v[p].len + 1;
			sam.v[neo].size = 0;
			sam.v[cur].link = neo;
			sam.v[q].link = neo;
			for (;p != -1 && sam.v[p].trans[ch] == q;
					p = sam.v[p].link)
				sam.v[p].trans[ch] = neo;
		}
	}

	sam.last = cur;
}

void sam_build(const char *str)
{
	sam_init();
	while (*str)
		sam_append(*str++ - 'a');
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void sam_build_tree(void)
{
	int i;
	for (i = 1; i < sam.vtop; ++i)
		sam_add_edge(sam.v[i].link, i);
}

int sam_dfs_ans(int p)
{
	int ans = 0;
	int i;
	for (i = sam.v[p].child; i != -1; i = sam.e[i].next) {
		ans = max(ans, sam_dfs_ans(sam.e[i].dest));
		sam.v[p].size += sam.v[sam.e[i].dest].size;
	}
	if (sam.v[p].size > 1)
		ans = max(ans, sam.v[p].size * sam.v[p].len);
	return ans;
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	char *buf = (char*)malloc(sizeof(char) * 1000006);
	scanf("%s", buf);
	sam_build(buf);
	free(buf);
	sam_build_tree();
	printf("%d\n", sam_dfs_ans(sam.start));

	return 0;
}
