// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "cardscore"
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

    int n, l, r; cin >> n >> l >> r;
    l--; r--;
    
    int a[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) a[i] *= -1;
    }
    
    long long res = 1;
    for (; l <= r; ++l) res = (res * a[l]) % 10;
    
    cout << res;

    time();
    return 0;
}