// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_coban_chontranh"
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int p, q, r; cin >> p >> q >> r;

    ll res = 0;
    
    if (p == q && q == r) {
        ll cnt = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == p) cnt++;
            
        res = cnt * (cnt - 1) * (cnt - 2) / 6;
    }
    else if (p == q) {
        ll cnt_p = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == p) cnt_p++;
            else if (a[i] == r) {
                res += cnt_p * (cnt_p - 1) / 2;
            }
        }
    }
    else if (q == r) {
        ll cnt_p = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == p) cnt_p++;
            else if (a[i] == q) {
                res += cnt_p * (cnt_p - 1) / 2;
            }
        }
    }
    else if (p == r) {
        ll cnt_p = 0;
        ll cnt_pq = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == p) {
                res += cnt_pq;
                cnt_p++;
            }
            else if (a[i] == q) {
                cnt_pq += cnt_p;
            }
        }
    }
    else {
        ll cnt_p = 0;
        ll cnt_pq = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == p) {
                cnt_p++;
            }
            else if (a[i] == q) {
                cnt_pq += cnt_p;
            }
            else if (a[i] == r) {
                res += cnt_pq;
            }
        }
    }

    cout << res << ln;
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