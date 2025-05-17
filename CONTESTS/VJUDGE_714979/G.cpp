// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/G
#include <bits/stdc++.h>
using namespace std;

#define NAME "G"
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

int l, n, m;
vector<int> pos;

bool check(int mid) {
    int cnt = 0;
    int last = pos[0]; 

    for (int i = 1; i <= n + 1; ++i) {
        if (pos[i] - last < mid) {
            cnt++;
        } else {
            last = pos[i];
        }
    }

    return cnt <= m;
}

signed main() {
    fastio();
    docfile();

    cin >> l >> n >> m;

    pos.resize(n + 2);
    pos[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i];
    }
    pos[n + 1] = l;

    int ans = 0;
    int lo = 1, hi = l;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << ln;

    time();
    return 0;
}