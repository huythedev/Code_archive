#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N;
	cin >> N;
	
	ll res = 0;
	for (ll a = 1; a < N / 3; ++a) {
		for (ll b = a + 1; b < N / 3; ++b) {
			for (ll c = b + 1; c < N / 3; ++c) {
				ll tmp = a + b + c;
				if (tmp == N) {
					++res;
					break;
				}
			}
		}
	}
	
	if (res == 0) {
		cout << "-1";
	}
	else {
		cout << res;
	}

    return 0;
}