#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, x, y, c;
	cin >> n >> x >> y >> c;
	int M[10][10] = { 0 };
	while (x != 0 && y != 0 && c != 0) {
		M[x][y] = c;
		cin >> x >> y >> c;
	}

	int dp[10][10][10][10] = { 0 };
	for (int i1 = 1; i1 <= n; i1++) {
		for (int j1 = 1; j1 <= n; j1++) {
			for (int i2 = 1; i2 <= n; i2++) {
				for (int j2 = 1; j2 <= n; j2++) {
					dp[i1][j1][i2][j2] = max({ dp[i1 - 1][j1][i2 - 1][j2], dp[i1 - 1][j1][i2][j2 - 1], dp[i1][j1 - 1][i2 - 1][j2], dp[i1][j1 - 1][i2][j2 - 1] }) + M[i1][j1] + M[i2][j2];
					if (i1 == i2 && j1 == j2) {
						dp[i1][j1][i2][j2] -= M[i1][j1];
					}
				}
			}
		}
	}

	cout << dp[n][n][n][n] << endl;
	return 0;
}
