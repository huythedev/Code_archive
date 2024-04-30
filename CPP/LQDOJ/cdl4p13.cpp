#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl4p13"
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

	int a, b; cin >> a >> b;

	cout << "Boi chung nho nhat cua " << a << " va " << b << " la " << abs((a * b) / __gcd(a, b));

	return 0;
}