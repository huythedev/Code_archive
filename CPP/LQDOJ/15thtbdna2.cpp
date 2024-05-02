#include <bits/stdc++.h>
using namespace std;

#define NAME "15thtbdna2"
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

	string S; cin >> S;

	int freq[300] = {0}, maxfreq = 0;
	for (char c : S) {
		freq[(int)c]++;
		maxfreq = max(maxfreq, freq[(int)c]);
	}

	for (int i = 0; i < 300; ++i)
		if (freq[i] == maxfreq) {
			cout << (char)i << ln;
			break;
		}

	return 0;
}