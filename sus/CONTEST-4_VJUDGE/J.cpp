// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/J
#include <bits/stdc++.h>
using namespace std;

#define NAME "J"
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

int n, m;
vector<ll> a;

bool check(ll mid) {
    int res = 1;
    ll curr = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > mid) {
            return false;
        }
        if (curr + a[i] <= mid) {
            curr += a[i];
        } else {
            res++;
            curr = a[i];
        }
    }
    return res <= m;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> m;

    a.resize(n);
    ll total = 0, max_val = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
        max_val = max(max_val, a[i]);
    }

    ll lo = max_val, hi = total, res = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << res << ln;

    time();
    return 0;
}