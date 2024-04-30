#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t104vd2"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool isLeapYear(int n) {
	return n % 400 == 0 || n % 100 != 0 && n % 4 == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;

	if (isLeapYear(n))
		cout << n << " là năm nhuận";
	else
		cout << n << " không phải là năm nhuận";

	return 0;
}