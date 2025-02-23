// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc078c17e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc078c17e"
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

const int MAXN = 2e5 + 5;
vector<vector<ll>> mat, res;
int n, m;

void multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector<vector<ll>> temp(n + 1, vector<ll>(n + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                temp[i][j] += a[i][k] * b[k][j];
    a = temp;
}

ll solve() {
    ll total = 0;
    res = mat;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(mat[i][j]) total++;
            
    for(int len = 2; len < n; len++) {
        multiply(res, mat);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                total += res[i][j];
    }
    return total;
}

int main() {
    fastio();
    docfile();
    
    cin >> n >> m;
    
    mat.resize(n + 1, vector<ll>(n + 1));
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = mat[v][u] = 1;
    }
    
    cout << solve() << ln;
    
    time();
    return 0;
}