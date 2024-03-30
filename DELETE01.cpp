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

	string N;
	cin >> N;
	
	for(ll i = 0; i < N.length(); ++i) {
		if(N[i] - '0' == 0 || N[i] - '0' == 1) {	
			N.erase(i, 1);
			i--;
		}
	}
	
	cout << N;

    return 0;
}