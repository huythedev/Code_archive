// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "TONGSOUOC"
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

ll cnt(ll n) {
    ll res = 0;

    for (ll i = 1; i * i <= n; ++i) {
        res += n / i;

        if (n / i != i) 
            res += i * (n / i - n / (i + 1));
    }

    return res;
}

int main() {
    fastio();
    docfile();

    ll l, r; 
    cin >> l >> r;

    cout << cnt(r) - cnt(l - 1);

    time();
    return 0;
}