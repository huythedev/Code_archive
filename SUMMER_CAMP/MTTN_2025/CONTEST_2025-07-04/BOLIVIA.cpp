// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BOLIVIA"
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

int n, q;
vector<int> h(300005);

bool check(int y1, int y2) {
    int res = 0;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        if (h[i] < y1) {
            heights[i] = 0;
        } 
        else if (h[i] >= y2) {
            heights[i] = y2 - y1 + 1;
        }
        else {
            heights[i] = h[i] - y1 + 1;
        }
    }
    
    for (int i = 0; i < n / 2; ++i) {
        if (heights[i] != heights[n - 1 - i]) {
            return false;
        }
    }
    
    cerr << y1 << ' ' << y2 << ln;
    
    return true;
}

void solve() {
    cin >> n >> q;
    for (int &i : h) {
        cin >> i;
    }

    int max_height = h[(n + 1) / 2 - 1];
    cerr << max_height << ln;
    
    int res = 0;
    for (int y1 = 0; y1 < max_height; ++y1) {
        for (int y2 = y1 + 1; y2 <= max_height; ++y2) {
            if (check(y1, y2)) {
                ++res;
            }
        }
    }
    cout << res << ln;

    while (q--) {
        res = 0;
        int t, h2; cin >> t >> h2;
        t--;
        h[t] = h2;

        for (int y1 = 0; y1 < max_height; ++y1) {
            for (int y2 = y1 + 1; y2 <= max_height; ++y2) {
                if (check(y1, y2)) {
                    ++res;
                }
            }
        }

        cout << res << ln;
    }
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