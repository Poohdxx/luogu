#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void dfs(const vector<pair<int, int>>& v, int cur, int d, int& res) {
	if (cur == 0) {
		res = max(res, d-1);
		return;
	}
	dfs(v, v[cur].first, d + 1, res);
	dfs(v, v[cur].second, d + 1, res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n+1);
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		v[i] = { l, r };
	}
	int res = 0;
	dfs(v, 1, 1, res);
	cout << res << endl;
}
