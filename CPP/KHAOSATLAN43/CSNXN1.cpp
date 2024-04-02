#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

int x,n,m, mod;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int powMod(int _n,int _k) {
    if (_k == 0) return 1;
    int tmp = powMod(_n,_k >> 1LL);
    tmp = tmp * tmp % m;
    if (_k & 1LL) tmp = tmp * _n % mod;
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    docfile();

    cin >> x >> n >> m;
    mod = m;

    cout << (powMod(x, n + 1) - 1 + m * m) % m * powMod(x - 1,m - 2) % m;
    return 0;
}
