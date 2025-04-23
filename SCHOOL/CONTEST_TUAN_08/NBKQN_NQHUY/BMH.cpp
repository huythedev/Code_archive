// Author: huythedev (https://huythedev.com)
// Problem Link:

#include <bits/stdc++.h>
using namespace std;

#define NAME "BMH"
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

signed main() {
    fastio();
    docfile();

    double k;
    int houses, roads, attended;
    cin >> houses >> roads >> attended >> k;

    queue<pair<int, int>> q;
    for (int i = 0; i < attended; i++) {
        int a;
        cin >> a;
        q.push({a - 1, 0});
    }

    vector<vector<int>> g(houses);
    for (int i = 0; i < roads; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> ans(houses, -1);
    while (q.size()) {
        auto [v, d] = q.front();
        q.pop();

        if (ans[v] != -1)
            continue;
        ans[v] = ceil((sqrt(k * k / 4 + 2 * k * d) - k / 2) / k);

        for (auto ch : g[v])
            if (ans[v] != -1)
                q.push({ch, d + 1});
    }

    for (auto i : ans)
        cout << i << ' ';

    time();
    return 0;
}
