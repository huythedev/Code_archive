#include <bits/stdc++.h>
using namespace std;

#define NAME "article"
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

	vector<char> vowels = {'a', 'e', 'o', 'i', 'u'};

	string st; cin >> st;
	if (find(vowels.begin(), vowels.end(), st[0]) != vowels.end())
		cout << "an";
	else
		cout << "a";

	return 0;
}