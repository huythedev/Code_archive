// Author: huythedev
// Problem Link: 
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

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> vec(n);
    for (auto &x : vec) {
        cin >> x.first >> x.second;
    }

    sort(vec.begin(), vec.end(), comp);

    int remain = vec[0].second;
    int total = vec[0].first;
    for (int i = 1; i < n; ++i) {
        if (remain == 0) break;

        total += vec[i].first;
        remain += vec[i].second;
        
        remain--;
    }

    cout << total << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}