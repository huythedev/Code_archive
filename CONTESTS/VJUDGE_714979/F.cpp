// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/F
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

signed main() {
    fastio();
    docfile();

    int m, n; cin >> m >> n;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    ll res = 0;

    for (int i : b) {
        ll tmp = -1;

        auto it = lower_bound(a.begin(), a.end(), i);

        if (it != a.end()) {
            ll diff = abs((ll)*it - i);
            if (tmp == -1 || diff < tmp) {
                tmp = diff;
            }
        }

        if (it != a.begin()) {
            auto it_prev = prev(it);
            ll diff = abs((ll)*it_prev - i);
            if (tmp == -1 || diff < tmp) {
                tmp = diff;
            }
        }
        
        if (tmp != -1) {
            res += tmp;
        }
    }

    cout << res << ln;

    time();
    return 0;
}