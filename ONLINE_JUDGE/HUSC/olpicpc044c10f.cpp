// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc044c10f
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int r1, c1, r2, c2, v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        for (int r = r1 - 1; r < r2; ++r) {
            for (int c = c1 - 1; c < c2; ++c) {
                matrix[r][c] += v;
            }
        }
    }

    int k, l; cin >> k >> l;

    int count_positive = 0, count_positive_even = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (matrix[r][c] > 0) {
                count_positive++;
                if (matrix[r][c] % 2 == 0) {
                    count_positive_even++;
                }
            }
        }
    }

    int res = k * count_positive + l * count_positive_even;
    cout << res;

    time();
    return 0;
}