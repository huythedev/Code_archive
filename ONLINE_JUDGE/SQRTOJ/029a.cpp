// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "INTEGER"
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

const ll MAX_VAL = 1e18;

void solve() {
    ll l, r;
    cin >> l >> r;

    vector<ll> vec;
    queue<pair<ll, ll>> q;

    q.push({1, 1});
    q.push({5, 5});
    q.push({9, 9});

    while (!q.empty()) {
        auto [num, last] = q.front();

        q.pop();
        vec.push_back(num);

        for (ll d : {1, 5, 9}) {
            if (d != last) {
                ll next = num * 10LL + d;

                if (next < MAX_VAL) {
                    q.push({next, d});
                }
            }
        }
    }

    sort(vec.begin(), vec.end());

    ll res = 0;
    for (auto a : vec) {
        if (a > r) break;

        ll lowVal = max(a, l - a);
        ll upVal = r - a;

        if (lowVal > upVal) continue;

        auto it1 = lower_bound(vec.begin(), vec.end(), lowVal);
        auto it2 = upper_bound(it1, vec.end(), upVal);

        ll cnt = it2 - it1;
        res += cnt;
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