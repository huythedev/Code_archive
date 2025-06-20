// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

bool check(vector<vector<int>> a, int n, int m, int k) {
    int max_val = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            max_val = max(max_val, a[i][j]);

    if (max_val > k + 1) 
        return false;

    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == k + 1)
                vec.emplace_back(i, j);

    if (vec.empty()) return true;

    vector<int> cnt(m, 0);
    for (auto [i, j] : vec)
        cnt[j]++;

    vector<vector<bool>> vec2(n, vector<bool>(m, false));
    for (auto [i, j] : vec)
        vec2[i][j] = true;

    for (int r = 0; r < n; r++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if ((!vec2[r][j] && cnt[j] > 0) || (vec2[r][j] && cnt[j] > 1))
                count++;
        }

        if (count <= 1) 
            return true;
    }

    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    if (n == 1) {
        int max_val = 0;
        for (int j = 0; j < m; j++)
            max_val = max(max_val, a[0][j]);

        cout << max_val - 1 << ln;
        return;
    }

    if (m == 1) {
        int max_val = 0;
        for (int i = 0; i < n; i++)
            max_val = max(max_val, a[i][0]);

        cout << max_val - 1 << ln;
        return;
    }

    int l = 0, r = 100;
    while (l < r) {
        int mid = l + (r - l) / 2;

        if (check(a, n, m, mid))
            r = mid;
        else
            l = mid + 1;
    }
    
    cout << l << ln;
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