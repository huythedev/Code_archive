#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll s1, t1, s2, t2;
	cin >> s1 >> t1 >> s2 >> t2;
	
	ld v1 = s1 / t1, v2 = s2 / t2;
	
	if((ll)v1 > (ll)v2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

    return 0;
}