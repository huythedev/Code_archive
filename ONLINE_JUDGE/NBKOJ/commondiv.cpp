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

    ll n;
    cin >> n;

    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    }

    ll maxgcd = 1;
    for(ll i = 0; i < n - 1; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            maxgcd = max(maxgcd, __gcd(x[i], x[j]));
        }
    }

    cout << maxgcd;

    return 0;
}