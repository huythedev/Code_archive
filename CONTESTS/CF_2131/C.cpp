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

ll dist(ll x, ll k) {
    ll rem = x % k;
    ll tmp = (k - rem) % k;
    return min(rem, tmp);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> S(n), T(n);
    for (int i = 0; i < n; ++i) 
        cin >> S[i];
    for (int i = 0; i < n; ++i) 
        cin >> T[i];

    unordered_map<ll, ll> cnt;
    cnt.reserve(n * 2);

    for (auto x : S) 
        ++cnt[dist(x, k)];

    for (auto x : T) 
        --cnt[dist(x, k)];

    bool ok = true;
    for (auto &p : cnt) {
        if (p.second != 0) { 
            ok = false; 
            break; 
        }
    }

    if (ok) cout << "YES" << ln;
    else cout << "NO" << ln;
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