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

const ll MOD = 1e9 + 7;

ll cntdiv(ll n) {
    ll res = 1;
    for(ll i = 2; i * i <= n; i++) {
        ll cnt = 0;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        res = (res * (cnt + 1)) % MOD;
    }
    if(n > 1) res = (res * 2) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll M; cin >> M;
    vector<ll> a(M);

    ll tmp = 1;
    for(ll &x : a) {
        cin >> x;
        tmp = tmp * x;
    }

    cout << cntdiv(tmp);

    return 0;
}