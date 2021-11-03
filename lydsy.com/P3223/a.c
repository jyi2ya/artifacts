#include <stdio.h>
#include <stdlib.h>
#ifndef DEBUG
#define NDEBUG
#endif
#include <assert.h>

typedef struct node {
	int value;
	int size, flip;
	struct node *son[2];
} node;

void splay(node **current, int k);
void split(node **left, node **right, node **src, int k);
void merge(node **dest, node **left, node **right);
void print_tree(node *current);
void build(node **root, int n);
void pushall(node *root);
node* newnode(int value);
void print_answer(node *root);

int main(void)
{
	int n, m, i;
	node *root = newnode(1);
	node *current = root;
	scanf("%d%d", &n, &m);
	for (i = 2; i <= n; ++i) {
		current->son[1] = newnode(i);
		current = current->son[1];
	}
	current = root;
	for (i = n; i >= 1; --i) {
		current->size = i;
		current = current->son[1];
	}
	for (i = 1; i <= n; i += 200)
		splay(&root, i);

	while (m--) {
		int l, r;
		node *left = NULL, *mid = NULL, *right = NULL, *tmp = NULL;
		scanf("%d%d", &l, &r);
		split(&tmp, &right, &root, r);
		split(&left, &mid, &tmp, l - 1);
		mid->flip ^= 1;
		merge(&tmp, &left, &mid);
		merge(&root, &tmp, &right);
	}
	pushall(root);
	print_answer(root);
	putchar('\n');
	return 0;
}

void print_answer(node *root)
{
	if (root == NULL)
		return;
	print_answer(root->son[0]);
	printf("%d ", root->value);
	print_answer(root->son[1]);
}

#define current (*p_current)
void pushdown(node **p_current)
{
	if (current == NULL)
		return;
	if (current->flip) {
		node *t = current->son[0];
		current->son[0] = current->son[1];
		current->son[1] = t;

		if (current->son[0] != NULL)
			current->son[0]->flip ^= 1;
		if (current->son[1] != NULL)
			current->son[1]->flip ^= 1;

		current->flip = 0;
	}
}

void pushall(node *root)
{
	if (root == NULL)
		return;
	pushdown(&root);
	pushall(root->son[0]);
	pushall(root->son[1]);
}
void maintain(node **p_current)
{
	assert(current != NULL);

	current->size = 1;
	if (current->son[0] != NULL)
		current->size += current->son[0]->size;
	if (current->son[1] != NULL)
		current->size += current->son[1]->size;
}

void rotate(node **p_current, int type)
{
	node *t = current->son[type];
	pushdown(&current->son[type]);
	current->son[type] = t->son[type ^ 1];
	t->son[type ^ 1] = current;
	current = t;

	maintain(&current->son[type ^ 1]);
	maintain(&current);
}

void splay(node **p_current, int k)
{
	int son_type, son_type2, left;
	node *current2;

	if (current == NULL)
		return;

	pushdown(&current);
	left = current->son[0] == NULL ? 0 : current->son[0]->size;
	if (k <= left) {
		son_type = 0;
	} else if (k <= left + 1) {
		return;
	} else {
		son_type = 1;
		k -= (left + 1);
	}

	pushdown(&current->son[son_type]);
	current2 = current->son[son_type];
	left = current2->son[0] == NULL ? 0 : current2->son[0]->size;
	if (k <= left) {
		son_type2 = 0;
	} else if (k <= left + 1) {
		rotate(&current, son_type);
		return;
	} else {
		son_type2 = 1;
		k -= (left + 1);
	}

	splay(&current->son[son_type]->son[son_type2], k);

	if (son_type == son_type2) {
		rotate(&current, son_type);
	} else {
		rotate(&current->son[son_type], son_type2);
	}
	rotate(&current, son_type);
}
#undef current

void split(node **left, node **right, node **src, int k)
{
	if (k == 0) {
		*right = *src;
		*left = NULL;
	} else {
		splay(src, k);
		*right = (*src)->son[1];
		(*src)->son[1] = NULL;
		maintain(src);
		*left = *src;
	}
}

void merge(node **dest, node **left, node **right)
{
	if (*right == NULL) {
		*dest = *left;
	} else {
		splay(right, 1);
		(*right)->son[0] = *left;
		maintain(right);
		*dest = *right;
	}
}

node* newnode(int value)
{
	node *ret = (node*)malloc(sizeof(node));
	ret->value = value;
	ret->size = 1;
	ret->flip = 0;
	ret->son[0] = NULL;
	ret->son[1] = NULL;
	return ret;
}

void print_tree(node *current)
{
	static int depth = 0;
	int i;
	if (!depth)
		puts("============== t r e e =================");

	if (current == NULL)
		return;
	++depth;
	print_tree(current->son[0]);
	--depth;
	putchar('|');
	for (i = 0; i < depth; ++i)
		printf(" |");
	printf("-[1;32m%d(%d,%d)[0m\n", current->value, current->size, current->flip);
	++depth;
	print_tree(current->son[1]);
	--depth;
}
