#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

vl memo;
ll solve(int n) {
	if (memo[n] < 0) {
		memo[n] = 0;
		for (int i = 0; i < n; ++i) {
			memo[n] += solve(i) * solve((n - 1) - i);
		}
	}

	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	if (0 == n) {
		cout << 1;
		return 0;
	}

	memo = vl(n + 1, -1);
	memo[0] = 1;

	cout << solve(n);

	return 0;
}