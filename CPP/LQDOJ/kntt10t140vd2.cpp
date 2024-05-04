#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t140vd2"
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

	int d, m, y; cin >> d >> m >> y;

	if (d > 31 || m > 12 || d < 1 || m < 1 || y < 1 )
		cout << "Thời gian nhập không hợp lệ";
	else
		cout << "Thời gian nhập hợp lệ";

	return 0;
}