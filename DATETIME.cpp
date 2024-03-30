#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

	ll D, M, Y;
	cin >> D >> M >> Y;
	
	if(Y >= 1 && Y <= 99) {
		if(M >= 1 && M <= 12) {
			if(D >= 1 && D <= 31) {
				cout << D << "/" << M << "/20" << Y; 
			}
			else 
				cout << -1;
		}
		else
			cout << -1;
	}
	else {
		cout << -1;
	}

    return 0;
}