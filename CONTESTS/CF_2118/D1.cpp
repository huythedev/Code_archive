// Author: huythedev
// Problem Link: https://codeforces.com/contest/2118/problem/D1
#include <bits/stdc++.h>
using namespace std;

#define NAME "D1"
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
    int n, k; cin >> n >> k;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) 
        cin >> p[i];

    vector<int> d(n);
    for (int i = 0; i < n; ++i) 
        cin >> d[i];

    int q; cin >> q;
    vector<ll> a(q);
    for (int i = 0; i < q; ++i) 
        cin >> a[i];
    
    for (int i = 0; i < q; ++i) {
        if (a[i] > p[n - 1]) {
            cout << "YES" << ln;
            continue;
        }
        auto it = lower_bound(p.begin(), p.end(), a[i]);
        int pos = 0, dir = 0, t = 0;
        if (it != p.end() && *it == a[i]) {
            pos = it - p.begin();
            dir = 1;
            t = 0;
        } else if (it == p.end()) {
            cout << "YES" << ln;
            continue;
        } else {
            pos = it - p.begin();
            ll m = p[pos] - a[i];
            t = m % k;
            dir = 1;
        }

        vector<vector<vector<bool>>> vec(n, vector<vector<bool>>(2, vector<bool>(k, false)));
        while (true) {
            int idx = (dir == 1 ? 0 : 1);
            if (vec[pos][idx][t]) {
                cout << "NO" << ln;
                break;
            }

            vec[pos][idx][t] = true;
            int idx2 = pos;
            if (t == d[idx2]) {
                dir = -dir;
            }
            
            if (dir == 1) {
                if (idx2 == n - 1) {
                    cout << "YES" << ln;
                    break;
                } else {
                    int next_i = idx2 + 1;
                    ll m = p[next_i] - p[idx2];
                    int next_t = (t + m) % k;
                    pos = next_i;
                    t = next_t;
                }
            } else {
                if (idx2 == 0) {
                    cout << "YES" << ln;
                    break;
                } else {
                    int next_i = idx2 - 1;
                    ll m = p[idx2] - p[next_i];
                    int next_t = (t + m) % k;
                    pos = next_i;
                    t = next_t;
                }
            }
        }
    }
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