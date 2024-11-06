#include <bits/stdc++.h>
using namespace std;

#define NAME "cmpint"
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

	string a, b; cin >> a >> b;

	while (a[0] == '0')
		a.erase(a.begin());
	while (b[0] == '0')
		b.erase(b.begin());

	if (a.size() > b.size())
		cout << ">";
	else if (a.size() < b.size())
		cout << "<";
	else {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] > b[i]) {
				cout << ">";
				return 0;
			}
			else if (a[i] < b[i]) {
				cout << "<";
				return 0;
			}
		}
		cout << "=";
	}

	return 0;
}