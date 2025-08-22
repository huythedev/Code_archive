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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < n; ++i) 
        cin >> b[i];

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) 
            ans += (a[i] - b[i]);
    }

    cout << (ans + 1) << ln;
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