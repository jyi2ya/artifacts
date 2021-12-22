#if 0
name="a"
g++ -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".cpp -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	static int a[100009];
	int mx, mn;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	mx = 0;
	for (int i = 0; i < n; ++i)
		mx += a[i];
	n = unique(a, a + n) - a;
	mn = 0;
	for (int i = 0; i < n; ++i)
		mn += a[i];

	cout << mx << '\n' << mn << '\n';
	return 0;
}
