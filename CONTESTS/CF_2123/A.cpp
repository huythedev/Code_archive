// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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
    int n; cin >> n;
    
    int cnt[4] = {0};
    for (int i = 0; i < n; i++)
        cnt[i % 4]++;

    int tmp = min(cnt[0], cnt[3]), tmp2 = min(cnt[1], cnt[2]);

    int remaining = (cnt[0] - tmp) + (cnt[3] - tmp) + (cnt[1] - tmp2) + (cnt[2] - tmp2);

    if (remaining > 0) {
        cout << "Alice" << ln;
    } 
    else {
        cout << "Bob" << ln;
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