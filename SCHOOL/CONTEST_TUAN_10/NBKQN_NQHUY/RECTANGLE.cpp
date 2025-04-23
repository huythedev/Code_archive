// Author: huythedev
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "RECTANGLE"
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

    int N; cin >> N;
    
    map<int, set<int>> mp;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        mp[x].insert(y);
    }
    
    vector<int> vec;
    for (auto& p : mp) {
        vec.push_back(p.first);
    }
    
    ll res = 0;
    for (size_t i = 0; i < (int)vec.size(); i++) {
        for (size_t j = i + 1; j < (int)vec.size(); j++) {
            const set<int>& y1 = mp[vec[i]];
            const set<int>& y2 = mp[vec[j]];
            
            int cnt = 0;
            auto it1 = y1.begin(), it2 = y2.begin();
            while (it1 != y1.end() && it2 != y2.end()) {
                if (*it1 < *it2) ++it1;
                else if (*it2 < *it1) ++it2;
                else {
                    ++cnt;
                    ++it1;
                    ++it2;
                }
            }
            
            res += (ll)cnt * (cnt - 1) / 2;
        }
    }
    
    cout << res << ln;

    time();
    return 0;
}