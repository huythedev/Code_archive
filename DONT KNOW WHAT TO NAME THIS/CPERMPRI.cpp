// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "prim"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

const int INF = 999999;
const int MAX = 1000;

int n, m;
vector<pair<int, int>> ds[MAX];
int *d, *near, *S;
pair<int, int> T[MAX];

int main() {
    fastio();
    docfile();

    cin >> n >> m;
    d = new int[n + 1];
    near = new int[n + 1];
    S = new int[n + 1];

    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        ds[u].push_back({v, w});
        ds[v].push_back({u, w});
    }

    for (int vertex = 1; vertex <= n; vertex++) {
        for (auto &edge : ds[vertex]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << ln;
    }

    d[1] = 0;
    near[1] = 1;
    S[1] = 1;

    for (int i = 2; i <= n; i++) {
        S[i] = 0;
        near[i] = 1;
        d[i] = INF;
        for (auto &edge : ds[1]) {
            if (edge.first == i) {
                d[i] = edge.second;
                break;
            }
        }
    }

    for (int k = 2; k <= n; k++) {
        int minWeight = INF, u = -1;

        for (int i = 1; i <= n; i++) {
            if (!S[i] && d[i] < minWeight) {
                minWeight = d[i];
                u = i;
            }
        }

        if (u == -1) break;
        S[u] = 1;
        T[k - 1] = make_pair(u, near[u]);

        for (auto &edge : ds[u]) {
            int v = edge.first, weight = edge.second;
            if (!S[v] && weight < d[v]) {
                d[v] = weight;
                near[v] = u;
            }
        }
    }

    time();
    return 0;
}
