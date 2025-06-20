// Author: huythedev
// Problem Link: https://marisaoj.com/problem/522
#include <bits/stdc++.h>
using namespace std;

#define NAME "522"
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

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int &i : A) {
        cin >> i;
    }

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int val = A[i] ^ (i + 1);
        mp[val]++;
    }

    ll pairs = 0;
    for (auto &p : mp) {
        ll c = p.second;
        pairs += c * (c - 1) / 2;
    }

    cout << pairs << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}