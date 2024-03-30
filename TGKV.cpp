#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool checktg(ld a, ld b, ld c) {
	if(a + b > c && b + c > a && a + c > b) {
		return true;
	}
	return false;
}

bool checkkv(ld a, ld b, ld c) {
	if(pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll T;
	cin >> T;
	
	while(T--) {
		ld a, b, c;
		cin >> a >> b >> c;
		if(checktg(a, b, c)) {
			if(checkkv(a, b, c)) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		else {
			cout << "NO";
		}
		cout << endl;
	}

    return 0;
}