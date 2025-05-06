// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/H
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

int n, k;
vector<int> l;

bool ok(int len) {
    if (len == 0) {
        return false;
    }
    ll ans = 0;
    for (int i : l) {
        ans += (ll)i / len;
    }
    return ans >= k;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> k;
    l.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    int res = 0, lo = 1, hi = 1e8;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << res << ln;

    time();
    return 0;
}