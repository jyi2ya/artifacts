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
#include <string>
#include <utility>
#include <vector>
#include <functional>
using namespace std;

int main(void)
{
	vector<pair<int, string> > a;

	vector<int>();

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (auto i = 0; i < 6; ++i) {
		string t;
		cin >> t;
		a.push_back(make_pair(t.length(), t));
	}

	sort(a.begin(), a.end(), greater<pair<int, string> >());

	for (auto i : a)
		cout << i.second << "\n";
	return 0;
}
