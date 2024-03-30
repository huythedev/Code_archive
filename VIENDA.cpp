#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N, K;
	cin >> N >> K;
	
	vector<ll> vec;
	ll t;
	while(cin >> t) {
		vec.push_back(t);
	}
	
	sort(vec.rbegin(), vec.rend());
	ll i = 0, k = 0, h = 0;
	while(K - vec[i] >= 0) {
		if(k == 0 && h == 0) {
			K -= vec[i];
			++k;
		}
		else {
			if(k > h) {
				++h;
			}
			else {
				++k;
			}
			K -= vec[i];
		}
	}
	
	if(k > h) {
		cout << "First";
	}
	else {
		cout << "Second";
	}
	
    return 0;
}