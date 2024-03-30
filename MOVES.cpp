#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll a, b, s;
	cin >> a >> b >> s;
	
	ll moves = abs(a) + abs(b);
	
	if(moves == s) {
		cout << "Yes";
	}
	else if(s >= moves && (s - moves) % 2 == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

    return 0;
}
