#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> helper(const vector<pair<int, int>>& v, int start, int end) {
	if (start == end) {
		return v[start];
	}
	int mid = (start + end) / 2;
	return max(helper(v, start, mid), helper(v, mid + 1, end));
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < (1 << n); i++) {
		int t;
		cin >> t;
		v.emplace_back(t, i+1);
	}
	const int m = v.size();
	auto t1 = helper(v, 0, m / 2 - 1);
	auto t2 = helper(v, m / 2, m - 1);
	cout << min(t1, t2).second << endl;
	return 0;
}

