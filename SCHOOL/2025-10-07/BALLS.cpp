// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BALLS"
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

const ll INF = -3e18;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int k = 0; k < q; ++k) {
        ll a, b;
        cin >> a >> b;

        vector<ll> vec(n + 1, INF);
        
        ll max1 = 0, max2 = 0;
        int color1 = 0, color2 = -1;
        
        ll ans = 0;

        for (int i = 0; i < n; ++i) {
            ll val = v[i];
            int curr_color = c[i];

            ll score_same = vec[curr_color] + val * a;
            
            ll maxDiff = (curr_color != color1) ? max1 : max2;
            ll scoreDiff = maxDiff + val * b;

            ll curr_dp = max(score_same, scoreDiff);
            
            vec[curr_color] = max(vec[curr_color], curr_dp);

            if (curr_color == color1) {
                max1 = max(max1, vec[curr_color]);
            } 
            else if (vec[curr_color] > max1) {
                max2 = max1;
                color2 = color1;
                max1 = vec[curr_color];
                color1 = curr_color;
            }
            else if (curr_color != color2 && vec[curr_color] > max2) {
                max2 = vec[curr_color];
                color2 = curr_color;
            }
            
            ans = max(ans, curr_dp);
        }

        cout << ans << ln;
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