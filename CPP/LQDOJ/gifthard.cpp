#include <bits/stdc++.h>
using namespace std;

#define NAME "gifthard"
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

	string S; getline(cin, S);
	cin >> ws;
	int N; cin >> N;
	while (N--) {
		string st; getline(cin, st);
		cin >> ws;

		int tmp = 0;
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == st[tmp]) {
				S.erase(i, 1);
				++tmp;
			}
			if (st.empty())
				break;
		}
	}

	cout << S;

	return 0;
}