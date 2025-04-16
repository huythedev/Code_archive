// Author: huythedev
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

signed main() {
    fastio();
    docfile();

    int n; cin >> n;

    vector<string> ops;

    for (int i = 2; i <= n; ++i) {
        ops.push_back("+ 1 1 " + to_string(i));
        ops.push_back("* " + to_string(i) + " " + to_string(i) + " " + to_string(i));
    }

    cout << ops.size() << ln;
    for (const string& i : ops) {
        cout << i << ln;
    }

    time();
    return 0;
}