// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

void solve() {
    int n; cin >> n;

    map<ll, int> cnt;
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        cnt[a]++;
    }

    vector<pair<ll, int>> vec;
    for (auto [x, y] : cnt) {
        vec.push_back({x, y});
    }

    ll ans = 0;
    
    vector<ll> oddLen, prefixSum;

    ll curr = 0, tmp = 0;

    for (int i = 0; i < (int)vec.size(); ++i) {
        ll M = vec[i].first;
        int C = vec[i].second;

        curr += M * C;
        tmp += C;

        if (C % 2 != 0) {
            oddLen.push_back(M);
            if (prefixSum.empty())
                prefixSum.push_back(M);
            else
                prefixSum.push_back(prefixSum.back() + M);
        }
        
        if (tmp < 3)
            continue;

        ll sumDel = 0, stickDel = 0;

        if ((int)oddLen.size() > 2) {
            stickDel = (int)oddLen.size() - 2;
            sumDel = prefixSum[(int)oddLen.size() - 3];
        }

        if (tmp - stickDel >= 3)
            if (2 * M < (curr - sumDel))
                ans = max(ans, curr - sumDel);
    }

    cout << ans << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}