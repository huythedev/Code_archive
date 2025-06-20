// Author: huythedev
// Problem Link: https://codeforces.com/contest/2118/problem/D2
#include <bits/stdc++.h>
using namespace std;

#define NAME "D2"
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

int query_id = 0;
vector<int> last_visit(2 * 200005, -1);

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<ll> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    int q;
    cin >> q;
    vector<ll> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }
    for (int query = 0; query < q; ++query) {
        ll a_j = a[query];
        query_id++;
        if (a_j > p[n - 1]) {
            cout << "YES\n";
            continue;
        }
        auto iter = lower_bound(p.begin(), p.end(), a_j);
        int pos;
        int from_dir;
        ll t_mod;
        if (iter != p.end() && *iter == a_j) {
            pos = iter - p.begin();
            from_dir = 1;
            t_mod = 0;
        } else if (iter == p.begin()) {
            pos = 0;
            from_dir = 1;
            t_mod = (p[0] - a_j) % k;
            if (t_mod < 0) t_mod += k;
        } else {
            pos = iter - p.begin();
            t_mod = (p[pos] - a_j) % k;
            if (t_mod < 0) t_mod += k;
            from_dir = 1;
        }
        bool escaped = false;
        bool cycle = false;
        while (true) {
            int state_id = pos * 2 + (from_dir == 1 ? 0 : 1);
            if (last_visit[state_id] == query_id) {
                cycle = true;
                break;
            }
            last_visit[state_id] = query_id;
            int next_pos;
            ll distance;
            if (from_dir == 1) {
                if (t_mod == d[pos]) {
                    if (pos == 0) {
                        escaped = true;
                        break;
                    }
                    next_pos = pos - 1;
                    distance = p[pos] - p[next_pos];
                    t_mod = (t_mod + distance) % k;
                    from_dir = -1;
                } else {
                    if (pos == n - 1) {
                        escaped = true;
                        break;
                    }
                    next_pos = pos + 1;
                    distance = p[next_pos] - p[pos];
                    t_mod = (t_mod + distance) % k;
                    from_dir = 1;
                }
            } else {
                if (t_mod == d[pos]) {
                    if (pos == n - 1) {
                        escaped = true;
                        break;
                    }
                    next_pos = pos + 1;
                    distance = p[next_pos] - p[pos];
                    t_mod = (t_mod + distance) % k;
                    from_dir = 1;
                } else {
                    if (pos == 0) {
                        escaped = true;
                        break;
                    }
                    next_pos = pos - 1;
                    distance = p[pos] - p[next_pos];
                    t_mod = (t_mod + distance) % k;
                    from_dir = -1;
                }
            }
            pos = next_pos;
        }
        cout << (escaped ? "YES" : "NO") << "\n";
    }
}

signed main() {
    docfile();
    fastio();
    int t = 1;
    while (t--) {
        solve();
    }
    time();
    return 0;
}