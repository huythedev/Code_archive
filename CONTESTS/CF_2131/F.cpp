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
    string a, b;
    cin >> n >> a >> b;

    vector<int> prefA(n), prefB(n);

    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] - '0') != a[0] - '0') 
            ++cntA;
        prefA[i] = cntA;

        if ((b[i] - '0') != a[0] - '0') 
            ++cntB;
        prefB[i] = cntB;
    }

    vector<int> u(n), v(n);
    for (int i = 1; i <= n; ++i) {
        u[i - 1] = i - 2 * prefA[i - 1];
        v[i - 1] = i - 2 * prefB[i - 1];
    }
        
    sort(v.begin(), v.end());

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) 
        pref[i + 1] = pref[i] + v[i];

    ll sum = 0;
    for (int x : u) {
        int idx = lower_bound(v.begin(), v.end(), -x) - v.begin();
        sum += 1LL * x * (n - idx * 2) + (pref[n] - pref[idx] * 2);
    }

    ll ans = (1LL * n * n * (n + 1) - sum) / 2;
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