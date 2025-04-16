// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc038c09e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc038c09e"
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

    int n, k;
    cin >> n >> k;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<bool> inMST(n, false);
    vector<ll> minEdge(n, LLONG_MAX);
    minEdge[0] = 0;
    ll totalWeight = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }

        inMST[u] = true;
        totalWeight += minEdge[u];

        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                ll edgeWeight = 1LL * k * (weights[u] + weights[v]);
                if (edgeWeight < minEdge[v]) {
                    minEdge[v] = edgeWeight;
                }
            }
        }
    }

    cout << totalWeight << ln;

    time();
    return 0;
}