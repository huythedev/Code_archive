#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<ll> vec;
	for (int i = 0; i < 4; ++i) {
		ll t;
		cin >> t;
		vec.push_back(t);
	}
	
	sort(vec.rbegin(), vec.rend());
	
	cout << vec[0] << "/" << vec[vec.size() - 1];
	
    return 0;
}