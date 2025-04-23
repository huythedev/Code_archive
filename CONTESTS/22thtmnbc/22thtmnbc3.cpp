// Author: huythedev (https://huythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/22thtmnbc3

#include <bits/stdc++.h>
using namespace std;

#define NAME "22thtmnbc3"
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

int main() {
    fastio();
    docfile();

    ll n, m, q, a, b;
    cin >> n >> m >> q >> a >> b;
    vector<ll> p(m);
    for (ll &x : p) cin >> x;
    sort(p.begin(), p.end());
    
    if (b >= a) {
        for (ll i = 0; i < q; ++i) {
            ll x, y;
            cin >> x >> y;
            cout << a * abs(x - y) << '\n';
        }
        return 0;
    }

    for (ll i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        
        if (x == y) {
            cout << 0 << ln;
            continue;
        }
        
        ll min_cost = a * abs(x - y);
        
        for (int j = 0; j < m; ++j) {
            ll cost_to_first = a * abs(x - p[j]);
            ll best_cost_to_y = a * abs(p[j] - y);
            for (int k = 0; k < m; ++k) {
                if (j != k) {
                    ll fast_cost = b * abs(p[j] - p[k]) + a * abs(p[k] - y);
                    best_cost_to_y = min(best_cost_to_y, fast_cost);
                }
            }
            min_cost = min(min_cost, cost_to_first + best_cost_to_y);
        }
        
        cout << min_cost << ln;
    }

    time();
    return 0;
}