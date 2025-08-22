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

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) 
            return false;
            
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } 
        else {
            parent[py] = px;
            if (rank[px] == rank[py]) 
                rank[px]++;
        }
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vec[i] = {{a - 1, b - 1}, i + 1};
    }

    DSU dsu(2 * n);
    vector<bool> vec2(n + 1, false);
    for (int i = 0; i < n; ++i) {
        int a = vec[i].first.first;
        int b = vec[i].first.second;

        int idx = vec[i].second;

        if (dsu.unite(a, b)) {
            vec2[idx] = true;
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        if (vec2[i]) {
            res.push_back(i);
        }
    }

    cout << (int)res.size() << ln;
    for (int x : res) {
        cout << x << ' ';
    }
    cout << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}