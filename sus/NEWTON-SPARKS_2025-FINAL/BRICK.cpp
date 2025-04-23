// Author: huythedev
// Problem Link: https://www.it.ngs.edu.vn/problem/newtonspark25ck_brick
// caluht
#include <bits/stdc++.h>
using namespace std;

#define NAME "BRICK"
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

ll N, C;
const ll MOD = 1e9 + 7;

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b) {
    ll res = a - b;
    return (res % MOD + MOD) % MOD;
}

ll mul(ll a, ll b) {
    return (1LL * a * b) % MOD;
}

struct Matrix {
    ll mat[2][2];

    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
    }
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix R;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                R.mat[i][j] = add(R.mat[i][j], mul(A.mat[i][k], B.mat[k][j]));
            }
        }
    }
    return R;
}

Matrix matrix_pow(Matrix A, ll p) {
    Matrix R;
    R.mat[0][0] = R.mat[1][1] = 1;

    while (p > 0) {
        if (p & 1) {
            R = multiply(R, A);
        }
        A = multiply(A, A);
        p >>= 1;
    }
    return R;
}

signed main() {
    fastio();
    docfile();

    cin >> N >> C;

    if (C == 1) {
        if (N == 1) {
            cout << 1 << ln;
        } else {
            cout << 0 << ln;
        }
        return 0;
    }

    if (N == 1) {
        cout << C % MOD << ln;
        return 0;
    }

    ll c1 = sub(C, 1);

    Matrix M;
    M.mat[0][0] = c1;
    M.mat[0][1] = c1;
    M.mat[1][0] = 1;
    M.mat[1][1] = 0;

    Matrix M_pow = matrix_pow(M, N - 1);

    ll sum_col0 = add(M_pow.mat[0][0], M_pow.mat[1][0]);
    ll ans = mul(sum_col0, C);

    cout << ans << ln;

    time();
    return 0;
}

