// Author: NBK.VaiLatXucXich
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

void solve() {
    int n, m; 
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        ++deg[u];
        ++deg[v];
    }

    int K = n - 1;
    vector<vector<ld>> vec(K, vector<ld>(K + 1, 0));

    for (int i = 1; i <= n - 1; ++i) 
        vec[i - 1][i - 1] = deg[i];
    
    for (auto [u, v] : edges) {
        if (u < n && v < n) {
            vec[u - 1][v - 1] -= 1;
            vec[v - 1][u - 1] -= 1;
        }
    }

    vec[0][K] = 1;

    const ld EPS = 1e-12L;
    for (int i = 0; i < K; ++i) {
        int tmp = i;
        for (int r = i + 1; r < K; ++r)
            if (abs(vec[r][i]) > abs(vec[tmp][i])) 
        
        tmp = r;
        if (abs(vec[tmp][i]) < EPS) 
            continue;
        if (tmp != i) 
            swap(vec[tmp], vec[i]);

        ld tmp2 = vec[i][i];
        for (int c = i; c <= K; ++c) 
            vec[i][c] /= tmp2;
        
        for (int r = 0; r < K; ++r) {
            if (r != i) {
                ld tmp3 = vec[r][i];
                if (abs(tmp3) < EPS) 
                    continue;
                for (int c = i; c <= K; ++c) 
                    vec[r][c] -= tmp3 * vec[i][c];
            }
        }
    }

    vector<ld> vec2(K, 0);
    for (int i = 0; i < K; ++i) 
        vec2[i] = vec[i][K];

    vector<ld> cnt;
    cnt.reserve(m);
    for (auto [u, v] : edges) {
        ld c = 0;
        if (u < n) c += vec2[u - 1];
        if (v < n) c += vec2[v - 1];
        cnt.push_back(c);
    }

    sort(cnt.begin(), cnt.end(), greater<ld>());

    ld ans = 0;
    for (int i = 0; i < m; ++i) 
        ans += cnt[i] * (ld)(i + 1);

    cout << fixed << setprecision(3) << ans << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}