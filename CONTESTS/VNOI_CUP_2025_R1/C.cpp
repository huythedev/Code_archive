// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

const int MOD = 1e9 + 7;

class Fenwick {
private:
    vector<ll> tree;
    int n;
public:
    Fenwick(int _n) : n(_n), tree(_n + 1, 0) {}
    void add(int i, ll v) {
        while (i <= n) {
            tree[i] += v;
            i += i & -i;
        }
    }
    ll sum(int i) {
        ll res = 0;
        while (i > 0) {
            res += tree[i];
            i -= i & -i;
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Fenwick tree(q);
    vector<ll> vec(n + 1, 0);
    vector<vector<pair<int, ll>>> vec2(n + 1);
    vector<int> vec3(n + 1, 0);
    
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int p; ll z;
            cin >> p >> z;
            vec[p] += z;
            vec2[p].push_back({i, z});
        } else if (type == 2) {
            ll v; cin >> v;
            tree.add(i, v);
        } else if (type == 3) {
            int p; cin >> p;
            ll sum_z = 0;
            for (auto& [s, z] : vec2[p]) {
                sum_z += z;
            }
            ll balance = 0;
            ll tmp = 0;
            int previous_time = vec3[p];
            for (auto& [s, z] : vec2[p]) {
                ll sum_v = tree.sum(s - 1) - tree.sum(previous_time);
                ll temp = (vec[p] - sum_z + tmp) % MOD;
                balance = (balance + (sum_v % MOD) * temp % MOD) % MOD;
                tmp += z;
                previous_time = s;
            }
            ll sum_v = tree.sum(i - 1) - tree.sum(previous_time);
            ll temp = (vec[p] - sum_z + tmp) % MOD;
            balance = (balance + (sum_v % MOD) * temp % MOD) % MOD;
            cout << balance << ln;
            vec2[p].clear();
            vec3[p] = i;
        }
    }
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