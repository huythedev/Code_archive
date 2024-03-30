#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> likenum;

void buildvec(){
	ll tmp = 1;
	while(likenum.size() < 1000) {
		if (tmp % 3 == 0 || tmp % 10 == 3) {
			++tmp;
		}
		else {
			likenum.push_back(tmp);
			++tmp;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	buildvec();
	
	ll q;
	cin >> q;
	while (q--) {
		ll t;
		cin >> t;
		cout << likenum[t - 1] << endl;
	}

    return 0;
}