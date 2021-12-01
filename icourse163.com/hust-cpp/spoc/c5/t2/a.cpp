#if 0
name="a"
g++ -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".cpp -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	int a[5][5];
	int m;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> a[i][j];
	cin >> m;

	for (int i = 0; i < 5; ++i)
		for (int j = i; j < 5; ++j)
			a[i][j] *= m;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << setw(5);
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}
