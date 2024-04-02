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

    ll n, k;
    cin >> n >> k;

    vector<ll> vec(n + 1, 0), a(n);
    for (ll i = 1; i <= n; ++i) {
        ll t; cin >> t;
        a[i-1] = t;
        vec[i] = vec[i - 1] + t;
    }

    ll res = a[k];
    for (ll i = k + 1; i <= n; ++i)
        res = max(res, vec[i] - vec[i - k]);

    cout << res;

    return 0;
}