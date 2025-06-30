// Author: huythedev
// Problem Link: https://codeforces.com/contest/2120/problem/C
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

vector<int> build(int n, ll m) {
    vector<int> vec;
    set<int, greater<int>> s;
    for (int i = 1; i <= n; ++i) 
        s.insert(i);

    ll sum = 0;
    int curr = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int nodes = n - i - 1;
        ll remain = m - sum;

        int v = -1;
        for (int x : s) {
            int d = min(curr, x);
            if (d + (ll)nodes * (s.size() > 1 ? min(d, *s.rbegin()) : 1) <= remain) {
                v = x;
                break;
            }
        }

        if (v == -1) 
            return {};

        vec.push_back(v);
        s.erase(v);

        curr = min(curr, v);
        sum += curr;
    }

    return vec;
}

void solve() {
    int n; ll m; cin >> n >> m;

    if (m < n || m > (ll)n * (n + 1) / 2) 
        cout << "-1" << ln;
    else {
        vector<int> vec = build(n, m);
        cout << vec[0] << ln;
        for (int i = 0; i < n - 1; ++i) 
            cout << vec[i] << " " << vec[i + 1] << ln;
    }
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}