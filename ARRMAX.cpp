#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	ll MAX = LLONG_MIN, pos = -1;
	ll t, i = 1;
	while(cin >> t) {
		if(t > MAX) {
			MAX = t;
			pos = i;
		}
		++i;
	}
	cout << MAX << endl << pos;

    return 0;
}