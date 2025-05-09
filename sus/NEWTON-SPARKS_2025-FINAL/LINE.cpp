// Author: huythedev
// Problem Link: https://www.it.ngs.edu.vn/problem/newtonspark25ck_line

#include <bits/stdc++.h>
using namespace std;

#define NAME "LINE"
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

    int n, q;
    cin >> n >> q;
    
    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        vector<pair<int, int>> valid_segments;
        for (auto segment : segments) {
            if (segment.first >= l && segment.second <= r) {
                valid_segments.push_back(segment);
            }
        }
        
        int curr_pos = l;
        
        while (curr_pos < r) {
            int furthest_end = curr_pos;
            bool found = false;
            
            for (auto segment : valid_segments) {
                if (segment.first <= curr_pos && segment.second > furthest_end) {
                    furthest_end = segment.second;
                    found = true;
                }
            }
            
            if (!found) {
                break;
            }
            
            curr_pos = furthest_end;
        }
        
        if (curr_pos >= r) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    time();
    return 0;
}