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

ll sumcs(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll T = 2;
    while(T--) {
        ll n, k;
        cin >> n >> k;

        ll res = 0;
        for(ll i = 1; i <= n / k; ++i) 
            res += sumcs(i * k);

        cout << res << ln;
    }

    return 0;
}