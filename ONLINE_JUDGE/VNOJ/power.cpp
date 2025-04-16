// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/power
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "power"
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

int test_case = 1;
void print_result(int res) {
    cout << "Case #" << test_case << ": " << res << ln;
    ++test_case;
}

int solve(ll l, ll r) {
    for (int k = 60; k >= 1; --k) {
        ll left = 0, right = (ll)(pow(r, 1.0 / k) + 10);
        while (left < right) {
            ll mid = (left + right) / 2;
            ll z = 1;
            for (int i = 0; i < k; ++i) {
                z *= mid;
                if (z >= l)
                    break;
            }
            if (z >= l)
                right = mid;
            else
                left = mid + 1;
        }
        ll z = 1;
        for (int i = 0; i < k; ++i) {
            z *= left;
            if (z > r)
                break;
        }
        if (l <= z && z <= r)
            return k;
    }
    return 0;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;

        int res = solve(l, r);

        print_result(res);
    }

    time();
    return 0;
}