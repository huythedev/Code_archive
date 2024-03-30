#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

ll luythua(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    docfile();

    ll a, n;
    cin >> a >> n;

    cout << (a + n) % MOD << ln;

    ll T = luythua(a, n);
    cout << T << ln;

    return 0;
}
