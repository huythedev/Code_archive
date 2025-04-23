// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2074/problem/D

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

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> x(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    
    ll total_points = 0;
    
    map<ll, vector<pair<ll, ll>>> ranges;
    
    for (int i = 0; i < n; i++) {
        ll center = x[i];
        ll radius = r[i];
        
        for (ll curr_x = center - radius; curr_x <= center + radius; curr_x++) {
            ll dx = abs(curr_x - center);
            if (dx > radius) continue;
            
            ll y_limit = sqrt(1.0 * radius * radius - 1.0 * dx * dx);
            ranges[curr_x].push_back({-y_limit, y_limit});
        }
    }
    
    for (auto& [x_val, y_ranges] : ranges) {
        sort(y_ranges.begin(), y_ranges.end());
        
        vector<pair<ll, ll>> merged;
        for (auto& range : y_ranges) {
            if (merged.empty() || merged.back().second < range.first) {
                merged.push_back(range);
            } 
            else {
                merged.back().second = max(merged.back().second, range.second);
            }
        }
        
        for (auto& [start, end] : merged) {
            ll left = ceil(start);
            ll right = floor(end);
            if (right >= left) {
                total_points += right - left + 1;
            }
        }
    }
    
    cout << total_points << ln;
}

signed main() {
    fastio();
    docfile();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}