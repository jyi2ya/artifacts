#include <stdio.h>

struct task {
	int pid, stt, tim, pri;
};

struct {
	struct task v[10000009];
	int top;
	int siz;
} H;

int h_ept(void)
{
	return H.siz == 0;
}

void h_ini(void)
{
	int i;
	H.top = 1;
	H.siz = 0;
	for (i = 0; i < 1000000; ++i)
		H.v[i].stt = 0x3f3f3f3f;
}

struct task h_top(void)
{
	return H.v[1];
}

void h_pop(void)
{
	int p = 1;
	H.v[p].pid = -1;
	H.v[p].pri = 0;
	H.v[p].stt = 0x3f3f3f3f;
	H.v[p].tim = 0;
	while (p * 2 < H.top) {
		int n = p * 2;
		if (n + 1 < H.top && (H.v[n + 1].pri > H.v[n].pri ||
			(H.v[n + 1].pri == H.v[n].pri &&
			H.v[n + 1].stt < H.v[n].stt)))
			++n;
		H.v[p] = H.v[n];
		p = n;
		H.v[p].pid = -1;
		H.v[p].pri = 0;
		H.v[p].stt = 0x3f3f3f3f;
		H.v[p].tim = 0;
	}
	--H.siz;
}

void h_prt(void)
{
	int i;
	for (i = 1; i < H.top; ++i)
		printf("%2d(%d) ", H.v[i].pid, H.v[i].pri);
	putchar('\n');
}

void h_push(struct task x)
{
	struct task t;
	int p = H.top;
	H.v[H.top++] = x;
	while (p > 1) {
		int n = p / 2;
		if (H.v[n].pri < H.v[p].pri || (H.v[n].pri == H.v[p].pri &&
				H.v[n].stt > H.v[p].stt)) {
			t = H.v[n];
			H.v[n] = H.v[p];
			H.v[p] = t;
		} else {
			break;
		}
		p = n;
	}
	++H.siz;
}

int main(void)
{
	struct task t;
	int last = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	h_ini();
	while (scanf("%d%d%d%d", &t.pid, &t.stt, &t.tim, &t.pri) == 4) {
REPICK:
		if (!h_ept()) {
			struct task cur = h_top();
			h_pop();
			cur.tim -= t.stt - last;
			if (cur.tim <= 0)
				printf("%d %d\n", cur.pid, t.stt + cur.tim);
			else
				h_push(cur);
			last = t.stt + cur.tim;
			if (cur.tim < 0)
				goto REPICK;
		}
		h_push(t);
		last = t.stt;
	}

	while (!h_ept()) {
		struct task cur = h_top();
		h_pop();
		last += cur.tim;
		printf("%d %d\n", cur.pid, last);
	}

	return 0;
}
