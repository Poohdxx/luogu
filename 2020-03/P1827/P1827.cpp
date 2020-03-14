#include <iostream>
#include <string>

using namespace std;

void dfs(const string& pre, const string& mid, int prestart, int preend, int midstart, int midend) {
	if (midstart > midend) return;
	int i = prestart;
	while (pre[i] != mid[midstart]) i++;
	dfs(pre, mid, prestart, i - 1, midstart + 1, midstart + i - prestart);
	dfs(pre, mid, i + 1, preend, midstart + i - prestart + 1, midend);
	cout << mid[midstart];
}

int main()
{
	ios_base::sync_with_stdio(false);
	string mid, pre;
	cin >> pre >> mid;
	int n = mid.size();
	dfs(pre, mid, 0, n - 1, 0, n - 1);
	return 0;
}

