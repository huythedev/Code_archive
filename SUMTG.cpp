#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin >> t;
	
	while(t--) {
		ll h1, m1, s1, h2, m2, s2;
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		
		ll h = h1 + h2, m = m1 + m2, s = s1 + s2;
		
		while(s / 60 != 0) {
			m++;
			s -= 60;
		}
		
		while(m / 60 != 0) {
			h++;
			m -= 60;
		}
		
		cout << h << " " << m << " " << s << endl;
	}

    return 0;
}