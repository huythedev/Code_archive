// Author: Perry
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "LFIB"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

string sum(string a,string b) {
	string c = "";
	int res = 0, mem = 0;
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size() - 1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		mem = res / 10;
		c = char(res%10 + 48) + c;
	}
	if (mem != 0) c = "1" + c;
	return c;
}

vector<string> fib(405);

void precompute() {
    fib[0] = "0";
    fib[1] = "1";
    for (int i = 2; i <= 400; i++) {
        fib[i] = sum(fib[i - 1], fib[i - 2]);
    }
}

signed main() {
    fastio();
    docfile();
    precompute();

    int tests; cin >> tests;
    while (tests--) {
        int i, j; string s; cin >> i >> j >> s;
        string tong = sum(fib[i], fib[j]);
        if (s == tong) {
            cout << "YES" << ln;
        } else {
            cout << "NO" << ln;
        }
    }

    time();
    return 0;
}