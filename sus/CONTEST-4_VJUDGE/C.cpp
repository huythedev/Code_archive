// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/C
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

ll n, m;
vector<int> tree_heights;

bool check(int h) {
    ll curr = 0;
    for (int i : tree_heights) {
        if (i > h) {
            curr += (i - h);
        }
        if (curr >= m) {
            return true;
        }
    }
    return curr >= m;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> m;
    tree_heights.resize(n);
    int max_h = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tree_heights[i];
        max_h = max(max_h, tree_heights[i]);
    }

    int lo = 0, hi = max_h, res = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
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