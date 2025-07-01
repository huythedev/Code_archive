// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "stalingrad"
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

const int MAXN = 400005;

int n, q;
vector<int> adj[MAXN];
int parent[MAXN], treeSize[MAXN], cnt[MAXN];
bool is_occupied[MAXN];
pair<ll, ll> dp[MAXN], solution[MAXN];

void dfs_precompute(int u, int p) {
    parent[u] = p;
    treeSize[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_precompute(v, u);
        treeSize[u] += treeSize[v];
    }
}

pair<ll, ll> calc(int u) {
    if (cnt[u] == 0) {
        return {0, 0};
    }
    
    pair<ll, ll> propagate_option = {1, (ll)treeSize[u] - cnt[u]};
    if (is_occupied[u]) {
        return propagate_option;
    }
    
    return min(propagate_option, solution[u]);
}

void solve() {
    int subtask;
    cin >> subtask;
    cin >> n >> q;

    vector<int> vec(n + 1);
    bool ok = true;
    for (int i = 2; i <= n; ++i) {
        cin >> vec[i];
        if (vec[i] != i - 1)
            ok = false;
    }

    if (ok) {
        set<int> st;
        for (int k = 0; k < q; ++k) {
            char type; int v;
            cin >> type >> v;
            if (type == '+')
                st.insert(v);
            else
                st.erase(v);
            
            if (st.empty())
                cout << "0 0" << ln;
            else {
                int min_v = *st.begin();
                ll cost = (ll)n - min_v + 1 - st.size();
                cout << 1 << " " << cost << ln;
            }
        }
    } 
    else {
        for (int i = 2; i <= n; ++i) {
            adj[vec[i]].push_back(i);
            adj[i].push_back(vec[i]);
        }

        dfs_precompute(1, 0);

        for (int k = 0; k < q; ++k) {
            char type; int v;
            cin >> type >> v;

            int delta = (type == '+') ? 1 : -1;
            is_occupied[v] = (type == '+');
            
            int curr = v;
            while (curr != 0) {
                pair<ll, ll> old_dp = dp[curr];
                
                cnt[curr] += delta;
                
                pair<ll, ll> new_dp = calc(curr);
                
                dp[curr] = new_dp;
                
                int p = parent[curr];
                if (p != 0) {
                    solution[p].first += new_dp.first - old_dp.first;
                    solution[p].second += new_dp.second - old_dp.second;
                }

                curr = p;
            }
            cout << solution[1].first << " " << solution[1].second << ln;
        }
    }
}

signed main() {
    docfile();
    fastio();

    solve();
    
    time();
    return 0;
}