// Author: huythedev
// Problem Link: https://lqdoj.edu.vn/problem/23qnab1
#include <bits/stdc++.h>
using namespace std;

#define NAME "SQUARE"
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

bool isPerfectSquare(int n) {
    int x = sqrt(n);
    return x * x == n;
}

signed main() {
    fastio();
    docfile();

    int n, k; cin >> n >> k;
    
    int ans = 0;
    for (; k <= n; ++k) {
        if (isPerfectSquare(k)) {
            ++ans;
        }
    }
    cout << ans << ln;

    time();
    return 0;
}