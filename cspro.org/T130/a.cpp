#if 0
name="a"
g++ -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".cpp -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int> > low, high;
	int n;
	static int a[500009];
	int mx = 1;
	int num = 1;
	int fail = 1;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 0)
			fail = 0;
		++a[i];
	}
	a[0] = 0;
	a[n + 1] = 0;
	n += 2;
	n = unique(a, a + n) - a;

	for (int i = 1; i < n - 1; ++i) {
		if (a[i - 1] < a[i] && a[i] > a[i + 1])
			high.push(a[i]);
		if (a[i - 1] > a[i] && a[i] < a[i + 1])
			low.push(a[i]);
	}

	mx = num;
	while (!low.empty()) {
		int top, cnt = 0;
		top = low.top();
		for (cnt = 0; !low.empty() && low.top() == top; ++cnt)
			low.pop();
		num += cnt;
		for (cnt = 0; !high.empty() && high.top() <= top; ++cnt)
			high.pop();
		num -= cnt;

		mx = max(mx, num);
	}

	if (fail)
		cout << '0' << endl;
	else
		cout << mx << endl;

	return 0;
}
