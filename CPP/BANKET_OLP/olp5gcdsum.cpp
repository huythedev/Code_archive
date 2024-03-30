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
    while (b!= 0) {
        if(a < b) 
            swap(a, b);

        ll tmp = a / b - 1;
        res = (res + a * tmp - (b * (tmp * (tmp + 1)) / 2)) % MOD;

        cout << res << ln;
        
        a -= b * tmp;
    }

    cout << res;

    return 0;
}
