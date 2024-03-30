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

    ll n, q;
    cin >> n >> q;

    vector<ll> dokho(n);
    vector<ll> tmp(n);

    for (ll i = 0; i < n; ++i) 
        cin >> dokho[i];

    for (ll i = 0; i < n; ++i) 
        cin >> tmp[i];

    for (ll i = 0; i < q; ++i) {
        ll res = 0, theluc;
        cin >> theluc;

        for (ll j = 0; j < n; ++j) {
            if (theluc >= dokho[j]) {
                res += dokho[j];
                theluc -= tmp[j];
            } else {
                break;
            }
        }

        cout << res << endl;
    }

    return 0;
}