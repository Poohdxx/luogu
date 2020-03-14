#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	multiset<int> st;
	for (int i = 0; i < q; i++) {
		int f, x;
		cin >> f >> x;
		if (f == 1) {
			cout << distance(st.begin(), st.lower_bound(x)) + 1 << endl;
		}
		else if (f == 2) {
			cout << *(next(st.begin(), x-1)) << endl;
		}
		else if (f == 3) {
			auto it = st.lower_bound(x);
			if (it == st.begin()) {
				cout << INT_MIN << endl;
			}
			else {
				cout << *(prev(it)) << endl;
			}
		}
		else if (f == 4) {
			auto it = st.upper_bound(x);
			if (it == st.end()) {
				cout << INT_MAX << endl;
			}
			else {
				cout << *(it) << endl;
			}
		}
		else {
			st.insert(x);
		}
	}
	return 0;
}
