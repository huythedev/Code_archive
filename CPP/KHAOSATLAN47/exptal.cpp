#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll a, b, c, d, n, m, p, q; cin >> a >> b >> c >> d >> n >> m >> p >> q;

    cout << (ll)pow(a, n) % MOD + (ll)pow(b, m) % MOD + (ll)pow(c, p) % MOD + (ll)pow(d, q) % MOD;

    return 0;
}