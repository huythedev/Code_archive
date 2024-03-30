#include <bits/stdc++.h>
#define NAME "SNAIL"
using namespace std;

typedef long long ll;

void docfile() {
	if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	
	ll a, b, v;
	cin >> a >> b >> v;
	
	ll t = a - b;
	
	if(v % t == 0) {
		cout << v / t;
	}
	else {
		cout << v / t + 1;
	}

    return 0;
}