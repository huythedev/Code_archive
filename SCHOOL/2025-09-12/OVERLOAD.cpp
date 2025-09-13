// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "OVERLOAD"
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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<pair<int,int>> vec(n);
    for (int j = 0; j < n; ++j) 
        vec[j] = {a[j], j};
    
    sort(vec.begin(), vec.end());

    vector<pair<ll,int>> vec2(m);
    for (int i = 0; i < m; ++i) 
        vec2[i] = {b[i], i + 1};

    sort(vec2.begin(), vec2.end());

    vector<int> ans(n, -1);
    priority_queue<pair<ll,int>> pq;
    int v = 0;
    for (auto [pos, idx] : vec2) {
        while (v < n && vec[v].first <= pos) {
            pq.push({vec[v].first, vec[v].second});
            ++v;
        }

        if (!pq.empty()) {
            auto [posV, idxV] = pq.top(); 
            pq.pop();
            ans[idxV] = idx; 
        }
    }

    for (int x : ans) cout << x << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}