#include <bits/stdc++.h>
using namespace std;

#define NAME "ifforwhile04"
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

	int a, b, c; cin >> a >> b >> c;

	cout << (int)pow(2, a + b) - (int)pow(4, c);

	return 0;
}