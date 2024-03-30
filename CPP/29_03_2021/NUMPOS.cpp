#include <bits/stdc++.h>
#define NAME "NUMPOS"
using namespace std;

typedef long long ll;

void docfile() {
	if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

const ll LIM = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	
	ll k;
	cin >> k;
	if(k <= 3) {
		cout << k;
	}
	else {
		cout << (k - 2) * 3;
	}

    return 0;
}