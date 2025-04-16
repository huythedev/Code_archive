// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/51
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()
#define int long long

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
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        mp[x]++;
    }

    ll res = 0;
    for (pair<int, int> p : mp) {
        res += p.second * (p.second - 1) / 2;
    }

    cout << res << ln;

    time();
    return 0;
}