#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
	int value, count, size;
	struct node *son[2];
} node;

void insert(node **p_current, int value);
void delete(node **p_current, int value);
int rank(node *current, int value);
int kth(node *current, int k);
int pre(node *current, int value);
int post(node *current, int value);

void splay(node **p_current, int k);

node *root;

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int op, x;
		scanf("%d%d", &op, &x);
		switch (op) {
			case 1 : insert(&root, x); rank(root, x); break;
			case 2 : delete(&root, x); break;
			case 3 : printf("%d\n", rank(root, x)); break;
			case 4 : printf("%d\n", kth(root, x)); break;
			case 5 : printf("%d\n", pre(root, x)); break;
			case 6 : printf("%d\n", post(root, x)); break;
		}
	}
	return 0;
}

#define current (*p_current)
node* newnode(int value)
{
	node *ret = (node*)malloc(sizeof(node));
	ret->size = 1;
	ret->value = value;
	ret->count = 1;
	ret->son[0] = NULL;
	ret->son[1] = NULL;
	return ret;
}

void maintain(node **p_current)
{
	assert(current != NULL);

	current->size = current->count;
	if (current->son[0] != NULL)
		current->size += current->son[0]->size;
	if (current->son[1] != NULL)
		current->size += current->son[1]->size;
}

void rotate(node **p_current, int type)
{
	assert(current != NULL);

	node *t = current->son[type];
	current->son[type] = t->son[type ^ 1];
	t->son[type ^ 1] = current;
	current = t;

	maintain(&current->son[type ^ 1]);
	maintain(&current);
}

/* pull kth element to root */
void splay(node **p_current, int k)
{
	int left = current->son[0] == NULL ? 0 : current->son[0]->size,
	    mid = current->count;
	int sontype, next_sontype;
	node *next_current;

	if (current == NULL)
		return;

	if (k <= left) {
		sontype = 0;
	} else if (k <= left + mid) {
		return;
	} else {
		sontype = 1;
		k -= (left + mid);
	}

	next_current = current->son[sontype];
	left = next_current->son[0] == NULL ? 0 : next_current->son[0]->size;
	mid = next_current->count;
	if (k <= left) {
		next_sontype = 0;
	} else if (k <= left + mid) {
		rotate(&current, sontype);
		return;
	} else {
		next_sontype = 1;
		k -= (left + mid);
	}

	splay(&(next_current->son[next_sontype]), k);
	if (sontype == next_sontype) {
		rotate(&current, sontype);
	} else {
		rotate(&current->son[sontype], next_sontype);
	}

	rotate(&current, sontype);
}

void split(node **left, node **right, node **src, int k)
{
	splay(src, k);
	*left = *src;
	*right = (*src)->son[1];
	(*src)->son[1] = NULL;
	maintain(src);
}

void merge(node **dest, node **left, node **right)
{
	if (right == NULL) {
		*dest = *left;
	} else {
		splay(right, 1);
		(*right)->son[0] = *left;
		maintain(right);
		*dest = *right;
	}
}

void insert(node **p_current, int value)
{
	if (current == NULL) {
		current = newnode(value);
	} else if (current->value == value) {
		++current->size;
		++current->count;
	} else {
		if (value < current->value)
			insert(&current->son[0], value);
		else
			insert(&current->son[1], value);
		maintain(&current);
	}
}

void delete(node **p_current, int value)
{
	rank(root, value);
	--current->size;
	--current->count;
	if (current->count <= 0) {
		if (current->son[0] == NULL) {
			current = current->son[1];
		} else if (current->son[1] == NULL) {
			current = current->son[0];
		} else {
			splay(&current->son[1], 1);
			current->son[1]->son[0] = current->son[0];
			current->son[0] = NULL;
			maintain(&current->son[1]);
			current = current->son[1];
			maintain(&current);
		}
	}
}

#undef current
int rank(node *current, int value)
{
	int ans = 1;
	if (current == NULL)
		return 0;
	while (current != NULL) {
		if (value == current->value) {
			if (current->son[0] != NULL)
				ans += current->son[0]->size;
			break;
		} else if (value < current->value) {
			current = current->son[0];
		} else {
			if (current->son[0] != NULL)
				ans += current->son[0]->size;
			ans += current->count;
			current = current->son[1];
		}
	}
	splay(&root, ans);
	return ans;
}

int kth(node *current, int k)
{
	splay(&root, k);
	return root->value;
}

int pre(node *current, int value)
{
	int ans;
	insert(&root, value);
	rank(root, value);
	current = root->son[0];
	while (current != NULL) {
		ans = current->value;
		current = current->son[1];
	}
	delete(&root, value);
	return ans;
}

int post(node *current, int value)
{
	int ans;
	insert(&root, value);
	rank(root, value);
	current = root->son[1];
	while (current != NULL) {
		ans = current->value;
		current = current->son[0];
	}
	delete(&root, value);
	return ans;
}
