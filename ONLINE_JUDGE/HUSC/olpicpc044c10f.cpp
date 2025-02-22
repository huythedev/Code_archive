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

const int MAXN = 1005;
ll diff[MAXN][MAXN], matrix[MAXN][MAXN], N, K, A, B;

void apply_updates() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            matrix[i][j] = diff[i][j] + matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
        }
    }
}

int main() {
    fastio();
    docfile();

    cin >> N >> K;
    while (K--) {
        int r1, c1, r2, c2, v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        diff[r1][c1] += v;
        diff[r2 + 1][c1] -= v;
        diff[r1][c2 + 1] -= v;
        diff[r2 + 1][c2 + 1] += v;
    }

    apply_updates();

    ll P = 0, E = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (matrix[i][j] > 0) {
                P++;
                if (matrix[i][j] % 2 == 0) {
                    E++;
                }
            }
        }
    }

    cin >> A >> B;
    cout << P * A + E * B << '\n';

    time();
    return 0;
}