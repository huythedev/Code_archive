// Author: huythedev
// Problem Link: https://marisaoj.com/problem/520
#include <bits/stdc++.h>
using namespace std;

#define NAME "520"
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
    int a, b; cin >> a >> b;
    bitset<15> abit(a), bbit(b), cbit(0);

    for (int i = 0; i < 5; ++i) {
        cbit[i] = abit[i] ^ bbit[i];
    }
    for (int i = 5; i < 10; ++i) {
        cbit[i] = abit[i] & bbit[i];
    }
    for (int i = 10; i < 15; ++i) {
        cbit[i] = abit[i] | bbit[i];
    }

    cout << cbit.to_ulong() << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}