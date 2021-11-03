/*
 * phi(n) = n (1 - 1/p_1) (1 - 1/p_2) ... (1 - 1/p_k)
 * n = phi(n) (p_1 / (p_1 - 1))(p_2 / (p_2 - 1)) ... (p_k / (p_k - 1))
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"

int is_prime[50009];
int prime[50009];
int top;

int n;
long long ans = -1;

long long llmin(long long a, long long b)
{
	if (a == -1)
		return b;
	return a < b ? a : b;
}

int is_prim(int x)
{
	int i;
	if (x == 2 || x == 3 || x == 5)
		return 1;
	for (i = 0; prime[i] * prime[i] <= x; ++i)
		if (x % prime[i] == 0)
			return 0;
	return 1;
}

void dfs(int pos, long long phi, long long num)
{
	static struct {
		int pos;
		long long phi, num;
		int i;
		long long num_, phi_;
		int pc;
	} ctx[1000009];
	static int ctop = 0;
	static int pc = 0;

#define save(x) ctx[ctop].x = x
#define dfs(pos__, phi__, num__) \
	do { \
		int new_pos__ = pos__; \
		long long new_phi__ = phi__; \
		long long new_num__ = num__; \
		save(pos); save(phi); save(num); \
		save(i); save(num_); save(phi_); \
		ctx[ctop].pc = __LINE__; \
		++ctop; \
		pc = 0; \
		pos = new_pos__; \
		phi = new_phi__; \
		num = new_num__; \
		goto CALL; \
		case __LINE__ : ; \
	} while (0)

#define rest(x) x = ctx[ctop].x
#define return \
	do { \
		if (ctop) { \
			--ctop; \
			rest(pos); rest(phi); rest(num); \
			rest(i); rest(num_); rest(phi_); rest(pc); \
			goto CALL; \
		} else { \
			goto RETURN; \
		} \
	} while (0)

	int i;
	long long num_;
	long long phi_;

CALL:
	switch (pc) {
		case 0:

	if (num == 1) {
		ans = llmin(ans, phi);
		return ;
	}
	if (num > 47009 && is_prim(num + 1)) {
		ans = llmin(ans, phi * (num + 1));
		return ;
	}
	for (i = pos; i < top && (prime[i] - 1) <= num; ++i)
		if (num % (prime[i] - 1) == 0) {
			num_ = num / (prime[i] - 1);
			phi_ = phi * prime[i];
			dfs(i + 1, phi_, num_);
			while (num_ % prime[i] == 0) {
				num_ /= prime[i];
				phi_ *= prime[i];
				dfs(i + 1, phi_, num_);
			}
		}
	default:
		return ;
	}
RETURN:
	;

#undef save
#undef rest
#undef dfs
#undef return
}

int main(void)
{
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	memset(is_prime, 0xcc, sizeof(is_prime));
	is_prime[0] = 0;
	is_prime[1] = 0;
	for (i = 2; i < 50009; ++i)
		if (is_prime[i]) {
			prime[top++] = i;
			for (j = i + i; j < 50009; j += i)
				is_prime[j] = 0;
		}

	scanf("%d", &n);
	dfs(0, 1, n);
	printf("%lld\n", ans);
	return 0;
}
