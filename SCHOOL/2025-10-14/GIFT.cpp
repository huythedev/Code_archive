// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "GIFT"
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
    int K, M, N;
    cin >> K >> M >> N;

    vector<ll> P(K), W(K);
    for (int i = 0; i < K; ++i) cin >> P[i] >> W[i];

    vector<ll> F(M);
    for (int j = 0; j < M; ++j) cin >> F[j];
    sort(F.begin(), F.end());

    int G = M + 1;

    vector<vector<pair<ll,ll>>> LeftR(G), RightL(G);
    vector<ll> midSum(G, 0), edgeSum(G, 0);

    for (int i = 0; i < K; ++i) {
        ll p = P[i], w = W[i];
        auto it = lower_bound(F.begin(), F.end(), p);
        if (it == F.begin()) {
            edgeSum[0] += w;
        } else if (it == F.end()) {
            edgeSum[M] += w;
        } else {
            int g = int(it - F.begin());
            ll L = F[g-1], R = F[g];
            ll s = L + R;
            if (2 * p < s) {
                ll r = 2 * p - L;
                LeftR[g].push_back({r, w});
            } else if (2 * p > s) {
                ll l = 2 * p - R;
                RightL[g].push_back({l, w});
            } else {
                midSum[g] += w;
            }
        }
    }

    vector<ll> gains;
    gains.reserve(2 * (M + 1));

    gains.push_back(edgeSum[0]);
    gains.push_back(0);

    for (int g = 1; g <= M - 1; ++g) {
        auto &Lvec = LeftR[g];
        auto &Rvec = RightL[g];
        sort(Lvec.begin(), Lvec.end());
        sort(Rvec.begin(), Rvec.end());

        ll sumLeft = 0, sumRight = 0;
        for (auto &e : Lvec) sumLeft += e.second;
        for (auto &e : Rvec) sumRight += e.second;
        ll L_suf = sumLeft, R_pre = 0;
        ll mx = midSum[g] + L_suf + R_pre;

        size_t i = 0, j = 0;
        while (i < Lvec.size() || j < Rvec.size()) {
            ll xr = (i < Lvec.size() ? Lvec[i].first : LLONG_MAX);
            ll xl = (j < Rvec.size() ? Rvec[j].first : LLONG_MAX);
            ll x = min(xr, xl);

            while (j < Rvec.size() && Rvec[j].first == x) {
                R_pre += Rvec[j].second;
                ++j;
            }

            mx = max(mx, midSum[g] + L_suf + R_pre);

            while (i < Lvec.size() && Lvec[i].first == x) {
                L_suf -= Lvec[i].second;
                ++i;
            }
        }

        ll sum = midSum[g] + sumLeft + sumRight; 
        gains.push_back(mx);
        gains.push_back(sum - mx);
    }

    gains.push_back(edgeSum[M]);
    gains.push_back(0);

    nth_element(gains.begin(), gains.begin() + min<ll>(N, gains.size()), gains.end(), greater<ll>());
    sort(gains.begin(), gains.begin() + min<ll>(N, gains.size()), greater<ll>());

    ll ans = 0;
    for (int i = 0; i < N && i < (int)gains.size(); ++i) ans += gains[i];
    cout << ans << ln;
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