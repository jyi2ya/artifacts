#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int level, value, count, size;
	struct node *son[2], *father;
} node;

int getint(void);

void insert(int x, node **p_current);
void delete(int x, node **p_current);
void rank(int x, node *current);
void kth(int k, node *current);
void pre(int x, node *current);
void post(int x, node *current);

node* newnode(int x);

node *root = NULL;

int main(void)
{
	int T = getint();
	while (T--) {
		int op, x;
		op = getint();
		x = getint();
		switch (op) {
			case 1 : insert(x, &root); break;
			case 2 : delete(x, &root); break;
			case 3 : rank(x, root); break;
			case 4 : kth(x, root); break;
			case 5 : pre(x, root); break;
			case 6 : post(x, root); break;
		}
	}
	return 0;
}

#define current (*p_current)
void rotate(node **p_current, int type)
{
	node *t = current->son[type];
	current->son[type] = t->son[1 ^ type];
	t->son[1 ^ type] = current;
	current = t;
}
void maintain_info(node **p_current)
{
	if (current == NULL)
		return ;

	current->father = NULL;
	current->size = current->count;

	if (current->son[0] != NULL) {
		current->son[0]->father = current;
		current->size += current->son[0]->size;
	}
	if (current->son[1] != NULL) {
		current->son[1]->father = current;
		current->size += current->son[1]->size;
	}
}
void try_to_rotate(node **p_current, int type)
{
	if (
			current->son[type] != NULL &&
			current->level < current->son[type]->level &&
			(
			 current->son[1 ^ type] == NULL ||
			 current->son[1 ^ type]->level < current->son[type]->level
			)
	   ) rotate(&current, type);

	maintain_info(&(current->son[0]));
	maintain_info(&(current->son[1]));
}
void maintain(node **p_current)
{
	if (current == NULL)
		return ;
	try_to_rotate(&current, 0);
	try_to_rotate(&current, 1);

	maintain_info(&current);
}

void insert(int x, node **p_current)
{
	if (current == NULL) {
		current = newnode(x);
	} else if (current->value == x) {
		++current->size;
		++current->count;
	} else {
		if (x < current->value)
			insert(x, &(current->son[0]));
		else
			insert(x, &(current->son[1]));
		maintain(&current);
	}
}

void delete(int x, node **p_current)
{
	if (current == NULL) {
		return ;
	} else if (current->value == x) {
		--current->size;
		--current->count;
		if (current->count <= 0) {
			if (current->son[0] == NULL) {
				current = current->son[1];
			} else if (current->son[1] == NULL) {
				current = current->son[0];
			} else {
				if (current->son[0]->level > current->son[1]->level) {
					rotate(&current, 0);
					delete(x, &(current->son[1]));
				} else if (current->son[1]->level > current->son[0]->level) {
					rotate(&current, 1);
					delete(x, &(current->son[0]));
				}
			}
			maintain(&current);
		}
	} else {
		if (x < current->value)
			delete(x, &(current->son[0]));
		else
			delete(x, &(current->son[1]));
		maintain(&current);
	}
}
#undef current

void rank(int x, node *current)
{
	int ans = 1;
	current = root;
	while (current != NULL) {
		if (x == current->value) {
			if (current->son[0] != NULL)
				ans += current->son[0]->size;
			break;
		} else if (x < current->value) {
			current = current->son[0];
		} else {
			if (current->son[0] != NULL)
				ans += current->son[0]->size;
			ans += current->count;
			current = current->son[1];
		}
	}
	printf("%d\n", ans);
}

void kth(int k, node *current)
{
	current = root;
	while (current != NULL) {
		int left, mid;
		left = (current->son[0] == NULL) ? 0 : current->son[0]->size;
		mid = current->count;
		if (k <= left) {
			current = current->son[0];
		} else if (k <= left + mid) {
			break;
		} else {
			k -= (left + mid);
			current = current->son[1];
		}
	}
	printf("%d\n", current->value);
}

void pre(int x, node *current)
{
	insert(x, &root);
	current = root;
	int ans = -0x7f7f7f7f;
	while (current != NULL) {
		if (x == current->value) {
			break;
		} else if (x < current->value) {
			current = current->son[0];
		} else {
			current = current->son[1];
		}
	}
	if (current->son[0] != NULL) {
		current = current->son[0];
		while (current != NULL) {
			if (ans < current->value && current->value < x)
				ans = current->value;
			current = current->son[1];
		}
	} else {
		while (current != NULL) {
			if (ans < current->value && current->value < x)
				ans = current->value;
			current = current->father;
		}
	}
	printf("%d\n", ans);
	delete(x, &root);
}

void post(int x, node *current)
{
	insert(x, &root);
	current = root;
	int ans = 0x7f7f7f7f;
	while (current != NULL) {
		if (x == current->value) {
			break;
		} else if (x < current->value) {
			current = current->son[0];
		} else {
			current = current->son[1];
		}
	}
	if (current->son[1] != NULL) {
		current = current->son[1];
		while (current != NULL) {
			if (x < current->value && current->value < ans)
				ans = current->value;
			current = current->son[0];
		}
	} else {
		while (current != NULL) {
			if (x < current->value && current->value < ans)
				ans = current->value;
			current = current->father;
		}
	}
	printf("%d\n", ans);
	delete(x, &root);
}

int getint(void)
{
	int r;
	scanf("%d", &r);
	return r;
}

node node_pool[200000];
int node_top = 0;
node* newnode(int x)
{
	node *r = node_pool + node_top;
	++node_top;
	r -> level = rand();
	r -> value = x;
	r -> size = 1;
	r -> count = 1;
	r -> son[0] = NULL;
	r -> son[1] = NULL;
	r -> father = NULL;
	return r;
}
