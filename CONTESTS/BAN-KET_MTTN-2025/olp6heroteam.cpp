// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6heroteam

#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6heroteam"
#define ln "\n"

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

const ll MOD = 998244353;

int func(ll x) {
    return (x > 0) ? 1 : ((x < 0) ? -1 : 0);
}

struct Hero {
    ll power, skill;
};

ll powMod(ll base, int exp, const ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

struct Fenwick {
    vector<ll> tree[4];
    int n;
    Fenwick(int sz) : n(sz) {
        for (int m = 0; m < 4; m++) tree[m].resize(n + 1, 0);
    }
    void update(int idx, ll power, ll val, int D) {
        idx++;
        while (idx <= n) {
            for (int m = 0; m <= D; m++) {
                ll term = (m == 0 ? 1 : powMod(power, m, MOD)) * val % MOD;
                tree[m][idx] = (tree[m][idx] + term) % MOD;
            }
            idx += idx & -idx;
        }
    }
    ll query(int idx, int m) {
        idx++;
        ll sum = 0;
        while (idx > 0) {
            sum = (sum + tree[m][idx]) % MOD;
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<Hero> heroes(n);
    for (int i = 0; i < n; i++) {
        cin >> heroes[i].power >> heroes[i].skill;
    }
    sort(heroes.begin(), heroes.end(), [](const Hero& a, const Hero& b) {
        return a.power < b.power;
    });

    ll res = 0;
    for (int j = 1; j < n - 1; j++) {
        ll yj = heroes[j].skill, pj = heroes[j].power;
        vector<vector<pair<ll, ll>>> tmp(3);
        for (int i = 0; i < j; i++) {
            ll xi = heroes[i].skill;
            int s1 = func(xi - yj) + 1;
            tmp[s1].push_back({heroes[i].power, xi});
        }
        for (int s1_idx = 0; s1_idx < 3; s1_idx++) {
            sort(tmp[s1_idx].begin(), tmp[s1_idx].end(),
                 [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
                     return a.second < b.second;
                 });
            vector<pair<ll, int>> vec;
            for (int i = 0; i < tmp[s1_idx].size(); i++) {
                ll xi = tmp[s1_idx][i].second;
                ll a = yj - xi, b = xi * yj;
                ll disc = a * a - 4 * b;
                if (disc >= 0) {
                    double r1 = (-a - sqrt(disc)) / 2.0;
                    double r2 = (-a + sqrt(disc)) / 2.0;
                    vec.push_back({(ll)ceil(r1), i});
                    vec.push_back({(ll)floor(r2) + 1, i});
                }
            }
            sort(vec.begin(), vec.end());
            Fenwick ft(j);
            int s1 = s1_idx - 1;
            vector<int> active(j, 0);
            int evt = 0;
            vector<pair<ll, int>> right(n - j - 1);
            for (int k = j + 1; k < n; k++) {
                right[k - j - 1] = {heroes[k].skill, k};
            }
            sort(right.begin(), right.end());
            int r = 0;
            while (r < right.size() || evt < vec.size()) {
                ll zk;
                int k_idx = -1;
                if (evt >= vec.size() || (r < right.size() && right[r].first <= (evt < vec.size() ? vec[evt].first : LLONG_MAX))) {
                    zk = right[r].first;
                    k_idx = right[r].second;
                    r++;
                } 
                else {
                    zk = vec[evt].first;
                    int i = vec[evt].second;
                    active[i] ^= 1;
                    ll pi = tmp[s1_idx][i].first;
                    ft.update(i, pi, active[i] ? 1 : -1, 3);
                    evt++;
                    continue;
                }
                ll pk = heroes[k_idx].power;
                int l = 0, h = j - 1, start = j;
                while (l <= h) {
                    int mid = (l + h) / 2;
                    if (heroes[mid].power > pk - pj) {
                        start = mid;
                        h = mid - 1;
                    } 
                    else {
                        l = mid + 1;
                    }
                }
                for (int i = 0; i < tmp[s1_idx].size(); i++) {
                    ll xi = tmp[s1_idx][i].second, pi = tmp[s1_idx][i].first;
                    if (pi <= pk - pj) continue;
                    int s2 = func(xi * yj - xi * zk + zk * zk - yj * zk);
                    int D = 1 + abs(s1) + abs(s2);
                    if (D > 3) continue;
                    ft.update(i, pi, active[i] ? -1 : 1, 3);
                    active[i] ^= 1;
                    ft.update(i, pi, active[i] ? 1 : -1, 3);
                }
                if (start < j) {
                    ll c = (pj + pk) % MOD;
                    for (int s2_idx = 0; s2_idx < 3; s2_idx++) {
                        int s2 = s2_idx - 1;
                        int D = 1 + abs(s1) + abs(s2);
                        if (D > 3) continue;
                        ll sum[4] = {0};
                        for (int m = 0; m <= D; m++) {
                            sum[m] = ft.query(j - 1, m) - (start > 0 ? ft.query(start - 1, m) : 0);
                            if (sum[m] < 0) sum[m] += MOD;
                        }
                        ll total = 0;
                        for (int m = 0; m <= D; m++) {
                            ll coef = 1;
                            for (int t = 0; t < m; t++) coef = coef * D % MOD;
                            for (int t = m + 1; t <= D; t++) coef = coef * (D - t) % MOD;
                            ll term = coef * powMod(c, D - m, MOD) % MOD * sum[m] % MOD;
                            total = (total + term) % MOD;
                        }
                        res = (res + total) % MOD;
                    }
                }
            }
        }
    }
    cout << res << ln;

    time();
    return 0;
}
