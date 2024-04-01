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

ll power(ll a, ll b) {
    ll res = (ll)pow(a, b);
    cout << res << ln;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll x, n, m;
    cin >> x >> n >> m;

    ll res = 0;
    for(ll i = 0; i <= n; ++i)
        res = (res + power(x, i));
    
    cout << res;

    return 0;
}
