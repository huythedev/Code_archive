// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/425
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
    int cnt = 0;
    for(int x1 = 1; x1 < n; ++x1) {
        for(int x2 = x1 + 1; x2 < n; ++x2) {
            for(int x3 = x2 + 1; x3 < n; ++x3) {
                int x4 = n - x1 - x2 - x3;
                if(x4 > x3) cnt++;
            }
        }
    }

    cout << cnt;

    time();
    return 0;
}