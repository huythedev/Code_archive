#include <bits/stdc++.h>
using namespace std;

#define NAME "24sna1"
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

	string A, B; cin >> A >> B;

	if (B.size() > 1)
		B.erase(B.size() - 1, 1);

	ll num_A = stoll(A), num_B = stoll(B);

	if (num_A > num_B)
		cout << "A";
	else
		cout << "B";

	return 0;
}