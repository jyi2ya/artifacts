#include <stdio.h>

int stack[1009], stack_top = 0;
int queue[1009], queue_top = 0, queue_bot = 0;
int heap[1009], heap_top = 1, heap_size = 0;

void push_stack(int x);
void push_queue(int x);
void push_heap(int x);

int pop_stack(int *ret);
int pop_queue(int *ret);
int pop_heap(int *ret);

int main(void)
{
	int N;
	while (scanf("%d", &N) == 1) {
		register int i;
		int n, op;
		int is_stack = 1, is_queue = 1, is_heap = 1;
		stack_top = 0;
		queue_top = 0, queue_bot = 0;
		heap_top = 1, heap_size = 0;

		for (i = 0; i < N; ++i) {
			scanf("%d%d", &op, &n);
			if (op == 1) {
				push_stack(n);
				push_queue(n);
				push_heap(n);
			} else {
				int ret;
				if (pop_stack(&ret) || ret != n)
					is_stack = 0;
				if (pop_queue(&ret) || ret != n)
					is_queue = 0;
				if (pop_heap(&ret) || ret != n)
					is_heap = 0;
			}
		}
		if (is_stack + is_queue + is_heap >= 2) {
			puts("not sure");
		} else if (is_stack + is_queue + is_heap == 0) {
			puts("impossible");
		} else if (is_stack) {
			puts("stack");
		} else if (is_queue) {
			puts("queue");
		} else if (is_heap) {
			puts("priority queue");
		}
	}

	return 0;
}

void push_stack(int x)
{
	stack[stack_top++] = x;
}

void push_queue(int x)
{
	queue[queue_top++] = x;
}

void push_heap(int x)
{
	int pos = heap_top;
	heap[heap_top++] = x;
	while (pos > 1) {
		int fa = pos / 2;
		if (heap[pos] > heap[fa]) {
			int t = heap[pos];
			heap[pos] = heap[fa];
			heap[fa] = t;
			pos = fa;
		} else {
			break;
		}
	}
	++heap_size;
}

int pop_stack(int *ret)
{
	if (stack_top == 0)
		return 1;
	*ret = stack[--stack_top];
	return 0;
}

int pop_queue(int *ret)
{
	if (queue_top == queue_bot)
		return 1;
	*ret = queue[queue_bot++];
	return 0;
}

int pop_heap(int *ret)
{
	int pos = 1;

	if (heap_size == 0)
		return 1;

	*ret = heap[pos];

	heap[pos] = 0;
	while (pos * 2 < heap_top) {
		int l = pos * 2, r = pos * 2 + 1;
		if (r < heap_top && heap[r] > heap[l]) {
			int t = heap[r];
			heap[r] = heap[pos];
			heap[pos] = t;
			pos = r;
		} else {
			int t = heap[l];
			heap[l] = heap[pos];
			heap[pos] = t;
			pos = l;
		}
	}
	--heap_size;

	return 0;
}
