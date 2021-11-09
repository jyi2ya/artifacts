#include <stdio.h>
#include <string.h>

char n[19];
int nt;
long long dpsum[19][19][19], dpnum[19][19][19], vis[19][19][19];

long long dfs(int pos, int pre, int same, int lmt, int ld, long long *sum);

int main(void)
{
	int i;
	long long a, b, aa, ab;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &a, &b);
	--a;
	sprintf(n, "%lld", a);
	nt = strlen(n);
	for (i = 0; i < nt; ++i)
		n[i] -= '0';
	memset(vis, 0, sizeof(vis));
	dfs(0, -1, 0, 1, 1, &aa);
	sprintf(n, "%lld", b);
	nt = strlen(n);
	for (i = 0; i < nt; ++i)
		n[i] -= '0';
	memset(vis, 0, sizeof(vis));
	dfs(0, -1, 0, 1, 1, &ab);
	printf("%lld\n", ab - aa);
	return 0;
}

long long dfs(int pos, int pre, int same, int lmt, int ld, long long *sum)
{
	int l = (lmt ? n[pos] : 9), i;
	long long rcv, num, ret = 0;

	*sum = 0;
	if (pos == nt) {
		*sum = pre * same * same;
		return 1;
	}

	if (!ld && !lmt && vis[pos][pre][same]) {
		*sum = dpsum[pos][pre][same];
		return dpnum[pos][pre][same];
	}

	for (i = 0; i <= l; ++i) {
		if (i == pre) {
			num = dfs(pos + 1, i, same + 1, (i == l) && lmt, (i == 0) && ld, &rcv);
			ret += num;
			*sum += rcv;
		} else {
			num = dfs(pos + 1, i, 1, (i == l) && lmt, (i == 0) && ld, &rcv);
			ret += num;
			*sum += num * pre * same * same;
			*sum += rcv;
		}
	}

	if (!ld && !lmt) {
		vis[pos][pre][same] = 1;
		dpsum[pos][pre][same] = *sum;
		dpnum[pos][pre][same] = ret;
	}

	return ret;
}
