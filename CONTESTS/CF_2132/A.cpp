// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}


void solve() {
    int n;  cin >> n;
    string st; cin >> st;
    int m; cin >> m;
    string b, c; cin >> b >> c;

    string s1 = "", s2 = "";
    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V') 
            s1.push_back(b[i]);
        else
            s2.push_back(b[i]);
    }

    reverse(s1.begin(), s1.end());

    cout << s1 << st << s2 << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}