// Author: huythedev
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "SAPXEP"
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

int sus;
bool comp(vector <int> &a, vector<int> &b) {
    return a[sus] < b[sus];
}

signed main() {
    fastio();
    docfile();

    int m, n, s, q; cin >> m >> n >> s >> q;
    vector<vector<int>> table(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> table[i][j];
    }
    vector<int> queries(s);
    for (int i = 0; i < s; ++i) {
        cin >> queries[i];
        queries[i]--;
    }

    vector<int> d(q), u(q), v(q);
    bool all_same = true;
    for (int i = 0; i < q; ++i) {
        cin >> d[i] >> u[i] >> v[i];
        d[i]--; u[i]--; v[i]--;
        if (d[i] != d[i - 1] && i > 0) all_same = false;
    }

    // Subtask 1: all d = 1
    if (all_same) {
        for (int i = 0; i < s; ++i) {
            if (i == d[0]) continue;
            sus = queries[i];
            // sort(table.begin(), table.end(), comp);
            vector<int> vec(m);
            for (int i = 0; i < m; ++i) {
                vec[i] = table[i][sus];
            }
            sort(vec.begin(), vec.end());
            for (int i = 0; i < m; ++i) {
                table[i][sus] = vec[i];
            }
        }
        for (int i = 0; i < q; ++i) {
            cout << table[u[i]][v[i]] << ln;
        }
    }
    else {
        while(q--) {
            vector<vector<int>> table2 = table;
            int d, u, v; cin >> d >> u >> v;
            d--; u--; v--;
            for (int i = 0; i < s; ++i) {
                if (i == d) continue;
                sus = queries[i];
                sort(table2.begin(), table2.end(), comp);
                // for (int i = 0; i < m; ++i) {
                //     for (int j = 0; j < n; ++j)
                //         cout << table2[i][j];
                //     cout << ln;
                // }
                // cout << "======" << ln;
            }

            // for (int i = 0; i < m; ++i) {
            //     for (int j = 0; j < n; ++j)
            //         cout << table2[i][j];
            //     cout << ln;
            // }
            // cout << "------------" << ln;
            cout << table2[u][v] << ln;
        }
    }

    time();
    return 0;
}