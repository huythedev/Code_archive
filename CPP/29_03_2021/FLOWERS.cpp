#include <bits/stdc++.h>
#define NAME "FLOWERS"
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
	
	ll a, b, c;
	cin >> a >> b >> c;
	
	ll m1 = (ll)(c / a) * a + ((c - ((ll)(c / a) * a)) / b) * b;
	ll m2 = (ll)(c / b) * b + ((c - ((ll)(c / b) * b)) / a) * a;
	
	cout << max(m1, m2);
	
    return 0;
}