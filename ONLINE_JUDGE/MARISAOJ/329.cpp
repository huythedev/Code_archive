// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "329"
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

void genSubSet(vector<ll>& a, int n, int len, int start, ll k, ll sum, bool& status) {
    if (status) return;

    if (len == 0) {
        if (sum == k) {
            cout << "YES" << ln;
            status = true;
        }
        return;
    }

    for (int i = start; i < n; i++) {
        ll tmp = a[i];
        a[i] = -1;
        genSubSet(a, n, len - 1, i + 1, k, sum + tmp, status);
        a[i] = tmp;
    }
}

void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool found = false;
    for (int len = 1; len <= n; ++len) {
        genSubSet(a, n, len, 0, k, 0, found);
        if (found) break;
    }

    if (!found) {
        cout << "NO" << ln;
    }
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