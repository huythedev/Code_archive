// Author: huythedev
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/599678/problem/B

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

signed main() {
    fastio();
    docfile();

    int n, k;
    cin >> n >> k;
    
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int a = 0;
    int l = 0;
    multiset<int> window;
    
    for (int r = 0; r < n; r++) {
        window.insert(heights[r]);
        
        while (!window.empty() && *window.rbegin() - *window.begin() > k) {
            window.erase(window.find(heights[l]));
            l++;
        }
        
        a = max(a, r - l + 1);
    }
    
    vector<pair<int, int>> vec2;
    
    for (int i = 0; i < n; i++) {
        if (i + a - 1 >= n) break;
        
        int min_height = *min_element(heights.begin() + i, heights.begin() + i + a);
        int max_height = *max_element(heights.begin() + i, heights.begin() + i + a);
        
        if (max_height - min_height <= k) {
            vec2.push_back({i + 1, i + a});
        }
    }
    
    cout << a << " " << vec2.size() << ln;
    for (pair<int, int> i : vec2) {
        cout << i.first << " " << i.second << ln;
    }

    time();
    return 0;
}