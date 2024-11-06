#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int n, k; cin >> n >> k;

	vector<int> vec(n);
	for(int i = 0; i < n; ++i)
		cin >> vec[i];

	sort(vec.rbegin(), vec.rend());

	cout << vec[k - 1];

	return 0;
}
