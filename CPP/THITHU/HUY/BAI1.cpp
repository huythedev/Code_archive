#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI1"

typedef long long ll;

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

int main() {
	fastio();
	docfile();

	ll k, a, b; cin >> k >> a >> b;
	cout << (b / k) - (a - 1) / k << endl;

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}
