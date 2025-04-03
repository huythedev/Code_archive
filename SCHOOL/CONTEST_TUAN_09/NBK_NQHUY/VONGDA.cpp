// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "VONGDA"
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

    int n; cin >> n;
    
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    
    vector<pair<int, int>> indexed_stones(2 * n);
    for (int i = 0; i < 2*n; i++) {
        indexed_stones[i] = {stones[i % n], i};
    }
    
    vector<int> dp, lis_len(2 * n, 0);  
    int max_len = 0;
    
    for (int i = 0; i < 2 * n; i++) {
        if (i >= n && indexed_stones[i].second - n >= 0) {
            while (!dp.empty() && indexed_stones[dp[0]].second <= indexed_stones[i].second - n) {
                dp.erase(dp.begin());
            }
        }
        
        auto it = lower_bound(dp.begin(), dp.end(), i, 
                             [&indexed_stones](int a, int b) -> bool {
                                 return indexed_stones[a].first < indexed_stones[b].first;
                             });
        
        if (it == dp.end()) {
            dp.push_back(i);
        } 
        else {
            *it = i;
        }
        
        lis_len[i] = dp.size();
        
        if (i < n || (indexed_stones[i].second - indexed_stones[i-n+1].second) < n) {
            max_len = max(max_len, lis_len[i]);
        }
    }
    
    cout << n - max_len << ln;

    time();
    return 0;
}