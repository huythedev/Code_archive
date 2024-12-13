// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/422
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

    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int x, y; cin >> x >> y;

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int dist = 0;
        for (int j = x; j != y; j = (j + 1) % n) {
            dist += a[j];
        }
        ans = min(ans, dist);
    }
    cout << ans;

    time();
    return 0;
}