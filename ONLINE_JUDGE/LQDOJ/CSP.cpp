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

    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    ll res = 0;
    for(ll i = 0; i < n - 1; ++i) {
        ll tmp = m - a[i];
        if(tmp <= 0)
            continue;
        ll t = upper_bound(a.begin() + i + 1, a.end(), tmp) - a.begin();
        res += max(0LL, t - i - 1);
    }

    cout << res;

    return 0;
}