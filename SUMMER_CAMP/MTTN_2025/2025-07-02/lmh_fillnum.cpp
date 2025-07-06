// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "lmh_fillnum"
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
const int MAXN = 1e7 + 5;
vector<ll> vec(MAXN), vec2(MAXN);

struct Query {
    int i, j, c;
};

ll get(int l, int r, ll k) {
    if (l > r) 
        return 0;
    ll res = vec2[r];
    if (l > 0)
        res = (res - vec2[l - 1] + k) % k;
    
    return res;
}

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<Query> queries(m);
    for (int i = 0; i < m; ++i)
        cin >> queries[i].i >> queries[i].j >> queries[i].c;

    vec[0] = 1;
    vec2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vec[i] = (vec[i - 1] * 10) % k;
        vec2[i] = (vec2[i - 1] + vec[i]) % k;
    }

    ll res = 0;
    map<int, int> mp;

    for (int q_idx = m - 1; q_idx >= 0; --q_idx) {
        int i = queries[q_idx].i;
        int j = queries[q_idx].j;
        int c = queries[q_idx].c;

        int pos = i;
        while (pos <= j) {
            auto it = mp.upper_bound(pos);
            if (it != mp.begin()) {
                auto prev_it = prev(it);
                if (prev_it->second >= pos) {
                    pos = prev_it->second + 1;
                    continue;
                }
            }

            int end_pos = j;
            if (it != mp.end()) {
                end_pos = min(end_pos, it->first - 1);
            }

            if (pos <= end_pos) {
                if (c != 0)
                    res = (res + (ll)c * get(n - end_pos, n - pos, k)) % k;

                int tmp = pos;
                int tmp2 = end_pos;

                auto next_it = mp.upper_bound(tmp);
                if (next_it != mp.end() && next_it->first == tmp2 + 1) {
                    tmp2 = next_it->second;
                    mp.erase(next_it);
                }

                auto prev_it = mp.upper_bound(tmp);
                if (prev_it != mp.begin()) {
                    --prev_it;
                    if (prev_it->second == tmp - 1) {
                        tmp = prev_it->first;
                        mp.erase(prev_it);
                    }
                }
                mp[tmp] = tmp2;
            }
            pos = end_pos + 1;
        }
    }
    
    cout << res << ln;
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