#include <bits/stdc++.h>
using namespace std;
#define NAME "NAME"
#define ln '\n'
typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME ".inp")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
}

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    docfile();

    ll a, b;
    cin >> a >> b;
    ll res = max(a, b);

    if(a < b) 
        swap(a, b);

    ll t = b;

    while (a != 0 && b != 0) {
        while(a >= b) {
            if(a - b >= b) 
                res = (res + a - b) % MOD;
            a -= b;
        }
        swap(a, b);
    }

    cout << res + t << ln;
    return 0;
}