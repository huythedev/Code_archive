#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t100vd1"
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

	int s; cin >> s;

	int org_s = s;

	int days = s / 86400; s = s % 86400;
	int	hours = s / 3600; s = s % 3600;
	int	mins = s / 60; s = s % 60;

	cout << org_s << " = " << days << " ngày " << hours << " giờ " << mins << " phút " << s << " giây";

	return 0;
}