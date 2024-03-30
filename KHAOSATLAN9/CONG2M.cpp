#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll N;
	cin >> N;
	ll tmp = N;
	
	vector <ll> A, B;
	while (tmp--) {
		ll t;
		cin >> t;
		A.push_back(t);
	}
	tmp = N;
	while (tmp--) {
		ll t;
		cin >> t;
		B.push_back(t);
	}
	
	for (ll i = 0; i < N; ++i) {
		cout << A[i] + B[i] << " ";
	}
    return 0;
}