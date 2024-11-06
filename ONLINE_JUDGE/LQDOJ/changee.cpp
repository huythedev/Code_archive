#include <bits/stdc++.h>
using namespace std;

#define NAME "changee"
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

	vector<char> vowels = {'u', 'e', 'o', 'a', 'i', 'U', 'E', 'O', 'A', 'I'};

	int t; cin >> t;
	while (t--) {
		string st; cin >> st;

		for (char c : st) {
			auto it = find(vowels.begin(), vowels.end(), c);

			if (it != vowels.end())
				cout << (char)toupper(c);
			else
				cout << (char)tolower(c);
		}
		cout << ln;
	}

	return 0;
}