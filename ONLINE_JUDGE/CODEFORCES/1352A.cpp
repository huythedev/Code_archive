// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1352/A
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

void solve() {
    int n;
    cin >> n;
    vector<int> result;
    int factor = 1;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0) {
            result.push_back(digit * factor);
        }
        n /= 10;
        factor *= 10;
    }
    cout << result.size() << ln;
    for (int num : result) {
        cout << num << " ";
    }
    cout << ln;
}

signed main() {
    fastio();
    docfile();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    time();
    return 0;
}