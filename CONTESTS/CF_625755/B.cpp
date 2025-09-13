// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

const int N = 1e6 + 5;

int n, a[N];
int pre[N], suf[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    
    pre[1] = a[1], suf[n] = a[n];
    for (int i = 2; i <= n; ++i) 
        pre[i] = max(pre[i - 1], a[i]);
    for (int i = n - 1; i >= 1; --i) 
        suf[i] = min(suf[i + 1], a[i]);

    int cnt = 0;
    for (int i = 1; i <= n; ++i) 
        if (pre[i] <= suf[i + 1]) ++cnt;

    cout << cnt + 1;
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