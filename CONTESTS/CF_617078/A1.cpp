// Author: huythedev
// Problem Link: https://codeforces.com/gym/617078/problem/A1
#include <bits/stdc++.h>
using namespace std;

#define NAME "A1"
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

int ans, n;

void backtrack(int sum, int last, long long lcm) {
    if (sum == n) {
        ans = max(ans, (int)lcm);
        return;
    }
    if (sum > n) return;
    
    for (int i = last; i <= n - sum && i <= 50; ++i) {
        long long new_lcm = lcm;
        if (lcm == 0) new_lcm = i;
        else {
            new_lcm = lcm * i / __gcd(lcm, (long long)i);
            if (new_lcm > 1e9) continue; // pruning
        }
        backtrack(sum + i, i, new_lcm);
    }
}

void solve() {
    cin >> n;
    ans = 0;
    backtrack(0, 1, 0);
    cout << ans << ln;
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