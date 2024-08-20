#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N, X;
	cin >> N >> X;
	vector<ll> A(N); 
	for (ll i = 0; i < N; ++i) {
		cin >> A[i];
	}

	ll i = 0, j = N - 1; 
	while (i < j) {
		ll sum = A[i] + A[j];
		if (sum == X) {
			cout << i + 1 << " " << j + 1;
			return 0;
		} else if (sum < X) {
			++i; 
		} else {
			--j;
		}
	}

	cout << "No solution";
	return 0;
}
