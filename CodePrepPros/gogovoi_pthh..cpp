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

ll cost(int x, ll v, const vector<ll>& prefixSum, const vector<ll>& suffixSum, int d) {
    ll leftCost  = v * 1LL * x - (prefixSum[x] - prefixSum[0]);
    ll rightCost = suffixSum[d - x] - v * 1LL * (d - x);
    return leftCost + rightCost;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    vector<pair<ll,int>> vec;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == a[i]) 
            ++j;

        vec.push_back({a[i], j - i});
        i = j;
    }
    
    int m = (int)vec.size();
    int l = 0, r = m - 1;
    ll cl = vec[l].second, cr = vec[r].second, ans = LLONG_MAX, cur = 0;
    while (true) {
        if (cl >= k || cr >= k) {
            ans = min(ans, cur);
            break;
        }

        if (l >= r) 
            break;

        if (cl <= cr) {
            ll gap = vec[l+1].first - vec[l].first;
            ll need = k - cl;

            if (cl + need >= k) {
                ans = min(ans, cur + need);
            }

            if (cl * gap < need) {
                cur += cl * gap;
                l++;
                cl += vec[l].second;
            } 
            else {
                ans = min(ans, cur + need);
                break;
            }
        } 
        else {
            ll gap = vec[r].first - vec[r-1].first;
            ll need = k - cr;

            if (cr + need >= k) {
                ans = min(ans, cur + need);
            }

            if (cr * gap < need) {
                cur += cr * gap;
                r--;
                cr += vec[r].second;
            } 
            else {
                ans = min(ans, cur + need);
                break;
            }
        }
    }
    
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