// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "SAUDI"
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

void subtask1(int n) {
    for (int i = 0; i < n; ++i) {
        if (i == 0 || i == n - 1) cout << 1 << ' ';
        else cout << 2 << ' ';
    }
}

void solve() {
    int n;
    cin >> n;
    string D;
    cin >> D;

    vector<vector<int>> adj(n + 1);

    vector<int> boundary_N = {1};
    vector<int> boundary_E = {1};
    vector<int> boundary_W = {1};
    vector<int> boundary_S = {1};

    for (int i = 2; i <= n; i++) {
        char d = D[i - 2];

        vector<int>* boundary;
        if (d == 'N') boundary = &boundary_N;
        else if (d == 'E') boundary = &boundary_E;
        else if (d == 'W') boundary = &boundary_W;
        else boundary = &boundary_S;

        for (int j : *boundary) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        if (d == 'N') {
            boundary_N = {i};
            boundary_E.push_back(i);
            boundary_W.push_back(i);
        } else if (d == 'E') {
            boundary_E = {i};
            boundary_N.push_back(i);
            boundary_S.push_back(i);
        } else if (d == 'W') {
            boundary_W = {i};
            boundary_N.push_back(i);
            boundary_S.push_back(i);
        } else if (d == 'S') {
            boundary_S = {i};
            boundary_E.push_back(i);
            boundary_W.push_back(i);
        }

        if (d == 'S' && adj[i].size() > 2) {
            vector<int> temp = adj[i];
            adj[i].clear();
            adj[i].push_back(temp[temp.size() - 2]);
            adj[i].push_back(temp[temp.size() - 1]);
            for (int j : temp) {
                auto it = find(adj[j].begin(), adj[j].end(), i);
                if (it != adj[j].end() && (j != adj[i][0] && j != adj[i][1])) {
                    adj[j].erase(it);
                }
            }
            int p = adj[i][0];
            int q = adj[i][1];
            if (find(adj[p].begin(), adj[p].end(), q) == adj[p].end()) {
                adj[p].push_back(q);
                adj[q].push_back(p);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << adj[i].size();
        if (i < n) cout << " ";
    }
    cout << ln;
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