#include <bits/stdc++.h>
#define NAME "BEAUTY"
using namespace std;

typedef long long ll;

void docfile() {
	if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

bool checkbeauty(ll n) {
	ll res = 0;
	string st = to_string(n);
	while(n > 0) {
		res += n % 10;
		n /= 10;
	}
	if(res % st.size() == 0) {
		return true;
	}
	return false;
}

const ll LIM = 1e6;
vector<ll> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll n;
	cin >> n;
	
	vector<ll> vec;
	
	ll t = 1;
	for(ll i = 1; i <= LIM; ++i) {
		for(ll j = t; j <= 1e18; ++j) {
			if(checkbeauty(j)) {
				vec.push_back(j);
				t = j + 1;
				break;
			}
		}
	}
	
	cout << vec[n - 1];

    return 0;
}