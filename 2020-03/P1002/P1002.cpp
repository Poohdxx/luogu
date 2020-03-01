#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int m, n, x, y;
	cin >> m >> n >> x >> y;
	auto dp = vector<vector<int64_t>>(m+1, vector<int64_t>(n+1, 0));
	int dir[9][2] = {{0,0},{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
	for (auto d : dir) {
		if (x+d[0] >= 0 && x+d[0] <= m && y+d[1] >= 0 && y+d[1] <= n) {
			dp[x+d[0]][y+d[1]] = -1;
		}
	}
	if (dp[0][0] == -1 || dp[m][n] == -1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
				continue;
			}
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
			}
			else {
				int64_t up = (i == 0 ? 0 : dp[i - 1][j]);
				int64_t lt = (j == 0 ? 0 : dp[i][j - 1]);
				dp[i][j] = up + lt;
			}
		}
	}

	cout << dp[m][n] << endl;
	return 0;
}