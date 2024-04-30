#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

	string chucmung = "Chuc mung sinh nhat LQDOJ";
	string S;
	getline(cin, S);

	map<char, int> chucai;
	for (char c : chucmung) {
		chucai[c]++;
	}

	map<char, int> freq_S;
	for (char c : S) {
		if (isalnum(c) || c == ' ') {
			freq_S[c]++;
		}
	}

	int res = 0;
	for (auto [c, cnt] : chucai) {
		if (freq_S[c] < cnt) {
			res += cnt - freq_S[c];
		}
	}

	cout << res << endl;
	return 0;
}