// Author: huythedev

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define NAME "BAI4"
#define ln "\n"

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME".INP")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}

void time() {
    cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s." << ln;
}

const int INF = INT_MAX;

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> C[i][j];
        }
    }

    vector<vector<int>> dist = C;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    vector<int> D(n);
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }

    ll res = LLONG_MAX;
    for (int k = 0; k < n; ++k) {
        ll total = 0;
        for (int i = 0; i < n; ++i) {
            total += dist[i][k];
        }
        total += D[k];
        if (total < res) {
            res = total;
        }
    }

    cout << res;

    time();
    return 0;
}