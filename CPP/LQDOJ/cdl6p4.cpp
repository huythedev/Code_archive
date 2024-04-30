#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl6p4"
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

	int N, M; cin >> N >> M;
	cin >> ws;

	string a, b;
	getline(cin, a);
	getline(cin, b);

	vector<string> name;
	int tmp = 0;
	for (int i = 0; i < (int)a.size(); ++i) {
		tmp = i;
		while (i < (int)a.size() && a[i] != ' ') {
			++i;
		}
		name.push_back(a.substr(tmp, i - tmp));

	}

	tmp = 0;
	for (int i = 0; i < (int)b.size(); ++i) {
		tmp = i;
		while (i < (int)b.size() && b[i] != ' ') {
			++i;
		}
		name.push_back(b.substr(tmp, i - tmp));
	}

	sort(name.begin(), name.end());
	for (string s : name)
		cout << s << ' ';

	return 0;
}