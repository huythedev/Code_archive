#include <bits/stdc++.h>
using namespace std;

#define NAME "div2borangevol2"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int N; cin >> N;
	while (N--) {
		string Y; cin >> Y;

		if (Y[0] == '0')
			cout << 0 << ln;
		else
			cout << Y.size() << ln;
	}

	return 0;
}