#include <bits/stdc++.h>
using namespace std;

#define NAME "STRC"

typedef long long ll;

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	docfile();

	string S; cin >> S;

	ll res = 0;
	for(int i = 0; i < S.size(); ++i)
		if((S[i] - '0') % 2 == 0 && S[i] - '0' <= 9 && S[i] - '0' >= 0)
			res += i + 1;

	cout << res;
	return 0;
}
