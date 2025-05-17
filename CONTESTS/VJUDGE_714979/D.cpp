// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/D
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

bool ok(int min_dist, int n, int c, const vector<int>& vec) {
    int cnt = 1;
    int last = vec[0];
    for (int i = 1; i < n; ++i) {
        if (vec[i] - last >= min_dist) {
            cnt++;
            last = vec[i];
            if (cnt == c) {
                return true;
            }
        }
    }
    return false;
}

signed main() {
    fastio();
    docfile();

    int n, c;
    cin >> n >> c;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int lo = 0, hi = vec[n - 1] - vec[0], res = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid, n, c, vec)) {
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