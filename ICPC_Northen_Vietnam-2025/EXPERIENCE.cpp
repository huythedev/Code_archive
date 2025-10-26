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

struct Hash {
    size_t operator()(const tuple<int, int, int, int, int, int>& t) const {
        auto h1 = hash<int>{}(get<0>(t));
        auto h2 = hash<int>{}(get<1>(t));
        auto h3 = hash<int>{}(get<2>(t));
        auto h4 = hash<int>{}(get<3>(t));
        auto h5 = hash<int>{}(get<4>(t));
        auto h6 = hash<int>{}(get<5>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3) ^ (h5 << 4) ^ (h6 << 5);
    }
};

int x, y, z;
int grid[51][51][51];
int a[5001][51][51];
unordered_map<tuple<int, int, int, int, int, int>, ll, Hash> mp;
int prefix[5001][51][51];

void buildPrefix() {
    for (int k = 1; k <= x; ++k) {
        for (int i = 1; i <= y; ++i) {
            for (int j = 1; j <= z; ++j) {
                prefix[k][i][j] = a[k][i][j] 
                + prefix[k - 1][i][j] 
                + prefix[k][i - 1][j] 
                + prefix[k][i][j - 1]
                - prefix[k - 1][i - 1][j]
                - prefix[k - 1][i][j - 1]
                - prefix[k][i - 1][j - 1]
                + prefix[k - 1][i - 1][j - 1];
            }
        }
    }
}

bool hasOne(int x1, int y1, int z1, int x2, int y2, int z2) {
    int sum = prefix[x2][y2][z2]
    - prefix[x1 - 1][y2][z2]
    - prefix[x2][y1 - 1][z2]
    - prefix[x2][y2][z1 - 1]
    + prefix[x1 - 1][y1 - 1][z2]
    + prefix[x1 - 1][y2][z1 - 1]
    + prefix[x2][y1 - 1][z1 - 1]
    - prefix[x1 - 1][y1 - 1][z1 - 1];
    return sum > 0;
}

ll calc(int x1, int y1, int z1, int x2, int y2, int z2) {
    if (!hasOne(x1, y1, z1, x2, y2, z2))
        return 0;
    
    tuple<int, int, int, int, int, int> cur = {x1, y1, z1, x2, y2, z2};
    if (mp.count(cur))
        return mp[cur];
    
    ll cost = min({(ll)x2 - x1 + 1, (ll)y2 - y1 + 1, (ll)z2 - z1 + 1});
    for (int k = x1; k < x2; ++k)
        cost = min(cost, calc(x1, y1, z1, k, y2, z2) + calc(k + 1, y1, z1, x2, y2, z2));
    
    for (int i = y1; i < y2; ++i)
        cost = min(cost, calc(x1, y1, z1, x2, i, z2) + calc(x1, i + 1, z1, x2, y2, z2));
    
    for (int j = z1; j < z2; ++j)
        cost = min(cost, calc(x1, y1, z1, x2, y2, j) + calc(x1, y1, j + 1, x2, y2, z2));
    
    return mp[cur] = cost;
}

void solve() {
    cin >> x >> y >> z;
    for (int k = 1; k <= x; ++k)
        for (int i = 1; i <= y; ++i)
            for (int j = 1; j <= z; ++j)
                cin >> a[k][i][j];
    
    buildPrefix();
    mp.clear();
    
    cout << calc(1, 1, 1, x, y, z) << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}