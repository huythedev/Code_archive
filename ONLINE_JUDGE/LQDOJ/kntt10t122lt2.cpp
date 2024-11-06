#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t122lt2"
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

	for (char c : S) {
		if (c - '0' >= 0 && c - '0' <= 9) {
			cout << "S có chứa chữ số";
			return 0;
		}
	}

	cout << "S không chứa chữ số nào";

	return 0;
}