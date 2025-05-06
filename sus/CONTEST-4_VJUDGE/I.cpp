// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/I
#include <bits/stdc++.h>
using namespace std;

#define NAME "I"
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

int l, n, k;
vector<int> a;

bool check(int max_dist) {
    int tmp = 0; 
    for (int i = 1; i < n; ++i) {
        int curr_dist = a[i] - a[i-1];
        if (curr_dist > max_dist) {
            tmp += (curr_dist - 1) / max_dist;
        }
    }
    return tmp <= k;
}

signed main() {
    fastio();
    docfile();

    cin >> l >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int lo = 1, hi = l, res = l;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
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