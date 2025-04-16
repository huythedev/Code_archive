// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/323
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

void solve(int n, int k, vector<int> &A, int i, int j) {
    if(i == k) {
        for(int x : A) cout << x << ' ';
        cout << ln;
        return;
    }
    for(int x = j + 1; x <= n; ++x) {
        A[i] = x;
        solve(n, k, A, i + 1, x);
    }
}

int main() {
    fastio();
    docfile();

    int n, k; cin >> n >> k;
    vector<int> A(k);
    solve(n, k, A, 0, 0);

    time();
    return 0;
}