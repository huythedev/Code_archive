#include <bits/stdc++.h>
using namespace std;

#define NAME "CLUB"
#define ln "\n"

typedef long long ll;
typedef long double ld;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

void time() {
	cerr << ln << "Time elapsed: " << clock()/CLOCKS_PER_SEC << "s." << ln;
}

int main() {
	fastio();
	docfile();

	string s, t; cin >> s >> t;
	unordered_map<char, int> freq_first_month, freq_second_month;
	for(char c : s)
		freq_first_month[c]++;
	for(char c : t)
		freq_second_month[c]++;

	int tests; cin >> tests;
	while(tests--) {
		char c; cin >> c;
		if(freq_first_month[c] > freq_second_month[c])
			cout << 1;
		else if(freq_first_month[c] < freq_second_month[c])
			cout << 2;
		else
			cout << 3;
		cout << ln;
	}

	time();
	return 0;
}
