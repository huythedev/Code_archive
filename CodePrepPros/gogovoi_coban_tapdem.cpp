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
    string s;
    int k;
    cin >> s >> k;

    int n = (int)s.size();
    ll ans = 0;
    vector<int> cnt(26, 0); 

    int l = 0;
    for (int r = 0; r < n; ++r) {
        int cr = s[r] - 'a';
        cnt[cr]++;

        while (cnt[cr] > k) {
            int cl = s[l] - 'a';
            cnt[cl]--;
            l++;
        }

        ans += (r - l + 1);
    }

    cout << ans << ln;
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