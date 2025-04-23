// Author: huythedev (https://huythedev.com)
// Problem Link:

#include <bits/stdc++.h>
using namespace std;

#define NAME "KHOANGCACH"
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

signed main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    unordered_map<int, vector<int>> color_pos;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        color_pos[a[i]].push_back(i);
    }
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        
        int min_dist = INT_MAX;
        
        for (auto &[color, positions] : color_pos) {
            auto it_l = lower_bound(positions.begin(), positions.end(), l);
            
            if (it_l == positions.end() || *it_l > r) continue;
            
            auto it_r = upper_bound(positions.begin(), positions.end(), r);
            if (distance(it_l, it_r) < 2) continue;
            
            for (auto it = it_l; it + 1 != it_r; ++it) {
                min_dist = min(min_dist, *(it + 1) - *it);
            }
        }
        
        if (min_dist == INT_MAX) {
            cout << -1 << ln;
        } 
        else {
            cout << min_dist << ln;
        }
    }

    time();
    return 0;
}