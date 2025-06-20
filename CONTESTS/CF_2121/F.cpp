// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

ll count(const vector<ll>& a, ll s, ll x, bool leq) {
    ll res = 0;
    int n = a.sz;
    int i = 0;
    while (i < n) {
        if (leq ? (a[i] <= x) : (a[i] < x)) {
            int j = i;
            while (j < n && (leq ? (a[j] <= x) : (a[j] < x))) 
                ++j;

            ll curr_sum = 0;
            map<ll, int> freq;
            freq[0] = 1;
            ll cnt = 0;

            for (int k = i; k < j; ++k) {
                curr_sum += a[k];
                if (freq.count(curr_sum - s)) 
                    cnt += freq[curr_sum - s];

                freq[curr_sum]++;
            }

            res += cnt;
            i = j;
        } 
        else 
            ++i;
    }

    return res;
}

void solve() {
    int n; ll s, x; cin >> n >> s >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    cout << count(a, s, x, true) - count(a, s, x, false) << ln;
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