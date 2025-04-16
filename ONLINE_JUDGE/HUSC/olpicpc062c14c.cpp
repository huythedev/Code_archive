// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc062c14c
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc062c14c"
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

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<pair<int, int>> swaps(m);
    for (int i = 0; i < m; ++i) {
        cin >> swaps[i].first >> swaps[i].second;
        swaps[i].first--;
        swaps[i].second--;
    }

    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    };

    auto unite = [&](int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    };

    for (const auto& p : swaps) {
        unite(p.first, p.second);
    }

    vector<vector<int>> components(n);
    for (int i = 0; i < n; i++) {
        components[find(i)].push_back(i);
    }

    vector<int> target = arr;
    sort(target.begin(), target.end(), greater<int>());
    
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (components[i].empty()) continue;
        
        vector<int> vals;
        for (int idx : components[i]) {
            vals.push_back(arr[idx]);
        }
        sort(vals.begin(), vals.end(), greater<int>());
        
        for (int j = 0; j < vals.size(); j++) {
            int pos = components[i][j];
            if (target[pos] != vals[j]) {
                cout << "NO" << ln;
                return 0;
            }
        }
    }
    
    cout << "YES" << ln;

    time();
    return 0;
}