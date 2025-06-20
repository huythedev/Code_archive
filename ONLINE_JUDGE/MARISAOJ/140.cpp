// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "140"
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

const int MOD = 1e9 + 7;

vector<int> vec(1e5, -1);

int count(int remaining_steps) {
    if (remaining_steps == 0) return 1;
    if (remaining_steps < 0) return 0;
    if (vec[remaining_steps] != -1)
        return vec[remaining_steps];

    int res = 0;
    res = (res + count(remaining_steps - 1)) % MOD;
    res = (res + count(remaining_steps - 2)) % MOD;
    res = (res + count(remaining_steps - 3)) % MOD;

    return vec[remaining_steps] = res;
}

void solve() {
    int n; cin >> n;

    cout << count(n) << ln;
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