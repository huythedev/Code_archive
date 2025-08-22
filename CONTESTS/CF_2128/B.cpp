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

void solve() {
    int n;
    cin >> n;
    
    deque<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    string res;
    for (int i = 0; i < n; ++i) {
        if (p.size() == 1) {
            res += 'L';
            p.pop_front();
        } 
        else {
            if (i % 2 == 0) {
                if (p.front() < p.back()) {
                    res += 'L';
                    p.pop_front();
                } 
                else {
                    res += 'R';
                    p.pop_back();
                }
            } 
            else {
                if (p.front() > p.back()) {
                    res += 'L';
                    p.pop_front();
                } 
                else {
                    res += 'R';
                    p.pop_back();
                }
            }
        }
    }
    
    cout << res << ln;
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