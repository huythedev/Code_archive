// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "hamming"
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
    int subtask; cin >> subtask;
    ll m, n; cin >> m >> n;
    string a, b; cin >> a >> b;
 
    ll len_a = a.length(), len_b = b.length();
 
    ll common_div = gcd(len_a, len_b);
    
    ll lcm = (ll)len_a / common_div * len_b;
 
    vector<vector<int>> vec(common_div, vector<int>(26, 0));
    for (int i = 0; i < len_a; ++i) {
        vec[i % common_div][a[i] - 'a']++;
    }
 
    ll diff = 0;
    for (int i = 0; i < len_b; ++i) {
        int idx = b[i] - 'a';
        int remainder = i % common_div;
        ll tmp = len_a / common_div;
        ll same_chars = vec[remainder][idx];
        diff += (tmp - same_chars);
    }
    
    ll total_len = (ll)m * len_a;
    ll num_lcm_blocks = total_len / lcm;
    
    ll total = diff * num_lcm_blocks;
 
    cout << total << ln;
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