#include <stdio.h>
#include <string.h>

int getint(void);
void swap(int *a, int *b);

void init(void);
void ins(void);
void del(void);
void htop(void);
void prt(void);

int main(void) {
	int chs;
	init();
	while (scanf("%d", &chs) == 1) {
		switch (chs) {
			case 1: { ins(); break; }
			case 2: { htop(); break; }
			case 3: { del(); break; }
			default: break;
		}
	}
	return 0;
}

int heap[2000009], top = 1;

void init(void) {
	memset(heap , 0x7f, sizeof(heap));
}

void ins(void) {
	int now = top, x;
	x = getint();
	heap[top++] = x;
	while (now > 1) {
		int cmp = now / 2;
		if (heap[now] < heap[cmp])
			swap(heap + now, heap + cmp);
		now = cmp;
	}
}

void del(void) {
	int now = 1;
	heap[now] = 0x7f7f7f7f;
	while (now * 2 < top) {
		int cmp = now * 2;
		if (cmp + 1 < top && heap[cmp + 1] < heap[cmp])
			++cmp;
		swap(heap + now, heap + cmp);
		now = cmp;
	}
	--top;
	while (heap[top] == 0x7f7f7f7f && top > 1) --top;
	++top;
}

void prt(void) {
	int i;
	for (i = 1; i < top; ++i) printf("%d ", heap[i]);
	putchar('\n');
}

void htop(void) {
	printf("%d\n", heap[1]);
}

int getint(void) {
	int x;
	scanf("%d", &x);
	return x;
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
