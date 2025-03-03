// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6mm
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6mm"
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

const ll MOD = 1e9 + 7;
const int SIZE = 5;

vector<vector<ll>> matrix_mult(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    vector<vector<ll>> C(SIZE, vector<ll>(SIZE, 0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> matrix_pow(const vector<vector<ll>>& M, ll exp) {
    vector<vector<ll>> res(SIZE, vector<ll>(SIZE, 0));

    for (int i = 0; i < SIZE; i++) 
        res[i][i] = 1; 

    vector<vector<ll>> A = M;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = matrix_mult(res, A);
        }

        A = matrix_mult(A, A);
        exp /= 2;
    }

    return res;
}

vector<ll> mult(const vector<vector<ll>>& M, const vector<ll>& V) {
    vector<ll> res(SIZE, 0);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            res[i] = (res[i] + M[i][j] * V[j]) % MOD;
        }
    }

    return res;
}

int main() {
    fastio();
    docfile();

    ll a, b, n; cin >> a >> b >> n;

    if (n == 1) {
        cout << (b % MOD) << ln;
    } 
    else {
        ll f2 = (b % MOD + (2 * (a % MOD)) % MOD + 12) % MOD;
        vector<ll> V = {f2, b % MOD, 4, 2, 1};

        vector<vector<ll>> M = {
            {1, 2, 3, 6, 3}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 1, 2, 1}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 0, 1}  
        };

        vector<vector<ll>> vec = matrix_pow(M, n - 2);
        vector<ll> res = mult(vec, V);

        cout << res[0] << ln; 
    }

    time();
    return 0;
}