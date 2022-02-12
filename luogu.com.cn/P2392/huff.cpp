#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int main(void)
{
	int n;
	int tot = 0;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;
		pq.push(t);
		tot += t;
	}

	while (pq.size() > 2) {
		int p = pq.top();
		pq.pop();
		int q = pq.top();
		pq.pop();
		pq.push(p + q);
	}

	int p = pq.top();
	pq.pop();
	int q = pq.top();
	pq.pop();

	int cost = p - q;
	cost = cost < 0 ? -cost : cost;

	cout << (tot + cost) / 2 << endl;

	return 0;
}
