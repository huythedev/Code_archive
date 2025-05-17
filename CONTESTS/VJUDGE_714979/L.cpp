// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/L
#include <bits/stdc++.h>
using namespace std;

#define NAME "L"
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

int n, p;
vector<pair<int, int>> devices;

bool check(double t, double p2) {
    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        double tmp = (double)devices[i].first * t;
        if (tmp > devices[i].second) {
            res += (tmp - devices[i].second);
        }
    }
    return res <= p2 * t;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> p;

    devices.resize(n);
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> devices[i].first >> devices[i].second;
        total += devices[i].first;
    }

    double p2 = static_cast<double>(p);

    if (total <= p2) {
        cout << -1 << ln;
        time();
        return 0;
    }

    double lo = 0.0, hi = 2e10, ans = 0.0;

    for (int i = 0; i < 100; ++i) {
        double mid = lo + (hi - lo) / 2.0;
        if (check(mid, p2)) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << fixed << setprecision(10) << ans << ln;

    time();
    return 0;
}