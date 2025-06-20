// Author: huythedev
// Problem Link: https://codeforces.com/contest/2110/problem/E
#include <bits/stdc++.h>
using namespace std;
 
#define NAME "E"
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
 
class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;
    }
    int find(int p) {
        if (parent[p] != p) parent[p] = find(parent[p]);
        return parent[p];
    }
    void unite(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        if (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else {
            parent[rootQ] = rootP;
            if (rank[rootP] == rank[rootQ]) rank[rootP]++;
        }
    }
};

void dfs(int current, int last_type, vector<int>& path, vector<bool>& visited, 
         const vector<ll>& v, const vector<ll>& p, 
         const unordered_map<ll, vector<int>>& vol, 
         const unordered_map<ll, vector<int>>& pitch, 
         bool& found, int n) {
    path.push_back(current);
    visited[current] = true;
    if (path.size() == n) {
        found = true;
        cout << "YES\n";
        for (int idx : path) cout << idx + 1 << " ";
        cout << endl;
        return;
    }
    vector<int> types = (last_type == -1) ? vector<int>{0, 1} : vector<int>{1 - last_type};
    for (int type : types) {
        const auto& neighbors = (type == 0 ? vol.at(v[current]) : pitch.at(p[current]));
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                dfs(neighbor, type, path, visited, v, p, vol, pitch, found, n);
                if (found) return;
            }
        }
    }
    path.pop_back();
    visited[current] = false;
}

void solve() {
    int n; cin >> n;
    vector<ll> v(n), p(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> p[i];

    UnionFind uf(n);
    unordered_map<ll, vector<int>> vol, pitch;
    for (int i = 0; i < n; i++) {
        vol[v[i]].push_back(i);
        pitch[p[i]].push_back(i);
    }

    for (const auto& i : vol) {
        const vector<int>& sounds = i.second;
        for (size_t j = 1; j < sounds.size(); j++) uf.unite(sounds[0], sounds[j]);
    }
    
    for (const auto& i : pitch) {
        const vector<int>& sounds = i.second;
        for (size_t j = 1; j < sounds.size(); j++) uf.unite(sounds[0], sounds[j]);
    }

    int root = uf.find(0);
    bool connected = true;
    for (int i = 1; i < n; i++) {
        if (uf.find(i) != root) {
            connected = false;
            break;
        }
    }
    if (!connected) {
        cout << "NO" << ln;
        return;
    }
    
    vector<bool> visited(n, false);
    vector<int> path;
    bool found = false;
    for (int start = 0; start < n && !found; start++) {
        dfs(start, -1, path, visited, v, p, vol, pitch, found, n);
        fill(visited.begin(), visited.end(), false);
        path.clear();
    }
    if (!found) cout << "NO" << ln;
}
 
signed main() {
    docfile();
    fastio();
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
 
    time();
    return 0;
}