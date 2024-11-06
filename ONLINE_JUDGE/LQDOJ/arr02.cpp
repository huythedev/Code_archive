#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	vector<ll>pos;
	ll t, tmp = LLONG_MAX, tmp2 = 1;
	while(cin >> t) {
		if(t < tmp) {
			tmp = t;
			pos.clear();
			pos.push_back(tmp2);
		}
		else if(t == tmp) {
			pos.push_back(tmp2);
		}
		++tmp2;
	}
	
	cout << tmp << endl;
	for(ll i : pos) {
		cout << i << " ";
	}
	
    return 0;
}