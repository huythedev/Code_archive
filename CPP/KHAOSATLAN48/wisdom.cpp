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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n, k; cin >> n >> k;

    ll res = 1;
    for(ll i = 2; i <= n; ++i) {
        ll tmp = i;
        for(ll j = 0; j < k; ++j)
            tmp = (tmp * tmp) % 10;

        res = (res + tmp) % 10;
    }
    
    cout << res;

    return 0;
}