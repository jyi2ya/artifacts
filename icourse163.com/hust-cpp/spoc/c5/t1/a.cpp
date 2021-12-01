#if 0
name="a"
g++ -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".cpp -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector <pair<double, int> > a;
	double avg;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	avg = 0;
	for (int i = 0; i < 10; ++i) {
		int t;
		cin >> t;
		a.push_back(make_pair(0, t));
		avg += t;
	}
	avg /= 10;

	for (auto i = a.begin(); i != a.end(); ++i)
		i->first = fabs(i->second - avg);

	sort(a.begin(), a.end());
	if (a[0].first == a[1].first)
		cout << a[0].second << "\n" << a[1].second << "\n";
	else
		cout << a[0].second << "\n";
	return 0;
}
