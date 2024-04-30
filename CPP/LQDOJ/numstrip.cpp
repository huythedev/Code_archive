#include <bits/stdc++.h>
using namespace std;

#define NAME "numstrip"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

vector<ll> buildprefixsum(vector<int> vec) {
	vector<ll> res(vec.size() + 1);
	res[0] = 0;
	for (int i = 1; i < res.size(); ++i)
		res[i] = res[i - 1] + vec[i - 1];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	vector<ll> prefixsum = buildprefixsum(A);
	int res = 0;
	for (int i = 1; i < prefixsum.size() - 1; ++i)
		if (prefixsum[i] == prefixsum[prefixsum.size() - 1] - prefixsum[i])
			++res;

	cout << res;

	return 0;
}