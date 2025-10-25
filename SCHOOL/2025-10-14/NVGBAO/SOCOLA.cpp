 #include <bits/stdc++.h>
using namespace std;

#define NAME "SOCOLA"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
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
    int n, q;
    cin >> n >> q;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    sort(c.begin(), c.end());

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) 
        pref[i] = pref[i - 1] + c[i - 1];
    
    ll total = pref[n];

    auto getA = [&](int y)->ll {
        return c[y - 1];
    };
    auto getB = [&](ll k, int x)->ll {
        return 2 * k - c[n - x];
    };

    while (q--) {
        ll k; int m;
        cin >> k >> m;

        int p = int(lower_bound(c.begin(), c.end(), k) - c.begin());
        int nb = n - p;

        int xmin = max(0, m - p);
        int xmax = min(m, nb);

        int l = xmin, r = xmax, x_found = xmin;
        while (l <= r) {
            int x = (l + r) / 2;
            int y = m - x; 
            
            ll A_left  = (y > 0) ? getA(y) : LLONG_MIN;
            ll A_right = (y < p) ? getA(y + 1) : LLONG_MAX;
            ll B_left  = (x > 0) ? getB(k, x) : LLONG_MIN;
            ll B_right = (x < nb) ? getB(k, x + 1) : LLONG_MAX;

            if (A_left <= B_right && B_left <= A_right) {
                x_found = x;
                break;
            } 
            else if (A_left > B_right) {
                l = x + 1;
            } 
            else {
                r = x - 1;
            }
        }

        int x = x_found;
        int y = m - x;
        ll sumA = pref[y];
        ll sumLargestX = total - pref[n - x];
        ll sumB = 2*k*x - sumLargestX;

        cout << (sumA + sumB) << ln;
    }
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}