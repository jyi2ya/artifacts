#include <stdio.h>

#define swap(a__, b__) \
	do { \
		int t_ = a__; \
		a__ = b__; \
		b__ = t_; \
	} while (0)

struct {
	int v[1000009];
	int top;
	int siz;
} H;

#define h_ini() \
	do { \
		H.top = 1; \
		H.siz = 0; \
	} while (0)

#define h_push(x__) \
	do { \
		int x_ = (x__); \
		int p_ = H.top; \
		H.v[H.top++] = x_; \
		while (p_ > 1) { \
			int n_ = p_ / 2; \
			if (H.v[n_] > H.v[p_]) \
				swap(H.v[n_], H.v[p_]); \
			else \
				break; \
			p_ = n_; \
		} \
		++H.siz; \
	} while (0)

#define h_ept() (H.siz == 0)

#define h_top() (H.v[1])

#define h_pop() \
	do { \
		int p_ = 1; \
		--H.top; \
		H.v[1] = H.v[H.top]; \
		while ((p_ << 1) < H.top) { \
			int n_ = p_ << 1; \
			if (n_ + 1 < H.top && H.v[n_ + 1] < H.v[n_]) \
				++n_; \
			if (H.v[n_] < H.v[p_]) \
				swap(H.v[n_], H.v[p_]); \
			else \
				break; \
			p_ = n_; \
		} \
		--H.siz; \
	} while (0)

int main(void)
{
	int n;
	h_ini();
	scanf("%d", &n);
	while (n--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x;
			scanf("%d", &x);
			h_push(x);
		} else if (op == 2) {
			printf("%d\n", h_top());
		} else {
			h_pop();
		}
	}
	return 0;
}
