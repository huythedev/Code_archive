// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/594115/problem/B
// davul
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

const int maxp = 2e5 + 5;
int p, k;
vector <pair <int, int>> coords (maxp);

signed main() {
    fastio();
    docfile();

    cin >> p >> k;
    coords.resize(p);
    for (int i = 0; i < p; ++i) {
        cin >> coords[i].first >> coords[i].second;
    }

    unordered_map<int, int> cnt;
    
    for (int i = 0; i < p; ++i) {
        int xi = coords[i].first;
        int yi = coords[i].second;
        
        int g = gcd(xi, yi);
        
        for (int d = 1; d * d <= g; ++d) {
            if (g % d == 0) {
                cnt[d]++;
                if (d * d != g) {
                    cnt[g / d]++;
                }
            }
        }
    }
    
    int res = 0;
    for (const auto& pair : cnt) {
        if (pair.second >= k) {
            res++;
        }
    }
    
    cout << res << ln;

    time();
    return 0;
}